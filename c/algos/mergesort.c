#include <stdio.h>

void copyArray(int *arraySrc, int *arrayDest, int lower, int upper)
{
	int index = lower;
	while (index <= upper)
	{
		arrayDest[index] = arraySrc[index];
		index++;
	}

	return;
}

void printArray (int *array, int lower, int upper)
{
	int index = lower;
	printf ("\nArray: ");

	while (index < upper)
	{
		printf(" %4d ", array[index]);
		index++;
	}

	printf ("\n");
}


void mergeSort(int array[], int lower, int upper)
{
	int mid = 0;

	if (lower < upper)
	{
		mid = (lower + upper) / 2;
	}
	else
		return;

	mergeSort(array, lower, mid);
	mergeSort(array, mid + 1, upper);
}



void merge(int array[], int lower, int mid, int upper)
{
	int tempArray[upper];

	int leftPortionCurrentIndex  	= lower;
	int rightPortionCurrentIndex 	= mid + 1;
	int tempArrayCurrentIndex 	= lower;

	while ((leftPortionCurrentIndex <= mid) && (rightPortionCurrentIndex <= upper))
	{
		if (array[leftPortionCurrentIndex] < array[rightPortionCurrentIndex]) {
			tempArray[tempArrayCurrentIndex]  =  array[leftPortionCurrentIndex];
			leftPortionCurrentIndex++;
		}
		else {
			tempArray[tempArrayCurrentIndex] = array[rightPortionCurrentIndex];
			rightPortionCurrentIndex++;
		}
		tempArrayCurrentIndex++;
	}
	
	if (leftPortionCurrentIndex > mid) {
		while (rightPortionCurrentIndex <= upper) {
			tempArray[tempArrayCurrentIndex] = array[rightPortionCurrentIndex];
			tempArrayCurrentIndex++;
			rightPortionCurrentIndex++;
		}
	}
	else {
		while (leftPortionCurrentIndex <= mid)
		{
			tempArray[tempArrayCurrentIndex] = array[leftPortionCurrentIndex];
			tempArrayCurrentIndex++;
			leftPortionCurrentIndex++;
		}
	}

	copyArray(tempArray, array, lower, upper);
}

int main()
{
	int array1[] = {1,30,21,4,5,12,8,100,54,12,43};
	int array2[] = {3,5,12,6,7,8,9,145,23,10};
	int array3[] = {1,2,3,4,5,6,7,50,45,40,30,20,10};

	printf("\n Unsorted Array: ");
	printArray(array1, 0 , 10);
	mergeSort(array1, 0, 10);
	printf("\n Sorted Array: ");
	printArray(array1, 0 , 10);
	
	printf("\n Unsorted Array: ");
	printArray(array2, 0 , 10);
	mergeSort(array2, 0, 10);
	printf("\n Sorted Array: ");
	printArray(array2, 0 , 10);

	printf("\n Unsorted Array: ");
	printArray(array3, 0 , 12);
	mergeSort(array3, 0, 12);
	printf("\n Sorted Array: ");
	printArray(array3, 0 , 12);

	return 1;
}


