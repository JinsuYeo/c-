#include <iostream>
#include <algorithm>

using namespace std;

long dp[1001], arr[5001];

int main(int argc, const char * argv[]) {
    int n{};
    cin >> n;
    
    for(int i{1}; i <= n; i++) {
        cin >> arr[i];
    }
    
    dp[1] = arr[1];
    
    for(int i{2}; i <= n; i++) {
        dp[i] = arr[i];
        for(int j{1}; j <= i; j++) {
            dp[i] = max(dp[i], dp[i-j] + arr[j]);
        }
    }
    
    cout << dp[n] << endl;
    
    return 0;
}
