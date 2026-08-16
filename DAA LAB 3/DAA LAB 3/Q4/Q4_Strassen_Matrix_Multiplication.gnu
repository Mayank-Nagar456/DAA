# DAA Lab-03 - Question 4
# Matrix Multiplication using Strassen's Method

set title "Strassen Matrix Multiplication"
set xlabel "Matrix Size (n)"
set ylabel "Execution Time (milliseconds)"

set logscale x
set grid

set key left top

plot "result.txt" using 1:2 \
     with linespoints title "Strassen"

pause -1
