#include <iostream>
#include <algorithm>

using namespace std;

int dp[100001], arr[100001];

int main(int argc, const char * argv[]) {
    int n{}, result{};
    cin >> n;
    for (int i {1}; i <= n; i++) {
        cin >> arr[i];
    }
    
    dp[1] = arr[1];
    result = arr[1];
    
    for(int i{2}; i <= n; i++) {
        if(dp[i-1] + arr[i] > arr[i]) {
            dp[i] = dp[i-1] + arr[i];
        } else {
            dp[i] = arr[i];
        }
    }
    
    for(int i{1}; i <= n; i++) {
        result = result < dp[i] ? dp[i] : result;
        
    }
    
    cout << result << endl;
    
    return 0;
}
