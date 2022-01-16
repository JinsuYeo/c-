//
//  Mystring.cpp
//  operatorOverloading
//
//  Created by 여진수 on 2021/11/28.
//

#include <cstring>
#include <iostream>
#include <cctype>
#include "Mystring.h"

Mystring::Mystring()
: str{nullptr}{
    str = new char[1];
    *str = '\0';
}

Mystring::Mystring(const char *s)
: str{nullptr}{
    if(s == nullptr) {
        str = new char[1];
        *str = '\0';
    } else {
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);
    }
}

Mystring::Mystring(const Mystring &source)
: str {nullptr}{
    str = new char[std::strlen(source.str)+1];
    std::strcpy(str, source.str);
}

Mystring::~Mystring(){
    delete [] str;
}

void Mystring::display() const {
    std::cout << str << ": " << std::strlen(str) << std::endl;
}

size_t Mystring::get_length() const {
    return std::strlen(str);
}

const char* Mystring::get_str() const {
    return str;
}

Mystring& Mystring::operator=(const Mystring &rhs){
    std::cout << "Using copy assignment" << std::endl;
    
    if(this == &rhs)
        return *this;
    delete [] this->str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);
    
    return *this;
}

Mystring& Mystring::operator=(Mystring &&rhs) { //r-value가 인자로 들어올 때 실핼됨.
    std::cout << "Using move assignment" << std::endl;
    
    if(this == &rhs)
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

Mystring operator-(const Mystring &obj){
    char* buffer = new char[std::strlen(obj.str) + 1];
    std::strcpy(buffer, obj.str);
    for(size_t i {}; i < std::strlen(buffer); i++)
        buffer[i] = tolower(buffer[i]);
    Mystring temp {buffer};
    delete [] buffer;
    return temp;
}

Mystring operator+(const Mystring &lhs, const Mystring &rhs){
    char* buffer = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
    std::strcpy(buffer, lhs.str);
    std::strcat(buffer, rhs.str);
    Mystring temp {buffer};
    delete [] buffer;
    return temp;
}

bool operator==(const Mystring &lhs, const Mystring &rhs){
    return (std::strcmp(lhs.str, rhs.str) == 0);
}

std::ostream& operator<<(std::ostream &os, const Mystring &obj){
    os << obj.str;
    return os;
}

std::istream& operator>>(std::istream &is, Mystring &obj){
    char* buffer = new char[1000];
    is >> buffer;
    obj = Mystring{buffer};
    delete [] buffer;
    
    return is;
}
