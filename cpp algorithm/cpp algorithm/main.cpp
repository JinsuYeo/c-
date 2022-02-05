#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n, c;
int arr[51][51];
bool visited[51][51];
vector<int> cv;

void dfs(int i, int j){
    visited[i][j] = 1;
    
    if(j > 1 && arr[i][j-1] == 1 && !visited[i][j-1]) dfs(i, j-1);
    if(j < n && arr[i][j+1] == 1 && !visited[i][j+1]) dfs(i, j+1);
    if(i > 1 && arr[i-1][j] == 1 && !visited[i-1][j]) dfs(i-1, j);
    if(i < n && arr[i+1][j] == 1 && !visited[i+1][j]) dfs(i+1, j);
    if(i > 1 && j > 1 && arr[i-1][j-1] == 1 && !visited[i-1][j-1]) dfs(i-1, j-1);
    if(i > 1 && j < n && arr[i-1][j+1] == 1 && !visited[i-1][j+1]) dfs(i-1, j+1);
    if(i < n && j > 1 && arr[i+1][j-1] == 1 && !visited[i+1][j-1]) dfs(i+1, j-1);
    if(i < n && j < n && arr[i+1][j+1] == 1 && !visited[i+1][j+1]) dfs(i+1, j+1);
}

int main() {
    n = 51;
    c = 0;
    
    int x, y;
    cin >> x >> y;
    while (!(x == 0 && y == 0)) {
        for(int i{1}; i <= y; i++) {
            for(int j{1}; j <= x; j++) {
                cin >> arr[i][j];
            }
        }
        
        for(int i{1}; i <= y; i++) {
            for(int j{1}; j <= x; j++) {
                if(!visited[i][j] && arr[i][j] == 1) {
                    c++;
                    dfs(i, j);
                }
            }
        }
    
        cout << c << "\n";
        
        c = 0;
        memset(visited, false, sizeof(visited));
        memset(arr, false, sizeof(arr));
        
        cin >> x >> y;
    }
    
    return 0;
}
