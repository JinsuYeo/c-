#include <iostream>
#include <string>

template <typename T>
T min(T a, T b) {
    return (a < b) ? a : b;
}

template <typename T1, typename T2>
void func(T1 a, T2 b){
    std::cout << a << " " << b << std::endl;
}

struct Person {
    std::string name;
    int age;
    bool operator<(const Person &rhs) const {
        return this->age < rhs.age;
    }
};

std::ostream &operator<<(std::ostream &os, const Person &rhs) {
    os << rhs.name;
    return os;
}

template<typename T>
void my_swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

int main(int argc, const char * argv[]) {
    int x{100};
    int y{200};
    std::cout << x << ", " << y << std::endl;
    my_swap(x, y);
    std::cout << x << ", " << y << std::endl;
    
    Person p1 {"Curly", 50};
    Person p2 {"Moe", 30};
    
    Person p3 = min(p1, p2);
    std::cout << p3.name << " is younger" << std::endl;
    
    std::cout << min<int>(2, 3) << std::endl;
    std::cout << min(2, 3) << std::endl;
    std::cout << min('A', 'B') << std::endl;
    std::cout << min(12.5, 9.2) << std::endl;
    std::cout << min(5+2*2, 7+40) << std::endl; // 매크로 사용과 다른 부분, 전처리기가 아닌 컴파일러가 처리. c++ 문법을 이해함.
    
    func<int, int>(10, 20);
    func(10, 20);
    func<char, double>('A', 12.4);
    func('A', 12.4);
    func(1000, "Testing");
    func(2000, std::string("Frank"));
    func(p1, p2);

    return 0;
}
