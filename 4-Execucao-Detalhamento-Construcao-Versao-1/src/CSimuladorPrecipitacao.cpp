#include "CSimuladorPrecipitacao.h"
#include "CPlotPrecipitacao.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

void CSimuladorPrecipitacao::executar() {
    std::string arqIons;
    ListarArquivosTxt("Selecione o arquivo de ions:", arqIons);
    tabelaIons.carregarDeArquivo(arqIons);

    std::string arqSais;
    ListarArquivosTxt("Selecione o arquivo de sais:", arqSais);
    CarregarSais(arqSais);

    CMisturaSalmouras mistura;
    int num;
    std::cout << "Quantas salmouras deseja adicionar? ";
    std::cin >> num;

    for (int i = 0; i < num; ++i) {
        CSalmoura s;
        std::cout << "\n--- Salmoura " << (i + 1) << " ---" << std::endl;
        ConstruirSalmoura(s);
        mistura.adicionarSalmoura(s);
    }

    simular(mistura);
}

void CSimuladorPrecipitacao::ConstruirSalmoura(CSalmoura& s) const {
    double v, t, p;
    std::cout << "Volume (L): ";
    std::cin >> v;
    std::cout << "Temperatura (K): ";
    std::cin >> t;
    std::cout << "Pressao (atm): ";
    std::cin >> p;
    s.setVolume(v);
    s.DefinirCondicoes(t, p);

    std::string arqSalmoura;
    ListarArquivosTxt("Selecione o arquivo de ions da salmoura:", arqSalmoura);
    std::ifstream arq("./dados/" + arqSalmoura);
    if (!arq.is_open()) {
        std::cerr << "Erro ao abrir " << arqSalmoura << std::endl;
        return;
    }

    std::string linha;
    while (std::getline(arq, linha)) {
        if (linha.empty() || linha[0] == '#') continue;
        std::istringstream iss(linha);
        std::string nomeIon;
        double mols;
        if (iss >> nomeIon >> mols) {
            s.adicionarIon(nomeIon, mols);
        }
    }
}

void CSimuladorPrecipitacao::CarregarSais(const std::string& caminhoArquivo) {
    std::ifstream arq("./dados/" + caminhoArquivo);
    if (!arq.is_open()) return;

    std::string linha;
    while (std::getline(arq, linha)) {
        if (linha.empty() || linha[0] == '#') continue;
        std::istringstream iss(linha);
        std::string nome, ion1str, ion2str;
        double kspRef, deltaH, tempRef;
        iss >> nome >> kspRef >> deltaH >> tempRef >> ion1str >> ion2str;

        std::vector<CIon> ions;
        std::vector<int> coefs;
        for (const std::string& entrada : {ion1str, ion2str}) {
            size_t sep = entrada.find(":");
            if (sep == std::string::npos) continue;
            std::string nomeIon = entrada.substr(0, sep);
            int coef = std::stoi(entrada.substr(sep + 1));
            ions.push_back(tabelaIons.obterIon(nomeIon));
            coefs.push_back(coef);
        }
        saisDisponiveis.emplace_back(nome, kspRef, deltaH, tempRef, ions, coefs);
    }
}

void CSimuladorPrecipitacao::ListarArquivosTxt(const std::string& titulo, std::string& selecionado) const {
    std::vector<std::string> arquivos;
    std::cout << "\n" << titulo << std::endl;
    int index = 1;
    for (const auto& entry : fs::directory_iterator("./dados/")) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            std::cout << "[" << index << "] " << entry.path().filename().string() << std::endl;
            arquivos.push_back(entry.path().filename().string());
            ++index;
        }
    }
    if (arquivos.empty()) {
        std::cerr << "Nenhum arquivo .txt encontrado." << std::endl;
        exit(1);
    }
    int escolha = 0;
    do {
        std::cout << "Digite o numero do arquivo desejado: ";
        std::cin >> escolha;
    } while (escolha < 1 || escolha > static_cast<int>(arquivos.size()));

    selecionado = arquivos[escolha - 1];
}

void CSimuladorPrecipitacao::simular(const CMisturaSalmouras& mistura) {
    auto concentracoes = mistura.calcularConcentracoesFinais();
    double somaTemperatura = 0.0;
    double somaVolume = 0.0;
    for (const auto& s : mistura.getSalmouras()) {
        somaTemperatura += s.getTemperatura() * s.getVolume();
        somaVolume += s.getVolume();
    }
    double temperaturaMedia = somaVolume > 0 ? somaTemperatura / somaVolume : 298.15;

    std::vector<std::string> nomes;
    std::vector<double> qs;
    std::vector<double> ksps;

    std::cout << "\n==== Resultados ====" << std::endl;
    for (const auto& sal : saisDisponiveis) {
        double Q = sal.calculateIonicProduct(concentracoes);
        double K = sal.KspCorrigido(temperaturaMedia);
        nomes.push_back(sal.getName());
        qs.push_back(Q);
        ksps.push_back(K);

        std::cout << "Sal: " << sal.getName()
                  << " | Q = " << Q
                  << " | Ksp_corrigido = " << K
                  << " | T(K) = " << temperaturaMedia << std::endl;

        if (Q > K) {
            std::cout << "  " << sal.getName() << " - PRECIPITA" << std::endl;
        } else {
            std::cout << "  " << sal.getName() << " - estavel" << std::endl;
        }
    }

    CPlotPrecipitacao plot;
    plot.PlotQvsKsp(nomes, qs, ksps);

    std::cout << "\nDigite o indice do sal para visualizar Q x Ksp(T): ";
    int escolha = 0;
    std::cin >> escolha;
    if (escolha >= 0 && escolha < static_cast<int>(saisDisponiveis.size())) {
        const auto& salSelecionado = saisDisponiveis[escolha];
        double Qfixo = salSelecionado.calculateIonicProduct(concentracoes);
        std::vector<double> temps, kspsT;
        for (double T = temperaturaMedia - 20; T <= temperaturaMedia + 20; T += 1.0) {
            temps.push_back(T);
            kspsT.push_back(salSelecionado.KspCorrigido(T));
        }
        plot.PlotQvsKspVsTemperatura(salSelecionado.getName(), Qfixo, temps, kspsT);
    }
}

