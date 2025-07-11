set logscale y
set style data histograms
set style fill solid border -1
set boxwidth 0.9
set xtics rotate by -45
set xtics ("Barita(BaSO4)" 0, "Calcita(CaCO3)" 1, "Gipsita(CaSO4)" 2, "Halita(NaCl)" 3, "Magnesita(MgCO3)" 4, "Celestita(SrSO4)" 5, "Fluorita(CaF2)" 6, "Barrilha(Na2CO3)" 7)
plot 'q_vs_ksp.dat' using 2 title 'Q', '' using 3 title 'Ksp Corrigido'
