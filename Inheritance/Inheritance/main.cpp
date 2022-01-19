#include <iostream>
#include "Account.hpp"
#include "Savings_Account.hpp"

using namespace std;

class Base {
private:
    int value;
public:
    Base() : value{0} { cout << "Base no-args constructor" << endl; }
    Base(int x) : value{x} { cout << "Base (int) overloaded constructor" << endl; }
    ~Base() { cout << "Base destructor" << endl; }
};

class Derived: public Base {
    using Base::Base;
private:
    int doubled_value;
public:
    Derived() : doubled_value{0} { cout << "Deriverd no-args constructor" << endl; }
    Derived(int x) : doubled_value{x*2} { cout << "Deriverd (int) overloaded constructor" << endl; }
    ~Derived() { cout << "Deriverd destructor" << endl; }
};

int main(int argc, const char * argv[]) {
//    Base b;
//    Base b{100};
//    Derived d;
    Derived d{1000};
    
//
//    cout << "=========== Base member access from base object =============\n";
//    Base base;
//    base.a = 100;
////    base.b = 200; // Compiler error
////    base.c = 300; // Compiler error
//
//
//    cout << "=========== Derived member access from derived object =============\n";
//    Derived d;
//    d.a = 100;
    
    
    //d.b = 200; // Compiler error
    //d.c = 300; // Compiler error
    
    
    
    
    
    
//    cout << "\n=== Account ===================" << endl;
//    Account acc{};
//    acc.deposit(2000.0);
//    acc.withdraw(500.0);
//
//    cout << endl;
//
//    Account *p_acc {nullptr};
//    p_acc = new Account();
//    p_acc->deposit(1000.0);
//    p_acc->withdraw(500.0);
//    delete p_acc;
//
//    cout << "\n=== Savings Account ===================" << endl;
//    Savings_Account sav_acc{};
//    sav_acc.deposit(2000.0);
//    sav_acc.withdraw(500.0);
//
//    cout << endl;
//
//    Savings_Account *p_sav_acc {nullptr};
//    p_sav_acc = new Savings_Account();
//    p_sav_acc->deposit(1000.0);
//    p_sav_acc->withdraw(500.0);
//    delete p_sav_acc;
//
//    cout << "\n======================================" << endl;
    
    return 0;
}
