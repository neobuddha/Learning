#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 2147483647
#define INT_MIN -2147483648

 int addOvf(int* result, int a, int b)
 {
     if(a > 0 && b > 0 && (b > INT_MAX - a))
         return -1;
     if(a < 0 && (b < INT_MIN - a))
         return -1;

     *result = a + b;
     return 0;
 }

 int multipleOvf(int *result, int a, int b)
 {
    *result = a * b;

     if((a == 0) || (b == 0)) {
        return 0;
     }
    
    if (a != *result / b)
        return -1;

    return 0;    
 }

int myAtoi(char* str) {
    char *ptr = str;
    int sign = 1;
    int overFlow = 0;
    int intValue = 0;
    int value = 0;
    int retValue = 0;
    
    // Skip leading Space, " characters
    while ((*ptr == ' ' || *ptr =='"') && *ptr != '\0')
        ptr++;
    // Check if String ended without any valid input.
    if(*ptr == '\0') {
        return 0;
    }

    //Check if "-" or "+" is defined
    if(*ptr == '-')
    {
        ptr++;
        sign = -1;
    } 
    else if(*ptr == '+')
    {
        ptr++;
    } 
    
    while(*ptr != '\0' && *ptr != ' ' && *ptr != '"')
    {
        value = *ptr - '0';

        // If non-numeric value in input
        if (value < 0 || value > 9)
            break;
        else
        {
            if (multipleOvf(&intValue , intValue, 10) == -1)
                    overFlow = -1;

                if (overFlow != -1)
                    overFlow = addOvf(&intValue, intValue, value);

                if (overFlow ==  -1) 
                {
                    if (sign != -1)
                        return (INT_MAX);
                    else
                        return (INT_MIN);
                }  
        } 
        
        ptr++;
    }
    
    return intValue * sign;
}


int main()
{
    char str[100] = "-6147483648";
    //char str[100] = "9991283472332";

    //while (1) {
        //printf("\n Enter Value: ");
        //scanf("%s", str);

        int value = myAtoi(str);
        printf("\n Output: %d\n", value);
    //}

    return 0;
}