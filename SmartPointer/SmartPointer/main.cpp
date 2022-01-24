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
    Test *t1 = new Test {1000};
    delete t1;
    
    std::unique_ptr<Test> t2 {new Test {100}};
    std::unique_ptr<Test> t3 = std::make_unique<Test> (1000);
    
    std::unique_ptr<Test> t4;
    t4 = std::move(t2);
    if (!t2) {
        std::cout << "t2 is nullptr" << std::endl;
    }
    
    return 0;
}

