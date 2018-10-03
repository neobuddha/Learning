"""
    This file contains the recursive version on Binary Search
"""

__author__="Prabhat Singh"

def recursiveBinarySearch(Array, low, high, value):
    mid = (low + high)/2

    if low < high:
        if Array[mid] == value:
            return 1
        elif Array[mid] > value:
            return recursiveBinarySearch(Array, low, mid -1, value)
        else:
            return recursiveBinarySearch(Array, mid+1, high, value)

def main():
    Array = [1,2,3,4,5,6,7,8,9,10,11,12]
    value = 18

    low = 0
    high = len(Array)

    print "Array: ", Array
    
    if recursiveBinarySearch(Array, low, high, value):
        print "Found: ", value 
    else:
        print "Not found: ", value

if __name__=="__main__":
    main()