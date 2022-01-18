#include <iostream>
#include <algorithm>

using namespace std;

int dp[100001];

int main(int argc, const char * argv[]) {
    int n{};
    cin >> n;
   
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    
    for(int i{2}; i <= n; i++){
        dp[i] = dp[i-1] + 1;
        for(int j{1}; j*j <= i; j++){
            dp[i] = min(dp[i], dp[i-(j*j)] + 1);
        }
    }
    
    cout << dp[n] << endl;
    
    return 0;
}
