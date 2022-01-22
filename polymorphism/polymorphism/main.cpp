#include <iostream>

class Base {
public:
    virtual void say_hello() const {
        std::cout << "Hello - I'm a Base class object" << std::endl;
    }
};

class Derived: public Base {
public:
    virtual void say_hello() const override{
        std::cout << "Hello - I'm a Derived class object" << std::endl;

    }
};

void greeting(const Base &obj){
    std::cout << "Greetings: ";
    obj.say_hello();
}
//
//class Account {
//public:
//    virtual void withdraw(double amount) {
//        std::cout << "In Account::withdraw" << std::endl;
//    }
//    virtual ~Account(){ std::cout << "Account::destructor" << std::endl; }
//};
//
//class Checking: public Account {
//public:
//    virtual void withdraw(double amount) {
//        std::cout << "In Checking::withdraw" << std::endl;
//    }
//    virtual ~Checking(){ std::cout << "Checking::destructor" << std::endl; }
//};
//
//class Savings: public Account {
//public:
//    virtual void withdraw(double amount) {
//        std::cout << "In Savings::withdraw" << std::endl;
//    }
//    virtual ~Savings(){ std::cout << "Savings::destructor" << std::endl; }
//};
//
//class Trust: public Account {
//public:
//    virtual void withdraw(double amount) {
//        std::cout << "In Trust::withdraw" << std::endl;
//    }
//    virtual ~Trust(){ std::cout << "Trust::destructor" << std::endl; }
//};

int main(int argc, const char * argv[]) {
    Base *p1 = new Base();
    p1->say_hello();
    
    Derived *p2 = new Derived();
    p2->say_hello();
    
    Base *p3 = new Derived();
    p3->say_hello();
    
    
//    std::cout << "\n === Ponters ====" << std::endl;
//    Account *p1 = new Account();
//    Account *p2 = new Savings();
//    Account *p3 = new Checking();
//    Account *p4 = new Trust();
//
//    p1->withdraw(1000);
//    p2->withdraw(1000);
//    p3->withdraw(1000);
//    p4->withdraw(1000);
//
//    std::cout << "\n === Clean up ====" << std::endl;
//    delete p1;
//    delete p2;
//    delete p3;
//    delete p4;
    
//    Base b;
//    b.say_hello();
//    greeting(b);
//
//    Derived d;
//    d.say_hello();
//    greeting(d);
//
//    Base *ptr = new Derived();
//    ptr->say_hello();
//    greeting(*ptr);
    
    return 0;
}
