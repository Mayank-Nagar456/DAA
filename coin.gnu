set title "Fair Coin vs Biased Coin Simulation"

set xlabel "Number of Tosses"

set ylabel "Probability of Head"

set grid

set key left top

set xrange [0:100000]

set yrange [0:1]

plot \
"coin.txt" using 1:2 with linespoints lw 2 title "Fair Coin", \
"coin.txt" using 1:3 with linespoints lw 2 title "Biased Coin", \
0.5 with lines title "P=0.5", \
0.8 with lines title "P=0.8"

pause -1