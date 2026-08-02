set title "Tower of Hanoi"

set xlabel "Number of Discs"

set ylabel "Number of Moves"

set grid

set key off

plot "toh.txt" using 1:2 with linespoints lw 2

pause -1