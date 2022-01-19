#include <iostream>
#include <algorithm>

using namespace std;

long dp[101];

int main(int argc, const char * argv[]) {
    int n{}, cn{};
    cin >> n;
    
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    
    for(int i{}; i < n; i++) {
        cin >> cn;
        for(int j{4}; j <= cn; j++) {
            dp[j] = dp[j-2] + dp[j-3];
        }
        cout << dp[cn] << endl;
    }
    //18분, O(n^2)
   
    return 0;
}
