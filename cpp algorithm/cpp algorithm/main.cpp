#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, S;
vector<int> v;
int cnt;

void dfs(int idx, int cur){
    if (cur == S && idx > -1) {
        cnt++;
    }
    
    for (int i{idx+1}; i < N; i++) {
        int next = cur + v.at(i);
        dfs(i, next);
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

    dfs(-1, 0);
    
    cout << cnt << '\n';
    
    return 0;
}
