#include <iostream>
#include <string>
#include <vector>

class Deep {
private:
    int *data;
public:
    void set_data_value(int d){*data = d;}
    int get_data_value(){return *data;}
    Deep(int d);
    Deep(const Deep &source);
    Deep(Deep &&source) noexcept;
    ~Deep();
};

Deep::Deep(int d) {
    data = new int;
    *data = d;
}

Deep::~Deep(){
    if(data != nullptr) {
        std::cout << "Destructor freeing data for: " << *data << '\n';
    } else {
        std::cout << "Destructor freeing data for nullptr" << '\n';
    }
    delete data;
}

Deep::Deep(const Deep &source)
    : Deep(*source.data) {
    std::cout << "Copy constructor - Deep: " << *data << '\n';
}

Deep::Deep(Deep &&source) noexcept
    :data {source.data} {
        source.data = nullptr;
}

int main(int argc, const char * argv[]) {
    std::vector<Deep> vec;
    
    Deep obj1 {100};
    Deep obj2 {obj1};
    
    vec.push_back(obj1);
    
    vec.push_back(obj2);
    
    vec.push_back(Deep{200});
    
    vec.push_back(Deep{300});

    return 0;
}
