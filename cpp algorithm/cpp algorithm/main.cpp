#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
   
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s;
    vector<int> v;

    cin >> s;
    
    reverse(s.begin(), s.end());

    for(int i{}; i < s.length(); i++) {
        int n = s.at(i) - '0';
        while(n/2) {
            v.push_back(n%2);
            n /= 2;
        }
        v.push_back(n);
        if(i != s.length()-1) {
            while (v.size() < (i+1)*3) {
                v.push_back(0);
            }
        }
    }
    
    for(int i{(int)v.size()-1}; i >= 0; i--) {
        cout << v.at(i);
    }
    cout << "\n";
    
    return 0;
}
