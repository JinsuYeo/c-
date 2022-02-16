#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <map>

using namespace std;

const int target {123456789};

int diry[4] = {-1, 0, 1, 0}; // 상, 좌, 하, 우
int dirx[4] = {0, -1, 0, 1};

int X, Y; // 0의 위치
queue<int> q;
map<int, int> visited;

void bfs(){
    while (!q.empty()) {
        int num = q.front();
        string s = to_string(num);
        int index = (int)s.find('9');
        q.pop();

        if (num == target) {
            return;
        }
        
        int y = index / 3;
        int x = index % 3;
        
        for (int i{}; i < 4; i++) {
            int tx = x + dirx[i];
            int ty = y + diry[i];
            
            if (tx >= 0 && tx < 3 && ty >= 0 && ty < 3) {
                string ts = s;
                swap(ts.at(y*3+x), ts.at(ty*3+tx));
                
                int next = stoi(ts);
                if (!visited.count(next)) {
                    q.push(next);
                    visited[next] = visited[num] + 1;
                }
            }
        }
        
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        
    int start{};
    
    for(int i{}; i < 3; i++) {
        for (int j{}; j < 3; j++) {
            int t{};
            cin >> t;
            if (t == 0) {
                t = 9;
            }
            start = start*10 + t;
        }
    }
    
    q.push(start);
    visited[start] = 0;
    
    bfs();
    
    if (!visited.count(target)) {
        cout << -1 << '\n';
    } else cout << visited[target] << '\n';
        
    return 0;
}
