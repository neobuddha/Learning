#include <stdio.h>
#include <stdlib.h>

int fibonnaci(int n)
{
    int mem[n];
    mem[0] = 0;
    mem[1] = 1;
    
    if (n == 0 || n == 1)
    {
        return n;
    }
    
    for (int i = 2; i <= n; i ++)
    {
        mem[i] = mem[i-2] + mem[i -1];
    }

    return mem[n];
}

int main()
{
    int number = 0;
    printf("\n Enter the number for generating fibonnaci output: ");
    scanf("%d", &number);
    printf("\n Fibonnaci of %d = %d\n", number, fibonnaci(number));
}