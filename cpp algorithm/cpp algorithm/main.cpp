#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int K;
vector<int> S;
vector<int> result;


void dfs(int idx, int size){
    if (size == 6) {
        for (int i{}; i < 6; i++) {
            cout << result.at(i) << " ";
        }
        cout << '\n';
        return;
    }
    
    for (int i{idx}; i < K; i++) {
        result.push_back(S.at(i));
        dfs(i+1, size+1);
        result.pop_back();
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while (cin >> K) {
        for (int i{}; i < K; i++) {
            int t{};
            cin >> t;
            S.push_back(t);
        }
        dfs(0, 0);
        cout << '\n';
        S.clear();
        result.clear();
    }

    return 0;
}
