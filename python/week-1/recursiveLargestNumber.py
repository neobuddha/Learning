"""
    This file contains the recursive logic for finding the largest number in an Array
"""

__author__="Prabhat Singh"

def recursiveLargestNumber(Array, max, numElement):

    if numElement <= 0:
        return -1

    elif numElement == 1:
        if max > Array[0]:
            return max
        else:
            return Array[0]
    else:
            if(Array[0] > max):
                max = Array[0];
            return recursiveLargestNumber(Array[1:], max, numElement -1)
            

def main():
    Array = [1,2,3,4,5,6,7,8,9,10,1,1]
    numElements = len(Array)

    print "Array: ", Array
    
    maxValue = recursiveLargestNumber(Array, 0, numElements)
    print "Max Value: ", maxValue 

if __name__=="__main__":
    main()