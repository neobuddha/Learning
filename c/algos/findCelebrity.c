#include <stdio.h>
#include <stdlib.h>

#define NUM_PERSON   8
int MATRIX [NUM_PERSON][NUM_PERSON] = {
                                        {0,1,1,0,1,0,0,0},
                                        {0,0,1,1,1,0,0,0},
                                        {0,0,0,0,1,0,0,0},
                                        {0,0,1,0,1,0,0,0},
                                        {0,0,0,0,0,0,0,0},
                                        {0,0,1,0,1,0,0,0},
                                        {0,0,1,0,1,0,0,0},
                                        {0,0,1,0,1,0,0,0},
                                    };

int knows (int A, int B)
{
    return (MATRIX[A][B]);
}

int findCelebrity(int numOfPerson)
{
    int person1 = 0;
    int person2 = numOfPerson-1;

    while (person1 < person2)
    {
        int removePerson1 = 0;
        int removePerson2 = 0;

        if(knows(person1, person2))
        {
            removePerson1 = 1;
        }
        else
        {
            removePerson2 = 1;   
        }

        if (knows(person2, person1))
        {
            removePerson2 = 1;                
        }
        else
        {
            removePerson1 = 1;
        }

        if(removePerson1)
            person1++;
        if(removePerson2)
            person2--;
    }

    /* Final Check if there is any celebrity present in set */
    for (int index = 0; index < NUM_PERSON; index++) {
        if(knows(person1,index))
            return -1;
    }

    return person1;
}

int main()
{
    printf("\n Celebrity: %d\n", findCelebrity(NUM_PERSON));
}