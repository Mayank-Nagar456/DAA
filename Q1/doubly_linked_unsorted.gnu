set terminal wxt size 1000,700

set title "Doubly Linked List (Unsorted) - Dictionary Operations"
set xlabel "Input Size (n)"
set ylabel "Growth"
set grid
set key outside

plot \
"doubly_linked_unsorted.txt" using 1:2 with lines title "Search O(n)", \
"doubly_linked_unsorted.txt" using 1:3 with lines title "Insert O(1)", \
"doubly_linked_unsorted.txt" using 1:4 with lines title "Delete O(n)", \
"doubly_linked_unsorted.txt" using 1:5 with lines title "Maximum O(n)", \
"doubly_linked_unsorted.txt" using 1:6 with lines title "Minimum O(n)", \
"doubly_linked_unsorted.txt" using 1:7 with lines title "Predecessor O(n)", \
"doubly_linked_unsorted.txt" using 1:8 with lines title "Successor O(n)"

pause -1