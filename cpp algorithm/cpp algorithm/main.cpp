#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

using namespace std;

vector<int> have;

int n, m, s;
long long mid, high, low, result;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for (int i{1}; i <= n; i++) {
        int t{};
        cin >> t;
        have.push_back(t);
    }
    
    sort(have.begin(), have.end());
    
    cin >> m;
    
    for (int i{}; i < m; i++) {
        int t{};
        cin >> t;
        cout << upper_bound(have.begin(), have.end(), t) - lower_bound(have.begin(), have.end(), t) << " ";
    }
    
        
    return 0;
}
