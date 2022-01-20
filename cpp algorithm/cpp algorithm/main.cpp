#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

long dp[5001], arr[5001];

int main(int argc, const char * argv[]) {
    string n{};
    cin >> n;
    
    if(n[0] == '0') {
        cout << 0 << endl;
        return 0;
    }
    
    for(int i{}; i < n.size(); i++) {
        arr[i+1] = long(n[i] - '0');
    }
    
    dp[0] = 1;
    dp[1] = 1;
    
    for(int i{2}; i <= n.size(); i++) {
        if(arr[i] != 0) dp[i] = dp[i-1];
        long tn = arr[i-1] * 10 + arr[i];
        if(tn >= 10 && tn <= 26) {
            dp[i] = (dp[i] + dp[i-2]) % 1000000;
        } else if(arr[i] == 0 && tn > 26){
            cout << 0 << endl;
            return 0;
        }
    }
        
    cout << dp[n.size()] << endl;
    
    return 0;
}
