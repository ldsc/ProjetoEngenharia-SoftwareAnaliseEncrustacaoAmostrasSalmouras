#ifndef CGNUPLOTPLOT_H
#define CGNUPLOTPLOT_H

#include <string>
#include <vector>

class CPlotPrecipitacao {
public:
    void PlotQvsKsp(const std::vector<std::string>& nomes,
                    const std::vector<double>& qs,
                    const std::vector<double>& ksps);

    void PlotQvsKspVsTemperatura(const std::string& nomeSal,
                                 double qFixo,
                                 const std::vector<double>& temperaturas,
                                 const std::vector<double>& ksps);
};

#endif