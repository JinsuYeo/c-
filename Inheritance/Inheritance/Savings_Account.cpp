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
}

void Savings_Account::withdraw(double amount){
    std::cout << "Savings Account withdraw called with " << amount << std::endl;
}

Savings_Account::Savings_Account()
: int_rate(3.0){
    
}

Savings_Account::~Savings_Account(){
    
}
