//
//  Account.hpp
//  Inheritance
//
//  Created by 여진수 on 2022/01/17.
//

#ifndef Account_hpp
#define Account_hpp
#include <string>
#include <iostream>

class Account
{
    friend std::ostream &operator<<(std::ostream &os, const Account &account);
private:
    static constexpr const char* def_name = "Unnamed Account"; // static은 클래스에 속하는 모든 객체들이 하나의 변수를 공유하게 하기 위함(변수가 한번만 생성됨) + global name space를 오염시키지 않기 위해 클래스 내부에서 정의하기 위함임.
    static constexpr double def_balance = 0.0; // constexpr은 클래스 내부에서 static class 멤버를 초기화 하기 위함. 일반화된 상수 표현식 -> 변수, 함수, 생성자 함수를 컴파일 타임에 평가될 수 있도록 처리해 줄 수 있음(반환값 계산 등).
protected:
    double balance;
public:
    std::string name;
    bool deposit(double amount);
    bool withdraw(double amount);
    Account(std::string name = def_name, double balance = def_balance);
    ~Account();
};


#endif /* Account_hpp */
