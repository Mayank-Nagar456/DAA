set terminal wxt size 1000,700

set title "Sorted Array - Dictionary Operations"

set xlabel "Input Size (n)"
set ylabel "Growth"

set grid
set key outside

plot \
"sorted_array.txt" using 1:2 with lines title "Search O(log n)", \
"sorted_array.txt" using 1:3 with lines title "Insert O(n)", \
"sorted_array.txt" using 1:4 with lines title "Delete O(n)", \
"sorted_array.txt" using 1:5 with lines title "Maximum O(1)", \
"sorted_array.txt" using 1:6 with lines title "Minimum O(1)", \
"sorted_array.txt" using 1:7 with lines title "Predecessor O(log n)", \
"sorted_array.txt" using 1:8 with lines title "Successor O(log n)"

pause -1