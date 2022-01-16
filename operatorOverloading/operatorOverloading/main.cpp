#include <iostream>
#include <vector>
#include "Mystring.h"

using namespace std;

int main(int argc, const char * argv[]) {
    cout << boolalpha << endl;
    
    Mystring larry{"Larry"};
    Mystring moe{"Moe"};
    
    Mystring stooge = larry;
    larry.display();
    moe.display();
    
    cout << (larry == moe) << endl;
    cout << (larry == stooge) << endl;
    
    larry.display();
    Mystring larry2 = -larry;
    larry.display();
    
    Mystring stooges = larry + "Moe";
    
    Mystring two_stooges = moe + " " + "Larry";
    two_stooges.display();
    

    return 0;
}
