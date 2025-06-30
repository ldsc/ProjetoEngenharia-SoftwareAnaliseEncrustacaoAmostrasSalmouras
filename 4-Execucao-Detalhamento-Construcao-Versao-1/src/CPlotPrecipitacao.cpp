#include "CPlotPrecipitacao.h"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iostream>

void CPlotPrecipitacao::PlotQvsKsp(const std::vector<std::string>& nomes,
                              const std::vector<double>& qs,
                              const std::vector<double>& ksps) {
    std::ofstream file("q_vs_ksp.dat");
    if (!file.is_open()) return;
    for (size_t i = 0; i < nomes.size(); ++i) {
        file << i << "\t" << qs[i] << "\t" << ksps[i] << "\n";
    }
    file.close();

    std::ofstream gnu("plot_q_vs_ksp.gp");
    gnu << "set logscale y\n";
    gnu << "set style data histograms\n";
    gnu << "set style fill solid border -1\n";
    gnu << "set boxwidth 0.9\n";
    gnu << "set xtics rotate by -45\n";
    gnu << "set xtics (";
    for (size_t i = 0; i < nomes.size(); ++i) {
        gnu << "\"" << nomes[i] << "\" " << i;
        if (i + 1 < nomes.size()) gnu << ", ";
    }
    gnu << ")\n";
    gnu << "plot 'q_vs_ksp.dat' using 2 title 'Q', '' using 3 title 'Ksp Corrigido'\n";
    gnu.close();

    std::system("gnuplot -persist plot_q_vs_ksp.gp");
}

void CPlotPrecipitacao::PlotQvsKspVsTemperatura(const std::string& nomeSal,
                                           double qFixo,
                                           const std::vector<double>& temperaturas,
                                           const std::vector<double>& ksps) {
    std::ofstream file("ksp_vs_temp.dat");
    if (!file.is_open()) return;
    for (size_t i = 0; i < temperaturas.size(); ++i) {
        file << temperaturas[i] << "\t" << ksps[i] << "\t" << qFixo << "\n";
    }
    file.close();

    std::ofstream gnu("plot_ksp_vs_temp.gp");
    gnu << "set logscale y\n";
    gnu << "set xlabel 'Temperatura (K)'\n";
    gnu << "set ylabel 'Valor (mol²/L²)'\n";
    gnu << "plot 'ksp_vs_temp.dat' using 1:2 title 'Ksp Corrigido para " << nomeSal <<" ' with lines, \\\n";
    gnu << "     '' using 1:3 title 'Q fixo' with lines\n";
    gnu.close();

    std::system("gnuplot -persist plot_ksp_vs_temp.gp");
}