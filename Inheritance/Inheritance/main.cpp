#include <iostream>
#include "Account.hpp"
#include "Savings_Account.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    cout << "\n=== Account ===================" << endl;
    Account acc{};
    acc.deposit(2000.0);
    acc.withdraw(500.0);
    
    cout << endl;
    
    Account *p_acc {nullptr};
    p_acc = new Account();
    p_acc->deposit(1000.0);
    p_acc->withdraw(500.0);
    delete p_acc;
    
    cout << "\n=== Savings Account ===================" << endl;
    Savings_Account sav_acc{};
    sav_acc.deposit(2000.0);
    sav_acc.withdraw(500.0);
    
    cout << endl;
    
    Savings_Account *p_sav_acc {nullptr};
    p_sav_acc = new Savings_Account();
    p_sav_acc->deposit(1000.0);
    p_sav_acc->withdraw(500.0);
    delete p_sav_acc;
    
    cout << "\n======================================" << endl;
    
    return 0;
}
