#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s1;
    getline(cin, s1);
    
    for (int i{}; i < s1.length(); i++) {
        if(s1.at(i) >= 'a' && s1.at(i) + 13 <= 'z') s1.at(i) += 13;
        else if(s1.at(i) - 13 >= 'a' && s1.at(i) <= 'z') s1.at(i) -= 13;
        else if(s1.at(i) >= 'A' && s1.at(i) + 13 <= 'Z') s1.at(i) += 13;
        else if(s1.at(i) - 13 >= 'A' && s1.at(i) <= 'Z') s1.at(i) -= 13;
    }
    
    cout << s1 << "\n";
    
    return 0;
}
