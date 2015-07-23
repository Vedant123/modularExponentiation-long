/**********************************************************
*  ModularExponentiation.h                                *
*  modularExponentiation-long                             *
*                                                         *
*  Created by Vedant Mathur on 7/23/15.                   *
*  Copyright (c) 2015 Vedant Mathur. All rights reserved. *
**********************************************************/

#include <stdio.h>
#include <math.h>
#include <string.h>

#ifndef MODULAR-EXPONENTIATION_H_INCLUDED
#define MODULAR-EXPONENTIATION_H_INCLUDED

    typedef char* string;
    typedef long long ll;
    
    ll modularExponentiation(ll base, ll exponent, ll modulo);
    ll calculateModularMultiplier(ll base, ll exponent, ll modulus);
    ll convertToBinary(ll decimalNumber);

#endif