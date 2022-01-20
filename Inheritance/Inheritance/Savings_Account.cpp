//
//  Savings_Account.cpp
//  Inheritance
//
//  Created by 여진수 on 2022/01/17.
//

#include <iostream>
#include "Savings_Account.hpp"

void Savings_Account::deposit(double amount){
    std::cout << "Savings Account deposit called with " << amount << std::endl;
    amount = amount + (amount * int_rate/100);
    Account::deposit(amount);
}

Savings_Account::Savings_Account()
: Savings_Account{0.0, 0.0}{
    
}

Savings_Account::Savings_Account(double balance, double int_rate)
: Account(balance), int_rate {int_rate}{
}


Savings_Account::~Savings_Account(){
}

std::ostream &operator<<(std::ostream &os, const Savings_Account &account){
    os << "Savings account balance: " << account.balance << " Interest rate: " << account.int_rate;
    return os;
}
