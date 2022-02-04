#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

using namespace std;

int c, n, counter, start;
array<int, 100001> visited;
array<int, 100001> g;
array<int, 100001> done;

void clear(){
    for(int i{1}; i <= n; i++) {
        visited[i] = 0;
        done[i] = 0;
        g[i] = 0;
        counter = 0;
    }
}

void dfs(int x){
    visited[x] = 1;
    
    int y = g[x];
    
    if(!visited[y]) dfs(y);
    else if (!done[y]) {
        for(int i{y}; i != x; i = g[i])
            counter++;
        counter++;
    }
    
    done[x] = 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> c;
    for(int i{1}; i <= c; i++) {
        cin >> n;
        counter = 0;
        for(int j{1}; j <= n; j++) {
            cin >> g[j];
        }
        
        for(int j{1}; j <= n; j++) {
            if(!visited[j])
                dfs(j);
        }
        cout << n - counter << "\n";
        clear();
    }
    
   
    return 0;
}
