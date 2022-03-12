#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100001;
const int MOD = 1000000009;

int T, N;
int dp[MAX][4];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;
    for (int i{4}; i < MAX; i++) {
        dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % MOD;
        dp[i][2] = (dp[i-2][1] + dp[i-2][3]) % MOD;
        dp[i][3] = (dp[i-3][1] + dp[i-3][2]) % MOD;
    }
    
    cin >> T;
    for(int i{}; i < T; i++){
        cin >> N;
        cout << ((dp[N][1] + dp[N][2]) % MOD + dp[N][3]) % MOD << '\n';
    }
    
    return 0;
}
