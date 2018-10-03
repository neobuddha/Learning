def binarySearch(numbers, low, high, value):
    
    '''print (numbers, low, high, value)'''
    
    if low < high:    
        mid = int ((low + high ) / 2)
        
        guess = numbers[ mid ]
        
        if guess == value:
            print ("Found value: ", value)
            return mid
            
        if guess < value:
            binarySearch (numbers, mid+1, high, value)
            
        if guess > value:
             binarySearch (numbers, low, mid -1, value)

def main():
    numbers = [ 1, 3, 4, 5, 12, 15, 13, 16, 18 ]

    high = int(len(numbers))

    binarySearch(numbers, 0, high -1, 16);


if __name__ == "__main__":
    main()
