//
//  Account.cpp
//  Inheritance
//
//  Created by 여진수 on 2022/01/17.
//
#include <iostream>
#include "Account.hpp"

void Account::deposit(double amount){
    std::cout << "Account deposit called with " << amount << std::endl;
    balance += amount;
}

void Account::withdraw(double amount){
    std::cout << "Account withdraw called with " << amount << std::endl;
    if(balance - amount >= 0)
        balance -= amount;
    else
        std::cout << "Insufficient funds" << std::endl;
}

Account::Account()
: balance(0.0), name("An Account"){
}

Account::Account(double balance)
: balance(balance){
}

Account::~Account(){
}

std::ostream &operator<<(std::ostream &os, const Account &account){
    os << "Account balance: " << account.balance;
    return os;
}
