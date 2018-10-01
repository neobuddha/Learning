#include <stdio.h>
#include <stdlib.h>

int myAtoi(char* str) {
    char *ptr = str;
    int sign = 1;
    int intValue = 0;
    int value = 0;
    
    while ((*ptr == ' ' || *ptr =='""') && *ptr != '\0')
        ptr++;
    
    if(*ptr == '\0') {
        return 0;
    }
    
    if(*ptr == '-')
    {
        ptr++;
        sign = -1;
    }
    
    while(*ptr != '\0' || *ptr != ' ' || *ptr != '""')
    {
        value = *ptr - '0';
        if (value < 0 || value > 9)
            return 0;
        else
        {
            intValue = intValue*10 + value;
        } 
        
        ptr++;
    }
    
    return intValue;
}


void main()
{
    char str[] = "42"
    printf("\n Output: %d", myAtoi(str));
}