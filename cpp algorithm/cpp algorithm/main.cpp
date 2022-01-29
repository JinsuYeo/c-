#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
   
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a{}, b{};
    cin >> a >> b;
    
    vector<int> v;
    
    while(a/b) {
        v.push_back(a%b);
        a /= b;
    }
    v.push_back(a%b);
    
    reverse(v.begin(), v.end());
    
    for(int i{}; i < v.size(); i++) {
        if(v.at(i) < 10) {
            cout << v.at(i);
        } else {
            cout << char(v.at(i)+'A'-10);
        }
    }
    cout << "\n";
    
    return 0;
}
