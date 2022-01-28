#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s;
    int n{};
    stack<char> sl;
    stack<char> sr;
    
    cin >> s >> n;
    
    for(int i{}; i < s.size(); i++)
        sl.push(s.at(i));
    
    for(int i{}; i < n; i++) {
        char t;
        cin >> t;
        if(t == 'P') {
            char c;
            cin >> c;
            sl.push(c);
        }
        if(t == 'L') {
            if(!sl.empty()) {
                sr.push(sl.top());
                sl.pop();
            }
        }
        if(t == 'D') {
            if(!sr.empty()){
                sl.push(sr.top());
                sr.pop();
            }
        }
        if(t == 'B') {
            if(!sl.empty()) {
                sl.pop();
            }
        }
    }
    
    while(!sl.empty()) {
        sr.push(sl.top());
        sl.pop();
    }
    
    unsigned long t = sr.size();
    for(int i{}; i != t; i++) {
        cout << sr.top();
        sr.pop();
    }
        
    return 0;
}
