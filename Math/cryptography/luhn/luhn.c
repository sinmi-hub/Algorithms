#include "luhn.h"

bool luhn(const char *num)
{
    if (strlen(num) > 1)
    {
        if (strlen(num) ==  2 && (num[0] == ' ' || num[1] == ' '))
            return false;
       
        int double_digit = 0, sum = 0;
        for (int i = strlen(num) - 1; i >= 0; i--) {
            if (num[i] == ' ') {continue;}
            if (!isdigit(num[i]) ) {return false;}

            int digit = num[i] - '0';
            digit = (double_digit) ? digit * 2 : digit;
            digit = (digit > 9) ? digit - 9 : digit;
    
            sum += digit;
            double_digit = !double_digit;
        }
        
        return (sum % 10 == 0);
    }
    
   return false;
}