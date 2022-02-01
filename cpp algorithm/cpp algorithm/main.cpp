#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int dc[1001];
int bc[1001];
int v;
vector<int> arr[1001];

void dfs(int x) {
    if(dc[x]) return;
    dc[x] = true;
    cout << x << " ";
    for(int i{}; i < arr[x].size(); i++) {
        int y = arr[x][i];
        dfs(y);
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
        for (int i{}; i < arr[x].size(); i++) {
            int y = arr[x][i];
            if(!bc[y]) {
                bc[y] = true;
                q.push(y);
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
        arr[x].push_back(y);
        arr[y].push_back(x);
        sort(arr[x].begin(), arr[x].end());
        sort(arr[y].begin(), arr[y].end());
    }
    
    dfs(s);
    cout << "\n";
    bfs(s);
    
    return 0;
}
