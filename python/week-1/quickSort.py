"""
This file contains code for quicksort.
"""

__author__="Prabhat Singh"

def partition(array, low, high):
    
    lowerIndex = low -  1
    pivot = array[high]

    for highIndex in range( low, high):
        if(array[highIndex] <= pivot):
            lowerIndex = lowerIndex + 1
            array[lowerIndex], array[highIndex] = array[highIndex], array[lowerIndex]
    
    lowerIndex = lowerIndex + 1
    array[lowerIndex], array[high] = array[high], array[lowerIndex]

    return lowerIndex

def quickSort(array, low, high):
    if low >= high:
        return
    else:
        pivot = partition(array, low, high)
        quickSort(array, low, pivot - 1)
        quickSort(array, pivot + 1, high)

def main():
    array = [12,3,21,5,22,333,-1,-4,30]
    print "Unsorted Array: ", array
    quickSort(array, 0, 8)
    print "Sorted Array: ", array

if __name__=="__main__":
    main()
