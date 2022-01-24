#include <iostream>
#include <memory>
#include <vector>

#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

class Test {
private:
    int data;
public:
    Test(): data{0} { std::cout << "Test constructor (" << data << ")" << std::endl; }
    Test(int data): data{data} { std::cout << "Test constructor (" << data << ")" << std::endl; }
    int get_data() const { return data; }
    ~Test() { std::cout << "Test destructor (" << data << ")" << std::endl; }
};

int main() {
    std::shared_ptr<int> p1 {new int {100}};
    std::cout << "Use count: " << p1.use_count() << std::endl;
    
    std::shared_ptr<int> p2 {p1};
    std::cout << "Use count: " << p2.use_count() << std::endl;
    
    p1.reset();
    std::cout << "Use count: " << p1.use_count() << std::endl;
    std::cout << "Use count: " << p2.use_count() << std::endl;
    
//    Test *t1 = new Test {1000};
//    delete t1;
//
//    std::unique_ptr<Test> t2 {new Test {100}};
//    std::unique_ptr<Test> t3 = std::make_unique<Test> (1000);
//
//    std::unique_ptr<Test> t4;
//    t4 = std::move(t2);
//    if (!t2) {
//        std::cout << "t2 is nullptr" << std::endl;
//    }
    
//    std::unique_ptr<Account> a1 = std::make_unique<Checking_Account>("Moe", 5000);
//    std::cout << *a1 << std::endl;
//    a1->deposit(5000);
//    std::cout << *a1 << std::endl;
//
//    std::vector<std::unique_ptr<Account>> accounts;
//    accounts.push_back(std::make_unique<Checking_Account>("James", 1000));
//    accounts.push_back(std::make_unique<Savings_Account>("Billy", 4000, 5.2));
//    accounts.push_back(std::make_unique<Trust_Account>("Bobby", 5000, 4.5));
//
//    for(const auto &acc: accounts) {
//        std::cout << *acc << std::endl;
//    }
    
    return 0;
}

