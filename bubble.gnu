set title "Bubble Sort Comparison"

set xlabel "Array Size"

set ylabel "Number of Comparisons"

set grid

set key left top

plot \
"bubble.txt" using 1:2 with linespoints lw 2 title "Normal Bubble Sort",\
"bubble.txt" using 1:3 with linespoints lw 2 title "Optimized Bubble Sort"

pause -1