#include <iostream>

using namespace std;

long long dp[201][201];

int main(int argc, const char * argv[]) {
    int k{}, n{};
    cin >> n >> k;
    
    for(int i{}; i <= n; i++) {
        dp[1][i] = 1;
    }
    
    for(int i{1}; i <= k; i++) {
        dp[i][0] = 1;
    }
    
    for(int i{2}; i <= k; i++) {
        for(int j{1}; j <= n; j++) {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000000;
                dp[i][j] %= 1000000000;
            }
    }
    
    cout << dp[k][n] << endl;
    
    return 0;
}
