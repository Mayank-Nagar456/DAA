set title "Growth of Functions"

set xlabel "n"

set ylabel "Function Value"

set grid

set key outside

set logscale y

plot \
"growth.txt" using 1:2 with lines lw 2 title "nlog2n",\
"growth.txt" using 1:3 with lines lw 2 title "12sqrt(n)",\
"growth.txt" using 1:4 with lines lw 2 title "1/n",\
"growth.txt" using 1:5 with lines lw 2 title "n^(log2n)",\
"growth.txt" using 1:6 with lines lw 2 title "100n^2+6n",\
"growth.txt" using 1:7 with lines lw 2 title "n^0.51",\
"growth.txt" using 1:8 with lines lw 2 title "n^2-324",\
"growth.txt" using 1:9 with lines lw 2 title "50n^0.5",\
"growth.txt" using 1:10 with lines lw 2 title "2n^3",\
"growth.txt" using 1:11 with lines lw 2 title "3^n",\
"growth.txt" using 1:12 with lines lw 2 title "2^32*n",\
"growth.txt" using 1:13 with lines lw 2 title "log2n"

pause -1