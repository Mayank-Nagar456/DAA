# DAA Lab-03 - Question 2
# Search the Defective Coin
# Divide and Conquer

set title "Defective Coin: Number of Balance Weighings"
set xlabel "Number of Coins (n)"
set ylabel "Number of Weighings"

set logscale x
set grid
set key left top

plot "result.txt" using 1:2 \
     with linespoints title "Divide and Conquer O(log2 n)"

pause -1
