#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> a;
vector<int> b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    for (int i{}; i < n; i++) {
        int t{};
        cin >> t;
        a.push_back(t);
    }
    for (int i{}; i < m; i++) {
        int t{};
        cin >> t;
        b.push_back(t);
    }
    
    copy(a.begin(), a.end(), back_inserter(b));
    sort(b.begin(), b.end());
    
    for (auto e: b)
        cout << e << " ";
    
    return 0;
}
