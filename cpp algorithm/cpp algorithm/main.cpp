#include <iostream>
#include <algorithm>

using namespace std;

int dp[31];

int main(int argc, const char * argv[]) {
    int n{};
    cin >> n;
   
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;
    for(int i{3}; i <= n; i++) {
        dp[i] = dp[i-2]*3;
        for (int j{4}; j <= i; j+=2) {
            dp[i] += dp[i-j]*2;
        }
    }

    cout << dp[n] << endl;
    
    return 0;
}
