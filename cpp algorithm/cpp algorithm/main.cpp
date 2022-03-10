#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 1001;

int N;
int arr[MAX];
int dp[MAX];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    for(int i{1}; i <= N; i++) {
        cin >> arr[i];
    }
    
    for(int i{1}; i <= N; i++) {
        dp[i] = arr[i];
        for (int j{1}; j < i; j++) {
            dp[i] = min(dp[i], arr[j] + dp[i-j]);
        }
    }
    
    cout << dp[N] << '\n';
    
    return 0;
}
