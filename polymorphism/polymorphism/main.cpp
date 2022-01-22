#include <iostream>
#include <vector>

//class Base {
//public:
//    virtual void say_hello() const {
//        std::cout << "Hello - I'm a Base class object" << std::endl;
//    }
//};
//
//class Derived: public Base {
//public:
//    virtual void say_hello() const override{
//        std::cout << "Hello - I'm a Derived class object" << std::endl;
//
//    }
//};
//
//void greeting(const Base &obj){
//    std::cout << "Greetings: ";
//    obj.say_hello();
//}
//
//
class I_Printable {
    friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);
public:
    virtual void print(std::ostream &os) const = 0;
};

std::ostream &operator<<(std::ostream &os, const I_Printable &obj){
    obj.print(os);
    return os;
}

class Account: public I_Printable {
//    friend std::ostream &operator<<(std::ostream &os, const Account &acc);
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }
    virtual void print(std::ostream &os) const override {
        os << "Account display";
    }
    virtual ~Account(){ std::cout << "Account::destructor" << std::endl; }
};

//std::ostream &operator<<(std::ostream &os, const Account &acc){
//    os << "Account display";
//    return os;
//}

class Checking: public Account {
//    friend std::ostream &operator<<(std::ostream &os, const Checking &acc);
public:
    virtual void withdraw(double amount) override {
        std::cout << "In Checking::withdraw" << std::endl;
    }
    virtual void print(std::ostream &os) const override {
        os << "Checking display";
    }
    virtual ~Checking(){ std::cout << "Checking::destructor" << std::endl; }
};

//std::ostream &operator<<(std::ostream &os, const Checking &acc){
//    os << "Checking display";
//    return os;
//}

class Savings: public Account {
//    friend std::ostream &operator<<(std::ostream &os, const Savings &acc);
public:
    virtual void withdraw(double amount) override {
        std::cout << "In Savings::withdraw" << std::endl;
    }
    virtual void print(std::ostream &os) const override {
        os << "Savings display";
    }
    virtual ~Savings(){ std::cout << "Savings::destructor" << std::endl; }
};
//
//std::ostream &operator<<(std::ostream &os, const Savings &acc){
//    os << "Savings display";
//    return os;
//}

class Trust: public Account {
//    friend std::ostream &operator<<(std::ostream &os, const Trust &acc);
public:
    virtual void withdraw(double amount) override {
        std::cout << "In Trust::withdraw" << std::endl;
    }
    virtual void print(std::ostream &os) const override {
        os << "Trust display";
    }
    virtual ~Trust(){ std::cout << "Trust::destructor" << std::endl; }
};

//std::ostream &operator<<(std::ostream &os, const Trust &acc){
//    os << "Trust display";
//    return os;
//}

void do_withdraw(Account &account, double amount) {
    account.withdraw(amount);
}
//
//class Shape {
//public:
//    virtual void draw() = 0;
//    virtual void rotate() = 0;
//    virtual ~Shape(){}
//};
//
//class Open_Shape: public Shape {
//public:
//    virtual ~Open_Shape(){}
//};
//
//class Closed_Shape: public Shape {
//public:
//    virtual ~Closed_Shape(){}
//};
//
//class Line: public Open_Shape {
//public:
//    virtual void draw() override {
//        std::cout << "Drawing a line" << std::endl;
//    }
//    virtual void rotate() override {
//        std::cout << "Rotating a line" << std::endl;
//    }
//    virtual ~Line(){}
//};
//
//class Circle: public Closed_Shape {
//public:
//    virtual void draw() override {
//        std::cout << "Drawing a circle" << std::endl;
//    }
//    virtual void rotate() override {
//        std::cout << "Rotating a circle" << std::endl;
//    }
//    virtual ~Circle() {}
//};
//
//class Square: public Closed_Shape {
//public:
//    virtual void draw() override {
//        std::cout << "Drawing a square" << std::endl;
//    }
//    virtual void rotate() override {
//        std::cout << "Rotating a square" << std::endl;
//    }
//    virtual ~Square() {}
//};
//
//void screen_refresh(const std::vector<Shape*> &shapes){
//    std::cout << "Refreshing" << std::endl;
//    for(const auto p: shapes)
//        p->draw();
//}
//
int main(int argc, const char * argv[]) {
//    Account a;
//    std::cout << a << std::endl;
//
//    Checking c;
//    std::cout << c << std::endl;
//
//    Savings s;
//    std::cout << s << std::endl;
//
//    Trust t;
//    std::cout << t << std::endl;
//
    Account *p1 = new Account();
    std::cout << *p1 << std::endl;
    
    Account *p2 = new Checking();
    std::cout << *p2 << std::endl;
    
    
//    Circle c;
//    c.draw();
//
//    Shape *ptr = new Circle();
//    ptr->draw();
//    ptr->rotate();
//    delete ptr;
//
//    Shape *s1 = new Circle();
//    Shape *s2 = new Line();
//    Shape *s3 = new Square();
//
//    std::vector<Shape*> shapes {s1, s2, s3};
////    for(const auto p: shapes)
////        p->draw();
//    screen_refresh(shapes);
//
//    delete s1;
//    delete s2;
//    delete s3;

    
    
//    Account a;
//    Account &ref = a;
//    ref.withdraw(1000);
//
//    Trust t;
//    Account &ref1 = t;
//    ref1.withdraw(1000);
//
//    Account a1;
//    Savings a2;
//    Checking a3;
//    Trust a4;
//
//    do_withdraw(a1, 1000);
//    do_withdraw(a2, 2000);
//    do_withdraw(a3, 3000);
//    do_withdraw(a4, 4000);
//
//
    
//    Base *p1 = new Base();
//    p1->say_hello();
//
//    Derived *p2 = new Derived();
//    p2->say_hello();
//
//    Base *p3 = new Derived();
//    p3->say_hello();
    
    
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
