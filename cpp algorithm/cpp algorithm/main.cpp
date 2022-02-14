#include <iostream>
#include <algorithm>
#include <array>
#include <vector>

using namespace std;

vector<int> v;
bool visited[11];
array<array<int, 11>, 11> arr;

int N, result{1 << 30}, min_v{}, des;

void dfs(int start, int cost, int n) {
    visited[start] = true;
    min_v += cost;
    if (n == N) {
        if (arr[start][des] != 0) {
            result = min(result, min_v + arr[start][des]);
        }
        return;
    }
    
    for (int i{}; i < N; i++) {
        if(!arr[start][i]) continue;
            
        if (!visited[i]) {
            dfs(i, arr[start][i], n+1);
            visited[i] = false;
            min_v -= arr[start][i];
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    for (int i{}; i < N; i++) {
        for (int j{}; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    
    for (int i{}; i < N; i++) {
        des = i;
        dfs(i, 0, 1);
        visited[i] = false;
    }
    
    cout << result << '\n';
    
    return 0;
}
