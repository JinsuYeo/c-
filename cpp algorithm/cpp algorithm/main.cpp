#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    queue<int> q;
    int n{}, t{};
    cin >> n >> t;
    vector<int> v;
    
    for (int i{1}; i <= n; i++) {
        q.push(i);
    }
    
    while(!q.empty()) {
        for(int i{}; i < t-1; i++) {
            int ti{};
            ti = q.front();
            q.pop();
            q.push(ti);
        }
        v.push_back(q.front());
        q.pop();
    }
    
    cout << "<";
    for(int i{}; i < n - 1; i++) {
        cout << v.at(i) << ", ";
    }
    cout << v.back() << ">" << "\n";
        
    return 0;
}
