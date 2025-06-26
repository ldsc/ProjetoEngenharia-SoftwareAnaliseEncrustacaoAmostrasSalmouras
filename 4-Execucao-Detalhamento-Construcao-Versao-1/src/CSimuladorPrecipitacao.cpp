#include "CSimuladorPrecipitacao.h"
#include "CTabelaPropriedadesIons.h"
#include <iostream>
#include <limits>

void CSimuladorPrecipitacao::executar() {
    CTabelaPropriedadesIons tabela;
    tabela.carregarDeArquivo("dados_ions.txt");

    int opcao = 0;
    do {
        std::cout << "\n==== Simulador de Precipitacao Quimica ====" << std::endl;
        std::cout << "1. Definir condicoes termodinamicas" << std::endl;
        std::cout << "2. Executar simulacao" << std::endl;
        std::cout << "3. (Futuro) Gerar grafico de concentracoes" << std::endl;
        std::cout << "4. Sair" << std::endl;
        std::cout << "Escolha: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1: {
                double p, t;
                std::cout << "Informe a pressao (atm): ";
                std::cin >> p;
                std::cout << "Informe a temperatura (Celsius): ";
                std::cin >> t;
                condicoes.setPressure(p);
                condicoes.setTemperature(t);
                break;
            }
            case 2: {
                int numSalmouras;
                CMisturaSalmouras mistura; // colocar como membro da classe.
                std::cout << "Quantas salmouras deseja criar? ";
                std::cin >> numSalmouras;
                for (int i = 0; i < numSalmouras; ++i) {
                    CSalmoura s;
                    double volume;// a entrada de dados da classe salmoura deveria ser feita na classe salmoura, algo como salmoura.EntradaDados();
                    std::cout << "\nSalmoura " << (i + 1) << ": volume (L): ";
                    std::cin >> volume;
                    s.setVolume(volume);

                    int numIons;
                    std::cout << "Quantos ions deseja adicionar? ";
                    std::cin >> numIons;
                    for (int j = 0; j < numIons; ++j) {
                        std::string nomeIon;
                        double mols;
                        std::cout << "  Nome do ion " << (j + 1) << ": ";//informar unidades
                        std::cin >> nomeIon;
                        std::cout << "  Mols: ";
                        std::cin >> mols;
                        s.adicionarIon(nomeIon, mols);
                    }
                    mistura.adicionarSalmoura(s);
                }

                int numSais;
                std::vector<CSalt> sais; // colocar na classe; atributo da classe
                std::cout << "\nQuantos sais deseja criar? ";
                std::cin >> numSais;
                for (int i = 0; i < numSais; ++i) {
                    std::string nome;
                    double ksp;
                    int numIons;
                    std::cout << "\nNome do sal: ";
                    std::cin >> nome;
                    std::cout << "Ksp: ";
                    std::cin >> ksp;
                    std::cout << "Numero de ions: ";
                    std::cin >> numIons;
                    std::vector<CIon> ions;
                    std::vector<int> coefs;
                    for (int j = 0; j < numIons; ++j) {
                        std::string nomeIon;
                        int coef;
                        std::cout << "  Nome do ion " << (j + 1) << ": ";
                        std::cin >> nomeIon;
                        CIon ion = tabela.obterIon(nomeIon);
                        std::cout << "  Coeficiente: ";
                        std::cin >> coef;
                        ions.push_back(ion);
                        coefs.push_back(coef);
                    }
                    sais.emplace_back(nome, ksp, ions, coefs);
                }

                simular(mistura, sais);
                break;
            }
            case 3:
                std::cout << "[INFO] Funcionalidade de grafico ainda nao implementada." << std::endl;
                break;
            case 4:
                std::cout << "Encerrando..." << std::endl;
                break;
            default:
                std::cout << "Opcao invalida." << std::endl;
        }
    } while (opcao != 4);
}

void CSimuladorPrecipitacao::simular(const CMisturaSalmouras& mistura, const std::vector<CSalt>& sais) {
    auto concentracoes = mistura.calcularConcentracoesFinais();
    for (const auto& sal : sais) {
        double Q = sal.calculateIonicProduct(concentracoes);
        std::cout << "Sal: " << sal.getName() << " → Q = " << Q;
        if (sal.willPrecipitate(concentracoes)) {
            std::cout << " → [PRECIPITA]" << std::endl;
        } else {
            std::cout << " → [estavel]" << std::endl;
        }
    }
}
