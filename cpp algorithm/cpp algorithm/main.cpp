#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001], arr[1001];

int main(int argc, const char * argv[]) {
    int n{}, max{1};
    cin >> n;
    for (int i {1}; i <= n; i++) {
        cin >> arr[i];
    }
    
    dp[1] = 1;
    for(int i {2}; i <= n; i++) {
        dp[i] = 1;
        for(int j{1}; j <= i-1; j++) {
            if(arr[j] < arr[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
        if(max < dp[i]) max = dp[i];
    }
    
    cout << max << endl;
    
    return 0;
}
