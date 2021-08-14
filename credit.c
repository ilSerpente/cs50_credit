#include<cs50.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

bool card_validation(long card_number)
{
    long cardnr = card_number / 10;
    int sum = 0;
    while (cardnr)
    {
        if ((cardnr % 10) * 2 > 9)
            sum += (((cardnr % 10) * 2) / 10) + (((cardnr % 10) * 2) % 10);
        else 
            sum += (cardnr % 10) * 2;
        cardnr = cardnr / 100;
    }
    cardnr = card_number;
    while (cardnr)
    {
        sum += cardnr % 10;
        cardnr = cardnr / 100;
    }
    return !(sum % 10);
}

bool validate_amex(long number)
{
    int a = number / 10000000000000;
    if (a == 34 || a == 37)
    {
        if (card_validation(number))
        {
            printf("AMEX\n");
            return true;
        }
    }
    return false;
}

bool validate_visa(long number)
{
int b = number / 1000000000000;
    if (b == 4)
    {
        if (card_validation(number))
        {
            printf("VISA\n");
            return true;
        }
    }
    return false;
}

bool validate_mastercardorvisa(long number)
{
    int b = number / 100000000000000;
    if (b / 10 == 4)
    {
        if (card_validation(number))
        {
            printf("VISA\n");
            return true;
        }
    }
    else if (b >= 51 && b <= 55)
    {
        if (card_validation(number))
        {
            printf("MASTERCARD\n");
            return true;
        }
    }
    return false;
} 

bool cards_validator(int nDigits, long number)
{
    bool is_valid = false;
    if (nDigits == 15)
        is_valid = validate_amex(number);
    else if (nDigits == 13)
        is_valid = validate_visa(number);
    else if (nDigits == 16)
        is_valid = validate_mastercardorvisa(number);
    return is_valid;
}

int main(void)
{
    long number = get_long("Number: ");
    int nDigits = floor(log10(labs(number))) + 1;
    if (!cards_validator(nDigits, number))
        printf("INVALID\n");
    return 0;
}
