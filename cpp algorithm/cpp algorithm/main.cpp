#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s;
    cin >> s;
    int count{}, result{};
    
    for(int i{}; i < s.length(); i++) {
        if(s.at(i) == '(' && s.at(i+1) != ')') {
            count++;
            result++;
        } else if(s.at(i) == '(' && s.at(i+1) == ')') {
            result += count;
        } else if(s.at(i) == ')' && s.length() != 0 && s.at(i-1) != '(') count--;
    }
    
    cout << result << "\n";
    
    return 0;
}
