#include <iostream>
#include "Account.hpp"
#include "Savings_Account.hpp"

using namespace std;

class Base {
    // Note friend of Base have access to all
public:
    int a{};
    void display() { cout << a << ", " << b << ", " << c << endl;} // member method has access to all
protected:
    int b{};
private:
    int c{};
};

class Derived: public Base {
    // Note friends of Derived have access to only Derived has access to
    
    // a will be public
    // b will be protected
    // c will not be acceessible
public:
    void access_base_members(){
        a = 100; // OK
        b = 200; // OK
//        c = 300; // not accessible
    }
};

int main(int argc, const char * argv[]) {
    
    cout << "=========== Base member access from base object =============\n";
    Base base;
    base.a = 100;
//    base.b = 200; // Compiler error
//    base.c = 300; // Compiler error
    
    
    cout << "=========== Derived member access from derived object =============\n";
    Derived d;
    d.a = 100;
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
