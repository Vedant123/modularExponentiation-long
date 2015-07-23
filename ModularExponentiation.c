/**********************************************************
*  ModularExponentiation.c                                *
*  modularExponentiation-long                             *
*                                                         *
*  Created by Vedant Mathur on 7/23/15.                   *
*  Copyright (c) 2015 Vedant Mathur. All rights reserved. *
 **********************************************************/

#include "ModularExponentiation.h"

//main function
int main(int argc, char* argv[])
{
    ll base;
    ll exponent;
    ll modulus;
    //prompting user for data
    printf("Enter the desired base: \n");
    scanf("%lld", &base);
    
    printf("Enter the desired exponent: \n");
    scanf("%lld", &exponent);
    
    printf("Enter the desired modulus: \n");
    scanf("%lld", &modulus);
    
    printf("%lld\n", modularExponentiation(base, exponent, modulus));
    
    return 0;
}

//primary function for the computation
ll modularExponentiation(ll base, ll exponent, ll modulo)
{
    //initializes binary variable
    ll binaryExponent;
    binaryExponent = convertToBinary(exponent);
    //defines the length of the binary string through the implementation of logarithms
    const int binaryLength = log(binaryExponent) + 1;
    //allocates the memory to a character array
    char binaryStr[binaryLength];
    //sets the buffer to convert the long long binary to a string 
    sprintf(binaryStr, "%lld", binaryExponent);
    //declaration of finalProduct
    long finalProduct;
    finalProduct = 1;
    
    int i;
    i = strlen(binaryStr) - 1;
    
    //loops thorugh the binary in reverse order
    for(; i >= 0; --i)
    {
        if(binaryStr[i] == '1')
        {
            //calls on calculateModularMultiplier function to complete calculation
            finalProduct *= calculateModularMultiplier(base, pow(2, strlen(binaryStr) - 1 - i), modulo);
        }
    }
    
    //return the final answer
    return finalProduct % modulo;
}

//recursive function to produce the required modulus multiplying
ll calculateModularMultiplier(ll base, ll exponent, ll modulus)
{
    //base case
    if(exponent == 1)
    {
        return base % modulus;
    }
    //recursive call
    return (calculateModularMultiplier(base, exponent / 2, modulus) % 19 * calculateModularMultiplier(base, exponent / 2, modulus) % 19) % modulus;
}

//recursive function to convert decimal number to binary
ll convertToBinary(ll decimalNumber)
{
    if(decimalNumber == 0)
    {
        return 0;
    }
    else
    {
        return (decimalNumber % 2) + 10 * convertToBinary((int)decimalNumber / 2);
    }
}
