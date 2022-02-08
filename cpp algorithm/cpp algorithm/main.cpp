#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector<int> have;
vector<int> check;

int n, m;
long long mid, high, low, result;

int main()
{
    cin >> n;
    for (int i{1}; i <= n; i++) {
        int t{};
        cin >> t;
        have.push_back(t);
    }
    cin >> m;
    for (int i{1}; i <= m; i++) {
        int t{};
        cin >> t;
        check.push_back(t);
    }
    
    sort(have.begin(), have.end());
    
    
    for (int i{}; i < check.size(); i++) {
        low = 0;
        high = n;
        bool flag = 0;
        while(low <= high) {
            int t = check[i];
            mid = (low + high) / 2;
            if (have[mid] == t) {
                flag = 1;
                break;
            }
            if (have[mid] < t) {
                low = mid + 1;
            }
            if (have[mid] > t) {
                high = mid - 1;
            }
        }
        if (flag) {
            cout << 1 << " ";
        } else cout << 0 << " ";
    }
    
        
    return 0;
}
