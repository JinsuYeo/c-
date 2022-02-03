#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

char color[20001];
int v, e, n;
char cur;
string bi {"YES"};
vector<int> arr[20001];

void clear() {
    for(int i{0}; i <= 20000; i++) {
        color[i] = 0;
        arr[i].clear();
    }
    bi = "YES";
}

void dfs(int start, char col) {
    if(color[start] != 0)
        return;
    
    color[start] = col;
    
    if (col == 'r') {
        col = 'b';
    } else {
        col = 'r';
    }
    
    for(int i{}; i < arr[start].size(); i++) {
        int x = arr[start][i];
        if(color[x] != 0 && color[x] == color[start]){
            bi = "NO";
            break;
        } else if(color[x] == 0){
            dfs(x, col);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    clear();
    cin >> n;
    
    for(int i{}; i < n; i++) {
        cin >> v >> e;
        for(int j{}; j < e; j++) {
            int x, y;
            cin >> x >> y;
            arr[x].push_back(y);
            arr[y].push_back(x);
        }
        for(int j{1}; j <= v; j++) {
            if(!color[j] && !arr[j].empty()){
                dfs(j, 'r');
            }
                
        }
        cout << bi << "\n";
        clear();
    }
    
    
    return 0;
}
