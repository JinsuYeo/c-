#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001], arr[1001];

int main(int argc, const char * argv[]) {
    int n{}, max{};
    cin >> n;
    for (int i {1}; i <= n; i++) {
        cin >> arr[i];
    }
    
    dp[1] = arr[1];
    max = dp[1];
    for(int i {2}; i <= n; i++) {
        dp[i] = arr[i];
        for(int j{1}; j <= i-1; j++) {
            if(arr[j] < arr[i] && dp[i] < dp[j] + arr[i]) {
                dp[i] = dp[j] + arr[i];
            }
        }
        if(max < dp[i]) max = dp[i];
    }
    
    cout << max << endl;
    
    return 0;
}
