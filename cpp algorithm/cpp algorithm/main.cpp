#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int S;
vector<int> v;
int result{1 << 30};

void dfs(int low, int high, int sum){
    while (low <= high && high < N) {
        if (sum < S) {
            sum += v[++high];
        } else if(sum == S) {
            result = min(result, high - low + 1);
            sum += v[++high];
        } else if(sum > S) {
            result = min(result, high - low + 1);
            sum -= v[low++];
//            if (low > high && low < N) {
//                high = low;
//                sum = v[low];
//            }
        }
    }
    
    return;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> S;
    for (int i{}; i < N; i++) {
        int t{};
        cin >> t;
        v.push_back(t);
    }

    dfs(0, 0, v[0]);
    
    if(result == 1 << 30) cout << 0 << '\n';
    else cout << result << '\n';
    
    return 0;
}
