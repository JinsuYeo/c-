#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, c;
priority_queue<int> q;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for (int i{}; i < n; i++) {
        int t{};
        cin >> t;
        q.push(t);
    }
    
    while (!q.empty()) {
        c += m/q.top();
        m %= q.top();
        q.pop();
    }
    
    cout << c;
    
    return 0;
}
