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
    friend std::ostream &operator<<(std::ostream &os, const Savings_Account &account);
protected:
    double int_rate;
public:
    void deposit(double amount);
//    void withdraw(double amount); // Withdraw is inherited
    Savings_Account();
    Savings_Account(double balance, double int_rate);
    ~Savings_Account();
};

#endif /* Savings_Account_hpp */
