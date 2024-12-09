set grid
set style line 1 lc rgb 'blue' lw 2
set style line 2 lc rgb 'red' pt 7 ps 1.5
set xrange [-10:10]
set yrange [-10:10]

plot 'polygon1.txt' using 1:2 with lines linestyle 1 title 'Polygons', 
'polygon2.txt' using 1:2 with lines linestyle 1 title 'Polygons', 