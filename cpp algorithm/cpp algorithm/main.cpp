#include <iostream>
#include <algorithm>

using namespace std;

int n, c;
long long house[200001];
long long mid, high, low, result;

int check(long long d) {
    int count{1};
    long long cur = house[1];
    for (int i{2}; i <= n; i++) {
        if (house[i] - cur >= d) {
            count++;
            cur = house[i];
        }
    }
    return count;
}

int main()
{
    cin >> n >> c;
    
    for (int i{1}; i <= n; i++)
        cin >> house[i];
    
    sort(house, house + n + 1);
    
    low = 1;
    high = house[n] - house[1];

    while (low <= high) {
        mid = (low + high) / 2;
        if(check(mid) >= c) {
            result = max(result, mid);
            low = mid + 1;
        } else high = mid - 1;
    }
    
    cout << result << "\n";
    
    return 0;
}
