"""
    Code for finding a Celebrity.
"""

__author__ = "Prabhat Singh"

NUM_PERSON = 8

# Relationship matrix
MATRIX = [
                [0, 1, 1, 0, 1, 0, 0, 0],
                [0, 0, 1, 1, 1, 0, 0, 0],
                [0, 0, 0, 0, 1, 0, 0, 0],
                [0, 0, 1, 0, 1, 0, 0, 0],
                [0, 0, 0, 0, 0, 0, 0, 0],
                [0, 0, 1, 0, 1, 0, 0, 0],
                [0, 0, 1, 0, 1, 0, 0, 0],
                [0, 0, 1, 0, 1, 0, 0, 0]
            ]


def knows(MATRIX, A, B):
    return (MATRIX[A][B])


def findCelebrity(numOfPerson):
     person1 = 0
     person2 = numOfPerson-1
     while person1 < person2:
        removePerson1 = 0
        removePerson2 = 0

        print ("Person1: ", person1, "Person2: ", person2)
        if knows(MATRIX,person1, person2):
            removePerson1 = 1
        else:
            removePerson2 = 1

        if knows(MATRIX,person2, person1):
            removePerson2 = 1
        else:
            removePerson1 = 1

        if removePerson1:
            person1 = person1 + 1
        if removePerson2:
            person2 = person2 - 1

     for index in range(NUM_PERSON):
        if(knows(MATRIX,person1,index)):
            return -1
     return person1

def main():
    print("Celebrity: ", findCelebrity(NUM_PERSON))

if  __name__=="__main__":
    main()
