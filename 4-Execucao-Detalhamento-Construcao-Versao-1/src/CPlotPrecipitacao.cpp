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
    gnu << config.getTerminalSetting();
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
    gnu << config.getTerminalSetting();
    gnu << "set logscale y\n";
    gnu << "set xlabel 'Temperatura (K)'\n";
    gnu << "set ylabel 'Valor (mol^2/L^2)'\n";
    gnu << "plot 'ksp_vs_temp.dat' using 1:2 title 'Ksp Corrigido para " << nomeSal <<" ' with lines, \\\n";
    gnu << "     '' using 1:3 title 'Q fixo' with lines\n";
    gnu.close();

    std::system("gnuplot -persist plot_ksp_vs_temp.gp");
}

void CPlotPrecipitacao::MultiplotQvsKspVsTemperatura(
    const std::vector<std::string>& nomesSalmouras,
    const std::vector<std::vector<std::string>>& nomesSais,
    const std::vector<std::vector<double>>& todosQs,
    const std::vector<std::vector<double>>& todosKsps)
{
    std::vector<std::string> arquivosGerados;
    for (size_t i = 0; i < nomesSalmouras.size(); ++i) {
        std::string nomeArquivo = "salmoura_" + std::to_string(i + 1) + ".dat";
        arquivosGerados.push_back(nomeArquivo);
        std::ofstream dat(nomeArquivo);
        for (size_t j = 0; j < nomesSais[i].size(); ++j) {
            dat << nomesSais[i][j] << " " << todosQs[i][j] << " " << todosKsps[i][j] << "\n";
        }
        dat.close();
    }

    std::ofstream gp("multiplot_barras.gp");
    gp << config.getTerminalSetting();
    gp << "set style data histograms\n";
    gp << "set style histogram cluster gap 1\n";
    gp << "set style fill solid border -1\n";
    gp << "set boxwidth 0.9\n";
    gp << "set logscale y\n";
    gp << "set yrange [1e-12:*]\n";
    gp << "set key outside\n";
    gp << "set multiplot layout 1," << nomesSalmouras.size() << " title 'Q vs Ksp por Salmoura'\n";

    for (size_t i = 0; i < nomesSalmouras.size(); ++i) {
        gp << "set title '" << nomesSalmouras[i] << "'\n";
        gp << "set xtics rotate by -45\n";
        gp << "set xtics font ',8'\n";
        gp << "plot '" << arquivosGerados[i] << "' using 2:xtic(1) title 'Q' lt rgb 'blue', \\\n";
        gp << "     '' using 3 title 'Ksp' lt rgb 'red'\n";
    }

    gp << "unset multiplot\n";
    gp.close();

    system("gnuplot -persist multiplot_barras.gp");
}
