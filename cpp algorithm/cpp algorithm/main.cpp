#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n{}, t{};
    string s;
    cin >> n;
    
    vector<int> v;
    
    for(int i{}; i < n; i++) {
        cin >> s;
        if(s == "push") {
            cin >> t;
            v.push_back(t);
        }
        if(s == "top") {
            if(v.size()) {
                cout << v.back() << "\n";
            } else {
                cout << -1 << "\n";
            }
        }
        if(s == "size") cout << v.size() << "\n";
        if(s == "pop") {
            if(v.size() != 0) {
                cout << v.back() << "\n";
                v.pop_back();
            } else {
                cout << -1 <<"\n";
            }
        }
        if(s == "empty") {
            if(v.size()) {
                cout << 0 << "\n";
            } else cout << 1 << "\n";
        }
    }
    
    return 0;
}
