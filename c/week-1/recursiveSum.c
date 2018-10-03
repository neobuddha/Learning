#include <stdio.h>
#include <stdlib.h>
#include "../inc/common.h"

int recursiveSum(int Array[], int numOfElements)
{
    if(numOfElements==0)
        return 0;
    else
        return Array[0] + recursiveSum(Array+1, numOfElements -1);
}

int main()
{
    int array[] = {1,2,3,4,5,6,7,8};
    printArray(array, 8);
    int sum = recursiveSum(array,8);
    printf("\n Array Sum: %3d\n", sum);
    return 0;
}