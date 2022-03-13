#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1001;

int T, M, idx;
vector<int> V;
vector<pair<int, vector<int>>> dp(MAX);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> T;
    vector<int> arr(T+1);
    for (int i{1}; i <= T; i++)
        cin >> arr[i];
    
    
    dp[1] = {1,{arr[1]}};
    M = 1;
    V = {arr[1]};
    for (int i{1}; i < T+1; i++) {
        int result{};
        vector<int> temp;
        for (int j{1}; j < i; j++) {
            if (arr[i] > arr[j]) {
                result = max(result, dp[j].first + 1);
                if(result == dp[j].first + 1) {
                    temp = dp[j].second;
                    temp.push_back(arr[i]);
                }
            }
        }
        if (!result) {
            dp[i] = {1,{arr[i]}};
        } else {
            dp[i] = {result, temp};
        }
        if(result >= M) {
            M = result;
            V = temp;
        }
    }
    
    cout << M << '\n';
    for (auto e: V) {
        cout << e << " ";
    }
    
    return 0;
}
