#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct compare{
    bool operator() (const string& a, const string& b) const {
        if(a.length() == b.length()) return a < b;
        return a.length() < b.length();
    }
};

int N;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    
    vector<string> v(N);
    for (int i{}; i < N; i++) {
        cin >> v[i];
    }
     
    set<string, compare> s(v.begin(), v.end());
    
    for(auto str : s) {
        cout << str << '\n';
    }
    
    return 0;
}
