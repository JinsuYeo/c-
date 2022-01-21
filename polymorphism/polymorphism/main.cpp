#include <iostream>

class Base {
public:
    void say_hello() const {
        std::cout << "Hello - I'm a Base class object" << std::endl;
    }
};

class Derived: public Base {
public:
    void say_hello() const {
        std::cout << "Hello - I'm a Derived class object" << std::endl;
        
    }
};

void greeting(const Base &obj){
    std::cout << "Greetings: ";
    obj.say_hello();
}

int main(int argc, const char * argv[]) {
    Base b;
    b.say_hello();
    greeting(b);
    
    Derived d;
    d.say_hello();
    greeting(d);
    
    Base *ptr = new Derived();
    ptr->say_hello();
    greeting(*ptr);
    
    return 0;
}
