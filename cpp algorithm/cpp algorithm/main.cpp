#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n{};
    vector<int> v;
    string s;
    
    cin >> n;
    for(int i{}; i < n; i++) {
        cin >> s;
        if(s == "push") {
            int t;
            cin >> t;
            v.push_back(t);
        }
        if(s == "pop") {
            if(v.size()) {
                cout << v.front() << "\n";
                v.erase(v.begin());
            } else cout << -1 << "\n";
        }
        if(s == "size") {
            cout << v.size() << "\n";
        }
        if(s == "empty") {
            if(!v.size()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        if(s == "front") {
            if(!v.size()) cout << -1 << "\n";
            else cout << v.front() << "\n";
        }
        if(s == "back") {
            if(!v.size()) cout << -1 << "\n";
            else cout << v.back() << "\n";
        }
    }
    
    return 0;
}
