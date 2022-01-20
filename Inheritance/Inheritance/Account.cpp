//
//  Account.cpp
//  Inheritance
//
//  Created by 여진수 on 2022/01/17.
//
#include <iostream>
#include "Account.hpp"

bool Account::deposit(double amount){
    std::cout << "Account deposit called with " << amount << std::endl;
    if(amount < 0)
        return false;
    else {
        balance += amount;
        return true;
    }
}

bool Account::withdraw(double amount){
    std::cout << "Account withdraw called with " << amount << std::endl;
    if(balance - amount >= 0){
        balance -= amount;
        return true;
    }
    else
    {
        std::cout << "Insufficient funds" << std::endl;
        return false;
    }
        
}

Account::Account(std::string name, double balance)
: name{name}, balance{balance} {
}

Account::~Account(){
}

std::ostream &operator<<(std::ostream &os, const Account &account){
    os << "Account balance: " << account.balance;
    return os;
}
