#include <iostream>
#include <algorithm>

using namespace std;

int dp[2][100001], arr[2][100001];

int main(int argc, const char * argv[]) {
    int n{}, cn{};
    
    cin >> n;
    for(int i {}; i < n; i++) {
        cin >> cn;
        for (int j{}; j < 2; j++) {
            for(int k{}; k < cn; k++) {
                cin >> arr[j][k];
            }
        }
        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];
        dp[0][1] = arr[1][0] + arr[0][1];
        dp[1][1] = arr[0][0] + arr[1][1];
        
        for (int j{2}; j < cn; j++) {
            for(int k{}; k < 2; k++) {
                if(!k) {
                    dp[0][j] = arr[0][j] + max(dp[1][j-1], dp[1][j-2]);
                } else {
                    dp[1][j] = arr[1][j] + max(dp[0][j-1], dp[0][j-2]);
                }
            }
        }
        cout << max(dp[0][cn-1],dp[1][cn-1]) << endl;
    }
    
    return 0;
}
