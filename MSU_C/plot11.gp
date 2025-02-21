set xlabel "X"
set ylabel "Y"

set xrange [-4:4]
set yrange [-3:3]

f1(x) = x**2 - 2
f2(x) = sin(x)
f3(x) = 0

plot f1(x) title "y = x^2 - 2" with lines lw 2, f2(x) title "y = sin(x)" with lines lw 2, f3(x) title "" with lines lw 2