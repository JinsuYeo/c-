#include <iostream>
#include <string>
#include <vector>

// 템플릿 클래스는 일반적으로 cpp 파일 없이 헤더파일에 완전히 포함됨.
// -> blueprint이기 때문에 컴파일러가 컴파일 x, 컴파일러가 템플릿 클래스 사용해서 특정 버전의 클래스를 만들고 그것을 컴파일 함.
// cpp 파일에 넣게되면 문제 발생 가능.
template <typename T>
class Item {
private:
    std::string name;
    T value;
public:
    Item(std::string name, T value): name{name}, value{value}
    {}
    std::string get_name() const {return name;}
    T get_value() const {return value;}
};

template <typename T1, typename T2>
struct My_pair{
    T1 first;
    T2 second;
};


//template <typename T>
//T min(T a, T b) {
//    return (a < b) ? a : b;
//}
//
//template <typename T1, typename T2>
//void func(T1 a, T2 b){
//    std::cout << a << " " << b << std::endl;
//}
//
//struct Person {
//    std::string name;
//    int age;
//    bool operator<(const Person &rhs) const {
//        return this->age < rhs.age;
//    }
//};
//
//std::ostream &operator<<(std::ostream &os, const Person &rhs) {
//    os << rhs.name;
//    return os;
//}
//
//template<typename T>
//void my_swap(T &a, T &b) {
//    T temp = a;
//    a = b;
//    b = temp;
//}

int main(int argc, const char * argv[]) {
    Item<int> item1 {"Frank", 100};
    std::cout << item1.get_name() << " " << item1.get_value() << std::endl;
    
    Item<std::string> item2 {"Frank", "Professor"};
    std::cout << item2.get_name() << " " << item2.get_value() << std::endl;
    
    Item<Item<std::string>> item3 {"Frank", {"C++", "Professor"}};
    std::cout << item3.get_name() << " "
              << item3.get_value().get_name() << " "
              << item3.get_value().get_value() << std::endl;
    
    std::cout << "\n";
    
    std::vector<Item<double>> vec {};
    vec.push_back(Item<double> {"Larry", 100.0});
    vec.push_back(Item<double> {"Moe", 200.0});
    vec.push_back(Item<double> {"Curly", 300.0});
    
    for(const auto &item: vec) {
        std::cout << item.get_name() << " " << item.get_value() << std::endl;
    }
    
    std::cout << "\n";
    
    My_pair<std::string, int> p1 {"Frank", 100};
    My_pair<int, double> p2 {124, 13.6};
    
    std::cout << p1.first << ", " << p1.second << std::endl;
    std::cout << p2.first << ", " << p2.second << std::endl;
    
//    int x{100};
//    int y{200};
//    std::cout << x << ", " << y << std::endl;
//    my_swap(x, y);
//    std::cout << x << ", " << y << std::endl;
//
//    Person p1 {"Curly", 50};
//    Person p2 {"Moe", 30};
//
//    Person p3 = min(p1, p2);
//    std::cout << p3.name << " is younger" << std::endl;
//
//    std::cout << min<int>(2, 3) << std::endl;
//    std::cout << min(2, 3) << std::endl;
//    std::cout << min('A', 'B') << std::endl;
//    std::cout << min(12.5, 9.2) << std::endl;
//    std::cout << min(5+2*2, 7+40) << std::endl; // 매크로 사용과 다른 부분, 전처리기가 아닌 컴파일러가 처리. c++ 문법을 이해함.
//
//    func<int, int>(10, 20);
//    func(10, 20);
//    func<char, double>('A', 12.4);
//    func('A', 12.4);
//    func(1000, "Testing");
//    func(2000, std::string("Frank"));
//    func(p1, p2);

    return 0;
}
