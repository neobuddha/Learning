#include <stdio.h>
#include <stdlib.h>
#include "../inc/common.h"

int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int lower = low -1;
    int upper;

    for (upper = low; upper < high; upper++)
    {
        if(array[upper] <= pivot)
        {
            swap(&array[++lower], &array[upper]);       
        }       
    }

    swap(&array[++lower], &array[high]);

    return lower;
    
}

void quickSort(int array[], int low, int high)
{
    int pivot = 0;

    /* If the array contains o or 1 elements, no need for doing any further sorting*/
    if(high - low < 2)
    {
        return;
    }

    pivot = partition(array, low, high);
    quickSort(array,low, pivot -1);
    quickSort(array, pivot+1, high);
}

int main()
{
    int array1[] = {1,4,5,15,6,3,18};
    printArray(array1,7);
    quickSort(array1, 0, 6);
    printArray(array1,7);

    int array2[] = {11};
    printArray(array2, 1);
    quickSort(array2, 0,0);
    printArray(array2, 1);

    int array3[] = {50,60,70,80,90,100,110,120};
    printArray(array3, 8);
    quickSort(array3, 0, 7);
    printArray(array3, 8);

    int array4[] = {100,90,85,75,65,55,44,35,25,15,5};
    printArray(array4, 11);
    quickSort(array4, 0, 10);
    printArray(array4, 11);

    int array5[] = {86,22,110,34,2,75,1,88,87,43,20};
    printArray(array5, 11);
    quickSort(array5, 0, 10);
    printArray(array5, 11);
  
    return 0;
}
