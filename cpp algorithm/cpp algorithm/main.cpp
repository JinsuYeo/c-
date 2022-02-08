#include<iostream>
using namespace std;

int n, m;
long long tree[1000001];
long long  maxi;
long long mid, high, low, result;

int main()
{
    cin >> n >> m;
    
    for (int i{1}; i <= n; i++)
    {
        cin >> tree[i];
        if (maxi < tree[i]) maxi = tree[i];
    }
    low = 1;
    high = maxi;

    while (low <= high) {
        long long sum{};
        mid = (low + high) / 2;
        for (int i{1}; i <= n; i++) {
            if(tree[i] > mid) sum += tree[i] - mid;
            else continue;
        }
        if(sum >= m) {
            low = mid + 1;
            if(result < mid) result = mid;
        } else high = mid - 1;
    }
    
    cout << result << "\n";
    
    return 0;
}
