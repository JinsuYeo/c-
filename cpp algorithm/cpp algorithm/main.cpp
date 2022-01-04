#include <iostream>
#include <algorithm>

using namespace std;

long long dp[91][2]{};

int main(int argc, const char * argv[]) {
    int n{};
    cin >> n;
    
    dp[1][1] = 1;
    
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < 2; j++) {
            if(j == 0) {
                dp[i][j] = dp[i-1][0] + dp[i-1][1];
            }
            if(j == 1) {
                dp[i][j] = dp[i-1][0];
            }
        }
    }
    
    cout << dp[n][0] + dp[n][1] << endl;
    
    return 0;
}
