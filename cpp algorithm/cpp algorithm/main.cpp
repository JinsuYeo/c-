#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1000001;
const int MOD = 1000000009;

int T, N;
int dp[MAX];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i{4}; i < MAX; i++) {
        dp[i] = (((dp[i-3] + dp[i-2]) % MOD) + dp[i-1]) % MOD;
    }
    
    cin >> T;
    for (int i{}; i < T; i++) {
        cin >> N;
        cout << dp[N] << '\n';
    }
    
    return 0;
}
