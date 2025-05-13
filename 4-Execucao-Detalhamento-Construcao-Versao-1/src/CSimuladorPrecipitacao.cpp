#include "CSimuladorPrecipitacao.h"
#include <iostream>
#include <cmath>

void CSimuladorPrecipitacao::executar() {
    // Cria duas salmouras de teste
    CSalmoura s1 = criarSalmouraTeste1();
    CSalmoura s2 = criarSalmouraTeste2();

    // Mistura as salmouras
    CMisturaSalmouras mistura;
    mistura.adicionarSalmoura(s1);
    mistura.adicionarSalmoura(s2);

    // Calcula concentrações finais
    auto concentracoes = mistura.calcularConcentracoesFinais();

    std::cout << "Concentracoes finais (mol/L):\n";
    for (const auto& [nome, conc] : concentracoes) {
        std::cout << " - " << nome << ": " << conc << "\n";
    }

    // Testa precipitação para cada sal
    std::cout << "\nAnálise de precipitação:\n";
    for (const auto& sal : mistura.getTodosSais()) {
        double Q = sal.calculateIonicProduct(concentracoes);
        std::cout << "Sal: " << sal.getName()
                  << " | Q = " << Q << " | Ksp = " << sal.getKsp();
        if (sal.willPrecipitate(concentracoes)) {
            std::cout << "  → Precipita!\n";
        } else {
            std::cout << "  → Estável.\n";
        }
    }
}

CSalmoura CSimuladorPrecipitacao::criarSalmouraTeste1() const {
    CTabelaPropriedadesIons tabela;
    tabela.carregarDeArquivo("dados_ions.txt");

    CSalmoura salmoura(1.0);
    salmoura.adicionarIon("Na", 0.1);
    salmoura.adicionarIon("Cl", 0.1);

    CIon na = tabela.obterIon("Na");
    CIon cl = tabela.obterIon("Cl");
    CSalt halita("Halita", 36.0, {na, cl}, {1, 1});

    salmoura.adicionarSal(halita);
    return salmoura;
}

CSalmoura CSimuladorPrecipitacao::criarSalmouraTeste2() const {
    CTabelaPropriedadesIons tabela;
    tabela.carregarDeArquivo("dados_ions.txt");

    CSalmoura salmoura(1.0);
    salmoura.adicionarIon("Ba", 0.005);
    salmoura.adicionarIon("SO4", 0.005);

    CIon ba = tabela.obterIon("Ba");
    CIon so4 = tabela.obterIon("SO4");
    CSalt barita("Barita", 1.08e-10, {ba, so4}, {1, 1});

    salmoura.adicionarSal(barita);
    return salmoura;
}