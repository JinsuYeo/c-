#include <iostream>
#include <string>

class Deep {
private:
    int *data;
public:
    void set_data_value(int d){*data = d;}
    int get_data_value(){return *data;}
    Deep(int d);
    Deep(const Deep &source);
    ~Deep();
};

Deep::Deep(int d) {
    data = new int;
    *data = d;
}

Deep::~Deep(){
    delete data;
    std::cout << "Destructor freeing data" << '\n';
}

Deep::Deep(const Deep &source)
    : Deep(*source.data) {
    std::cout << "Copy constructor - deep\n";
}

void display_deep(Deep s){
    std::cout << s.get_data_value() << std::endl;
}


int main(int argc, const char * argv[]) {
    Deep obj1 {100};
    display_deep(obj1);
    
    Deep obj2 {obj1};
    
    obj2.set_data_value(1000);
    display_deep(obj2);

    return 0;
}
