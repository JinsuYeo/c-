#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> v;

int n;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int sum{};
    
    cin >> n;
    for (int i{}; i < n ; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }
    
    sort(v.begin(), v.end());
    
    for (int i{0}; i < n; i++) {
        sum += v[i]*(n-i);
    }
    
    cout << sum;
    
    return 0;
}
