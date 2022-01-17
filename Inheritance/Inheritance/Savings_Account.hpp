//
//  Savings_Account.hpp
//  Inheritance
//
//  Created by 여진수 on 2022/01/17.
//

#ifndef Savings_Account_hpp
#define Savings_Account_hpp

#include "Account.hpp"

class Savings_Account: public Account
{
public:
    double int_rate;
    void deposit(double amount);
    void withdraw(double amount);
    Savings_Account();
    ~Savings_Account();
};

#endif /* Savings_Account_hpp */
