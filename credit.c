#include <stdio.h>
#include <string.h>

// Amerincan Express numbers starts with 34 or 37 -> 15 digit
// MasterCard numbers starts with 51, 52, 53, 54 or 55 -> 16 digit
// Visa numbers starts with 04 - > 13 and 16 digits

// test card 4003600000000014

int main(void)
{
    long creditCardNumber;

    do
    {
        printf("Input CC number: \n");
        scanf("%ld", &creditCardNumber);
    }
    while (&creditCardNumber <= 0);

    long workingCC = creditCardNumber;
    int sum;
    int count = 0;
    long divisor = 10;
    char result[11];

    // 1st case
    while (workingCC > 0)
    {
        int lastDigit = workingCC % 10;
        sum = sum + lastDigit;
        workingCC = workingCC / 100;
    }

    // 2nd case
    workingCC = creditCardNumber / 10;
    while (workingCC > 0)
    {
        int lastDigit = workingCC % 10;
        int timesTwo = lastDigit * 2;
        sum = sum + (timesTwo % 10) + (timesTwo / 10);
        workingCC = workingCC / 100;
    }

    workingCC = creditCardNumber;
    while (workingCC != 0 )
    {
        workingCC = workingCC / 10;
        count++;
    }

    printf("%i\n", count);

    for (int i = 0; i < count - 2; i++ ) {

      divisor = divisor * 10;

    }

    int firstDigit = creditCardNumber / divisor;

    int firstTwoDigits = creditCardNumber / (divisor / 10);

    if (sum % 10 == 0)
    {
        if (firstDigit == 4 && (count == 13 || count == 16))
        {
            strcpy(result, "VISA");
        }
        else if ((firstTwoDigits == 34 || firstTwoDigits == 37) && count == 15)
        {
            strcpy(result, "AMEX");
          
        } else if ((firstTwoDigits >= 51 && firstTwoDigits <= 58) && count == 16)
        {
            strcpy(result, "MASTERCARD");
        } else {
            strcpy(result, "INVALID");
        }
    }
    else
    {
            strcpy(result, "INVALID");
    }
    printf("%s\n", result);
}
