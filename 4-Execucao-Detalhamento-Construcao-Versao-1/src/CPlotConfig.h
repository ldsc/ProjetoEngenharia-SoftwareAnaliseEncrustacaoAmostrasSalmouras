#ifndef CPLOTCONFIG_H
#define CPLOTCONFIG_H

#include <string>

enum class QualidadePlot {
    Alta,     // 1920x1080
    Media,    // 1280x720
    Baixa     // 800x600
};

class CPlotConfig {
private:
    QualidadePlot qualidade;

public:
    CPlotConfig(QualidadePlot q = QualidadePlot::Alta) : qualidade(q) {}

    std::string getTerminalSetting() const {
        switch (qualidade) {
            case QualidadePlot::Alta:
                return "set terminal wxt size 1920,1080\n";
            case QualidadePlot::Media:
                return "set terminal wxt size 1280,720\n";
            case QualidadePlot::Baixa:
                return "set terminal wxt size 800,600\n";
            default:
                return "set terminal wxt size 1280,720\n";
        }
    }
};

#endif