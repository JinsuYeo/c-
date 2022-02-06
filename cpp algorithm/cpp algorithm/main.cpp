#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int arr[100001];
bool visited[100001];
vector<int> vec[100001];
queue<int> q;

void bfs(int start) {
    visited[start] = 1;
    for (int i{}; i < vec[start].size(); i++) {
        q.push(vec[start][i]);
        arr[vec[start][i]] = start;
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        visited[x] = 1;
        for (int i{}; i < vec[x].size(); i++) {
            if(!visited[vec[x][i]]){
                q.push(vec[x][i]);
                arr[vec[x][i]] = x;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(int i{}; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    
    bfs(1);
    
    for (int i{2}; i <= n; i++) {
        cout << arr[i] << "\n";
    }
    
    return 0;
}
