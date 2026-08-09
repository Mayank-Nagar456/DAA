set terminal wxt size 1000,700

set title "Unsorted Array - Dictionary Operations"
set xlabel "Input Size (n)"
set ylabel "Growth"
set grid
set key outside

plot \
"unsorted_array.txt" using 1:2 with lines title "Search O(n)", \
"unsorted_array.txt" using 1:3 with lines title "Insert O(1)", \
"unsorted_array.txt" using 1:4 with lines title "Delete O(n)", \
"unsorted_array.txt" using 1:5 with lines title "Maximum O(n)", \
"unsorted_array.txt" using 1:6 with lines title "Minimum O(n)", \
"unsorted_array.txt" using 1:7 with lines title "Predecessor O(n)", \
"unsorted_array.txt" using 1:8 with lines title "Successor O(n)"

pause -1