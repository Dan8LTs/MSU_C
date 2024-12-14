set xrange [-10:10]
set yrange [-10:10]
plot "polygon1.txt" using 1:2 with lines lc rgb "blue" title "Polygon1", "polygon2.txt" using 1:2 with lines lc rgb "blue" title "Polygon2"
