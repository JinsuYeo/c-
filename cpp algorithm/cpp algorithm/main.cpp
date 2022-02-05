#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstdio>

using namespace std;

int n, m, c, result;
int arr[101][101];
int visited[101][101];
queue<pair<int, int>> q;

int checki[4] = {0, 0, -1, 1};
int checkj[4] = {-1, 1, 0, 0};

bool bfs(){
    long s = q.size();
    while(s) {
        int x, y;
        x = q.front().first;
        y = q.front().second;
        q.pop();
        s--;
        for(int i{}; i < 4; i++) {
            int ci = x + checki[i];
            int cj = y + checkj[i];
            
            if(ci >= 1 && ci <= n && cj >= 1 && cj <= m && !visited[ci][cj]) {
                if(ci == n && cj == m) {
                    c++;
                    return true;
                }
                if(arr[ci][cj] == 1) {
                    q.push(pair<int, int> {ci, cj});
                    visited[ci][cj] = 1;
                }
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    
    for(int i{1}; i <= n; i++) {
        for (int j{1}; j <= m; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }
    
    q.push(pair<int, int>{1, 1});
    visited[1][1] = 1;

    while(!q.empty()){
        int end {};
        c++;
        end = bfs();
        if(end) break;
    }
    
    cout << c <<"\n";
     
    return 0;
}
