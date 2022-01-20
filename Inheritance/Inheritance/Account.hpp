//
//  Account.hpp
//  Inheritance
//
//  Created by 여진수 on 2022/01/17.
//

#ifndef Account_hpp
#define Account_hpp
#include <string>
#include <iostream>

class Account
{
    friend std::ostream &operator<<(std::ostream &os, const Account &account);
protected:
    double balance;
public:
    std::string name;
    void deposit(double amount);
    void withdraw(double amount);
    Account();
    Account(double balance);
    ~Account();
};


#endif /* Account_hpp */
