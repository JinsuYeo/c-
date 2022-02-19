#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;

const int MAX {1000001};

int F, S, G, U, D;

queue<pair<int, int>> q;
bool visited[MAX];

int bfs(int start){
    q.push(make_pair(start, 0));
    visited[start] = true;
    
    while (!q.empty()) {
        int cur = q.front().first;
        int count = q.front().second;
        q.pop();
        
        if (cur == G) {
            return count;
        }
        
        if (cur + U <= F && !visited[cur+U]) {
            q.push(make_pair(cur+U, count+1));
            visited[cur+U] = true;
        }
        if (cur - D >= 1 && !visited[cur-D]) {
            q.push(make_pair(cur-D, count+1));
            visited[cur-D] = true;
        }
    }
    
    return -1;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> F >> S >> G >> U >> D;
    
    int result = bfs(S);
    if (result != -1) cout << result << '\n';
    else cout << "use the stairs\n";
    
    return 0;
}
