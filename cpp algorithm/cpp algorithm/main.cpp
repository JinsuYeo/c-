#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int n, m, c, nc;
int arr[1001][1001];
int visited[1001][1001];
queue<pair<int, int>> q;

int checki[4] = {0, 0, -1, 1};
int checkj[4] = {-1, 1, 0, 0};

void bfs(){
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
            
            if(ci >= 1 && ci <= n && cj >= 1 && cj <= m) {
                if(arr[ci][cj] == 0) {
                    q.push(pair<int, int> {ci, cj});
                    arr[ci][cj] = 1;
                    nc--;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> m >> n;
    
    for(int i{1}; i <= n; i++) {
        for (int j{1}; j <= m; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1) q.push(pair<int, int>{i, j});
            if(arr[i][j] == 0) nc++;
        }
    }
    
    while(!q.empty()){
        c++;
        bfs();
    }
    c--;
    
    if(!nc) cout << c <<"\n";
    else cout << -1 << "\n";
    
    return 0;
}
