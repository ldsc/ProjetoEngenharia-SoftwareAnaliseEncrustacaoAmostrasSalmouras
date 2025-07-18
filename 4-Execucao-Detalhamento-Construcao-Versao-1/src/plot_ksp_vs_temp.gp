set logscale y
set xlabel 'Temperatura (K)'
set ylabel 'Valor (mol²/L²)'
plot 'ksp_vs_temp.dat' using 1:2 title 'Ksp Corrigido para Calcita(CaCO3) ' with lines, \
     '' using 1:3 title 'Q fixo' with lines
