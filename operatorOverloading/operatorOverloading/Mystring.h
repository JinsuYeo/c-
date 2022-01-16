//
//  Mystring.hpp
//  operatorOverloading
//
//  Created by 여진수 on 2021/11/28.
//

#ifndef Mystring_h
#define Mystring_h

#include <iostream>

class Mystring {
private:
    char* str;
public:
    Mystring();
    Mystring(const char* s);
    Mystring(const Mystring &source);
    ~Mystring();
    void display() const;
    size_t get_length() const;
    const char *get_str() const;
    Mystring& operator=(const Mystring &rhs);
    Mystring& operator=(Mystring &&rhs);
    Mystring operator-() const;
    Mystring operator+(const Mystring &rhs) const;
    bool operator==(const Mystring &rhs) const;
};


#endif /* Mystring_h */
