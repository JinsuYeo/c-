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
    int sum{};

    cin >> s;
    
    reverse(s.begin(), s.end());

    for(int i{}; i*3 < s.length(); i++) {
        sum = s.at(i*3)-'0';
        if(i*3+1 < s.length()) sum += (s.at(i*3+1)-'0')*2;
        if(i*3+2 < s.length()) sum += + (s.at(i*3+2) -'0')*4;
        v.push_back(sum);
        sum = 0;
    }
    
    for(int i{(int)v.size()-1}; i >= 0; i--) {
        cout << v.at(i);
    }
    cout << "\n";
    
    return 0;
}
