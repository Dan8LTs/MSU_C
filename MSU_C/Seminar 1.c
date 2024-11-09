#include <stdio.h>
#include <string.h>

void main()
{
    char ans[1000000] = "";
    int n;
    scanf_s("%d", &n);
    int i = 0;
    while (n)
    {
        ans[i] = n % 2 + '0';
        i++;
        n /= 2;
    }
    
    printf("%s", _strrev(ans));
}