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
    friend bool operator==(const Mystring &lhs, const Mystring &rhs);
    friend Mystring operator-(const Mystring &obj);
    friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);
    friend std::ostream& operator<<(std::ostream &os, const Mystring &obj);
    friend std::istream& operator>>(std::istream &is, Mystring &obj);
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
//    Mystring operator-() const;
//    Mystring operator+(const Mystring &rhs) const;
//    bool operator==(const Mystring &rhs) const;
};


#endif /* Mystring_h */
