#include <stdio.h>

int main2()
{
    double s, a;
    int n;
    FILE* fin = fopen("input.txt", "r");
    if (!fin) {
        fprintf(stderr, "Cannot open file\n");
        return -1;
    }

    s = n = 0;
    while (fscanf_s(fin, "%lf", &a) == 1) {
        s += a;
        n++;
    }

    if (n == 0) {
        fprintf(stderr, "Division by zero\n");
        return -1;
    }
    fprintf(stdout, "Mean value is %f", s / n);
}