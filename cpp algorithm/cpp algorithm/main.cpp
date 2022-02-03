#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

char visited[1001];
int v, e, n, c;
int p[1001];
vector<int> arr[1001];

void clear() {
    for(int i{0}; i < 1001; i++) {
        visited[i] = 0;
        arr[i].clear();
        c = 0;
    }
}

void dfs(int start) {
    if(visited[start] != 0)
        return;
    
    visited[start] = true;
    
    for(int i{}; i < arr[start].size(); i++) {
        int x = arr[start][i];
        if(!visited[x])
            dfs(x);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    clear();
    cin >> n;
    
    for(int i{}; i < n; i++) {
        cin >> v;
        e = v;
        for(int j{1}; j <= e; j++) {
            cin >> p[j];
        }
        for(int j{1}; p[j] != 0; j++) {
            arr[j].push_back(p[j]);
            arr[p[j]].push_back(j);
        }
        for(int j{1}; j <= v; j++) {
            if(!visited[j]){
                dfs(j);
                c++;
            }
        }
        cout << c << "\n";
        clear();
    }
    
    
    return 0;
}
