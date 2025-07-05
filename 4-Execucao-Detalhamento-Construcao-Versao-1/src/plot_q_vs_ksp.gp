set logscale y
set style data histograms
set style fill solid border -1
set boxwidth 0.9
set xtics rotate by -45
set xtics ("Na+" 0, "Cl-" 1, "Ca2+" 2, "CO3--" 3, "SO4--" 4, "Ba2+" 5, "Sr2+" 6, "Mg2+" 7, "F-" 8, "Fe3+" 9, "OH-" 10)
plot 'q_vs_ksp.dat' using 2 title 'Q', '' using 3 title 'Ksp Corrigido'
