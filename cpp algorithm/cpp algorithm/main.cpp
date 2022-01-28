#include <iostream>
#include <algorithm>
#include <list>
#include <string>

using namespace std;
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s;
    int n{};
    cin >> s >> n;

    list<char> l(s.begin(), s.end());
    auto now = l.end();
    
    for(int i{}; i < n; i++) {
        char t;
        cin >> t;
        if(t == 'P') {
            char c;
            cin >> c;
            l.insert(now, c);
        }
        if(t == 'B') {
            if(now != l.begin()) {
                now = l.erase(--now);
            }
        }
        if(t == 'D') {
            if(now != l.end()){
                now++;
            }
        }
        if(t == 'L') {
            if(now != l.begin()){
                now--;
            }
        }
    }
    
    for(auto c: l){
        cout << c;
    }
        
    return 0;
}
