//
//  Mystring.cpp
//  operatorOverloading
//
//  Created by 여진수 on 2021/11/28.
//

#include <cstring>
#include <iostream>
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
    std::cout << "Copy assignment\n";
    
    return *this;
}

Mystring& Mystring::operator=(Mystring &&rhs) {
    std::cout << "Using move assignment" << std::endl;
    
    if(this == &rhs)
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}
