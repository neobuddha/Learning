#include <stdio.h>
#include <stdlib.h>

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
void selectionSort(int array[], int numOfElem)
{
    int index = 0;
    int innerLoopIndex = 0;
    int smallestElem = 0;
    int smallestArrayIndex = 0;

    for (index = 0; index < numOfElem; index++)
    {
        int smallestElemIndex = index;
        for(innerLoopIndex = index + 1; innerLoopIndex < numOfElem; innerLoopIndex++)
        {
            if (array[smallestElemIndex] > array[innerLoopIndex])
            {
                smallestElemIndex = innerLoopIndex;
            }
        }

        swap(&array[index], &array[smallestElemIndex]);
    }
}

int main()
{
    int array1[] = {1,4,5,15,6,3,18};
    printArray(array1,7);
    selectionSort(array1, 7);
    printArray(array1,7);

    int array2[] = {11};
    printArray(array2,1);
    selectionSort(array2,1);
    printArray(array2,1);

    int array3[] = {50,60,70,80,90,100,110,120};
    printArray(array3,8);
    selectionSort(array3,8);
    printArray(array3,8);

    int array4[] = {100,90,85,75,65,55,44,35,25,15,5};
    printArray(array4,11);
    selectionSort(array4,11);
    printArray(array4,11);

    int array5[] = {86,22,110,34,2,75,1,88,87,43,20};
    printArray(array5,11);
    selectionSort(array5,11);
    printArray(array5,11);
  
    return 0;
}
