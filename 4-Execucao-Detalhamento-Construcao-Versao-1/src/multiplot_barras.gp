set terminal wxt size 1920,1080
set style data histograms
set style histogram cluster gap 1
set style fill solid border -1
set boxwidth 0.9
set logscale y
set yrange [1e-12:*]
set key outside
set multiplot layout 1,2 title 'Q vs Ksp por Salmoura'
set title 'Salmoura 1'
set xtics rotate by -45
set xtics font ',8'
plot 'salmoura_1.dat' using 2:xtic(1) title 'Q' lt rgb 'blue', \
     '' using 3 title 'Ksp' lt rgb 'red'
set title 'Salmoura 2'
set xtics rotate by -45
set xtics font ',8'
plot 'salmoura_2.dat' using 2:xtic(1) title 'Q' lt rgb 'blue', \
     '' using 3 title 'Ksp' lt rgb 'red'
unset multiplot
