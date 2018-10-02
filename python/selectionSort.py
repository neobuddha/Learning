"""
This file has code for selection sort.
"""
__auther__="Prabhat Singh"

def selectionSort(array):
    length = len(array)

    index = 0

    for index in range(length):
        innerLoopIndex = index
        minimumValueIndex = index
        for innerLoopIndex in range (index, length):
            if array[minimumValueIndex] > array[innerLoopIndex]:
                minimumValueIndex = innerLoopIndex
        
        array[index], array[minimumValueIndex] = array[minimumValueIndex], array[index]

def main():
    array = [5,4,2,3,1]

    print("Unsorted Array:", array)
    selectionSort(array)
    print("Unsorted Array:", array)

if __name__=="__main__":
    main()