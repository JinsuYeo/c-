#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int dc[1001];
int bc[1001];
int v;
int matrix[1001][1001];

vector<int> arr[1001];

void dfs(int x) {
    if(dc[x]) return;
    dc[x] = true;
    cout << x << " ";
    for(int i{1}; i <= v; i++) {
        if(matrix[x][i] && !dc[i]) {
            dfs(i);
        }
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    bc[start] = true;
    
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << " ";
        for (int i{1}; i <= v; i++) {
            if(matrix[x][i] && !bc[i]) {
                bc[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int s{}, e{};
    
    cin >> v >> e >> s;
    for(int i{}; i < e; i++) {
        int x, y;
        cin >> x >> y;
        matrix[x][y] = 1;
        matrix[y][x] = 1;
    }
    
    dfs(s);
    cout << "\n";
    bfs(s);
    
    return 0;
}
