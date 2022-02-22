#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef struct {
    int x;
    int y;
} COORD;

COORD dir[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

int N, M, C{1 << 30};
int arr[101][101];
bool visited[101][101];
//priority_queue<pair<int, COORD>> q;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

void bfs(){
    q.push(make_pair(0, make_pair(1, 1)));
    visited[1][1] = true;
    while (!q.empty()) {
        int x = q.top().second.first;
        int y = q.top().second.second;
        int count = q.top().first;
        q.pop();
  
        if (y == N && x == M) {
            C = count;
            return;
        }
        
        for (int i{}; i < 4; i++) {
            int nextx = x + dir[i].x;
            int nexty = y + dir[i].y;
            
            if (nextx < 1 || nextx > M || nexty < 1 || nexty > N) continue;
            if (!visited[nexty][nextx] && arr[nexty][nextx] == 0) {
                q.push(make_pair(count, make_pair(nextx, nexty)));
                visited[nexty][nextx] = true;
                continue;
            }
            if (!visited[nexty][nextx] && arr[nexty][nextx] == 1) {
                q.push(make_pair(count+1, make_pair(nextx, nexty)));
                visited[nexty][nextx] = true;
            }
        }
    }
}

int main(void) {
    cin >> M >> N;

    for (int i{1}; i <= N; i++) {
        for (int j{1}; j <= M; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }
    
    bfs();
    
    cout << C << '\n';
    
    return 0;
}
