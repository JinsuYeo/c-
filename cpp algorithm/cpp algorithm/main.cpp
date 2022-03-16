#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100001;
const int MOD = 9901;

int T, result;
int arr[MAX][3];
int dp[MAX][3];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> T;
    
    for (int i{}; i < 3; i++)
        dp[1][i] = 1;
    
    for (int i{2}; i <= T; i++) {
        dp[i][0] = (((dp[i-1][1] + dp[i-1][2]) % MOD) + dp[i-1][0]) % MOD;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % MOD;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % MOD;
    }
    
    for (int i{}; i < 3; i++) {
        result = (((dp[T][1] + dp[T][2]) % MOD) + dp[T][0]) % MOD;
    }
    
    cout << result << '\n';
    
    return 0;
}
