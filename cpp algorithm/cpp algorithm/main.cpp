#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

set<int> have;
vector<int> check;

int n, m;
long long mid, high, low, result;

int main()
{
    cin >> n;
    for (int i{1}; i <= n; i++) {
        int t{};
        cin >> t;
        have.insert(t);
    }
    cin >> m;
    for (int i{1}; i <= m; i++) {
        int t{};
        cin >> t;
        check.push_back(t);
    }
    
    for(int i{}; i < check.size(); i++) {
        auto it = have.find(check.at(i));
        if (it != have.end()) {
            cout << 1 << " ";
        } else cout << 0 << " ";
    }
        
    return 0;
}
