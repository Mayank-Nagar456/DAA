# DAA Lab-03 - Question 3
# Maximum and Minimum using Divide and Conquer

set title "Maximum and Minimum: Divide and Conquer"
set xlabel "Input Size (n)"
set ylabel "Number of Comparisons"

set grid
set key left top

plot "result.txt" using 1:2 \
     with linespoints title "Actual Comparisons n", \
     "result.txt" using 1:3 \
     with linespoints title "3n/2 Bound"

pause -1
