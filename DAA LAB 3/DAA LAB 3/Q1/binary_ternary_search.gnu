# DAA Lab-03 - Question 1
# Binary Search vs Ternary Search
# Comparison using execution time

set title "Binary Search vs Ternary Search"
set xlabel "Input Size (n)"
set ylabel "Execution Time (milliseconds)"

set logscale x
set grid
set key left top

plot "result.txt" using 1:2 \
     with linespoints title "Binary Search O(log2 n)", \
     "result.txt" using 1:3 \
     with linespoints title "Ternary Search O(log3 n)"

pause -1
