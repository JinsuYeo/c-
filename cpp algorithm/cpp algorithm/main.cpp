#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
    
bool compare(string a, string b) {
    return a < b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s;
    vector<string> v;
    
    cin >> s;
    string t = s;
    for(int i{}; i < s.length(); i++) {
        v.push_back(t);
        if(s.size()){
            t.erase(t.begin());
        }
    }
    
    sort(v.begin(), v.end(), compare);
    
    for (int i{}; i < v.size(); i++) {
        cout << v.at(i) << "\n";
    }
    
    return 0;
}
