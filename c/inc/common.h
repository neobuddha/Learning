#include <stdio.h>

void swap (int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void printArray(int array[], int numElement)
{
    printf ("\n Array: ");
    
    for (int index = 0; index < numElement; index++)
    {
        printf (" %3d ", array[index]);
    }

    printf("\n");
}
