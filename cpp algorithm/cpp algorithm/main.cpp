#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1000001;
const int MOD = 1000000009;

int T, N, result;
int arr[1001][3];
int dp[1001][3];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> T;
    for (int i{1}; i <= T; i++) {
        for (int j{}; j < 3; j++) {
            cin >> arr[i][j];
        }
    }
    
    for (int i{}; i < 3; i++)
        dp[1][i] = arr[1][i];
    
    for (int i{2}; i <= T; i++) {
        for (int j{}; j < 3; j++) {
            if (j == 0) {
                dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + arr[i][0];
            }
            else if (j == 1) {
                dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + arr[i][1];
            }
            else if (j == 2) {
                dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + arr[i][2];
            }
        }
    }
    
    for (int i{}; i < 3; i++) {
        result = min(dp[T][0], min(dp[T][1], dp[T][2]));
    }
    
    cout << result << '\n';
    
    return 0;
}
