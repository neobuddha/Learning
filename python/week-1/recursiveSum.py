"""
This file has code for a recursive sum program
"""

__author__="Prabhat Singh"

def recursiveSum(Array, NumElements):
    sum = 0

    if NumElements == 0:
        return 0;
    else:
        return Array[0] + recursiveSum(Array[1:], NumElements -1)

def main():
    array = [1,2,3,4,5,6,7,8]

    print("Array: ", array)

    numElements = len(array)

    sum = recursiveSum(array, numElements)
    print("Sum of Array", sum)


if __name__=="__main__":
    main()
