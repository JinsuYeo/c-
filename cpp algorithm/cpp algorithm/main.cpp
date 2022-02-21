#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> v;
int cnt;

void dfs(int idx, int cur){
    if (cur == M && idx > -1) {
        cnt++;
    }
    
    if (idx + 1 >= N || cur > M) {
        return;
    }
    
    if (idx == -1) {
        for (int i{idx+1}; i < N; i++) {
            int next = cur + v.at(i);
            dfs(i, next);
        }
    } else {
        int next = cur + v.at(idx+1);
        dfs(idx+1, next);
    }
    
    return;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    for (int i{}; i < N; i++) {
        int t{};
        cin >> t;
        v.push_back(t);
    }

    dfs(-1, 0);
    
    cout << cnt << '\n';
    
    return 0;
}
