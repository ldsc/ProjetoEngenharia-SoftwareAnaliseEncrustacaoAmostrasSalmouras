#ifndef CGNUPLOTPLOT_H
#define CGNUPLOTPLOT_H

#include "CPlotConfig.h"

#include <string>
#include <vector>

class CPlotPrecipitacao {
    public:

        CPlotPrecipitacao(QualidadePlot q = QualidadePlot::Alta) : config(q) {}

        void PlotQvsKsp(const std::vector<std::string>& nomes,
                        const std::vector<double>& qs,
                        const std::vector<double>& ksps);

        void PlotQvsKspVsTemperatura(const std::string& nomeSal,
                                    double qFixo,
                                    const std::vector<double>& temperaturas,
                                    const std::vector<double>& ksps);
        
        void MultiplotQvsKspVsTemperatura(const std::vector<std::string>& nomesSalmouras,
                                        const std::vector<std::vector<std::string>>& nomesSaisPorSalmoura,
                                        const std::vector<std::vector<double>>& todosQs,
                                        const std::vector<std::vector<double>>& todosKsps);

    private:
        CPlotConfig config;
};

#endif