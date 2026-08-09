set terminal wxt size 1000,700

set title "Merge Sort vs Modified Merge Sort"

set xlabel "Input Size (n)"
set ylabel "Growth"

set grid
set key outside

plot \
"merge_sort.txt" using 1:2 with lines title "Merge Sort O(n log2 n)", \
"merge_sort.txt" using 1:3 with lines title "Modified Merge Sort O(n log3 n)"

pause -1