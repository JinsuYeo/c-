#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

int R, C;
string s;
bool visited[27];
int result;

typedef struct {
    int y;
    int x;
} DIR;
DIR dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int &&idx, int &&cnt){
    int y{idx/C};
    int x{idx%C};
    
    if (cnt > result) result = cnt;
    
    for (int i{}; i < 4; i++) {
        int nexty = y + dir[i].y;
        int nextx = x + dir[i].x;
        if (nextx < 0 || nextx >= C || nexty < 0 || nexty >= R) continue;
        if (!visited[s[nexty*C + nextx]-'A']) {
            visited[s[nexty*C + nextx]-'A'] = true;
            dfs(nexty*C + nextx, cnt+1);
            visited[s[nexty*C + nextx]-'A'] = false;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> R >> C;
    for (int i{}; i < R; i++) {
        string t;
        cin >> t;
        s += t;
    }
    
    visited[s[0]-'A'] = true;
    dfs(0, 1);
    
    cout << result << '\n';

    return 0;
}
