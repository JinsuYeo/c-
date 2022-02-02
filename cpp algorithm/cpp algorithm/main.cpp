#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int visited[1001];
int v, e, c;
vector<int> arr[1001];

int connected(int node){
    if(visited[node]) return true;
    visited[node] = true;
    for(int i{}; i < arr[node].size(); i++) {
        int x = arr[node][i];
        connected(x);
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> v >> e;
    for(int i{}; i < e; i++) {
        int x, y;
        cin >> x >> y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    
    for(int i{1}; i <= v; i++) {
        int check = connected(i);
        if(!check) c++;
    }
    
    cout << c << "\n";
    
    return 0;
}
