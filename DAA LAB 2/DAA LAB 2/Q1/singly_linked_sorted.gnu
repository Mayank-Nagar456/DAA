set terminal wxt size 1000,700

set title "Sorted Singly Linked List - Dictionary Operations"
set xlabel "Input Size (n)"
set ylabel "Growth"
set grid
set key outside

plot \
"singly_linked_sorted.txt" using 1:2 with lines title "Search O(n)", \
"singly_linked_sorted.txt" using 1:3 with lines title "Insert O(n)", \
"singly_linked_sorted.txt" using 1:4 with lines title "Delete O(n)", \
"singly_linked_sorted.txt" using 1:5 with lines title "Maximum O(n)", \
"singly_linked_sorted.txt" using 1:6 with lines title "Minimum O(1)", \
"singly_linked_sorted.txt" using 1:7 with lines title "Predecessor O(n)", \
"singly_linked_sorted.txt" using 1:8 with lines title "Successor O(n)"

pause -1