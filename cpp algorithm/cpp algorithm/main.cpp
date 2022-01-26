#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s;
    
    while(getline(cin, s)){
        int l{}, u{}, n{}, e{};
        for(int i{}; i < s.length(); i++){
            if(s.at(i) >= 'a' && s.at(i) <= 'z') l++;
            if(s.at(i) >= 'A' && s.at(i) <= 'Z') u++;
            if(s.at(i) >= '0' && s.at(i) <= '9') n++;
            if(s.at(i) == ' ') e++;
        }
        cout << l << " " << u << " " << n << " " << e << "\n";
    }
    
    return 0;
}
