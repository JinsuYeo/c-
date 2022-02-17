#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int N, M, K;

typedef struct{
    int x;
    int y;
} Dir;
Dir dir[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

string arr[100];
string target;
int visited[100][100][80];

int C;

int dfs(int &y, int &x, int c){
    int &result = visited[y][x][c]; // c는 target과 비교할 문자의 위치 의미함. ex) 1일 때는 target[1]과 비교. visited[y][x][c]는 만들고 있는 영단어의 c번째 위치가(index가 c일 때), arr의 (x, y)를 지나감을 의미. + 참조로 사용하지 않으면 시간초과 발생.
    
    if (result != -1) {
        return result; // 이미 경로를 방문했다면 0 or 1이 들어있을 테니 리턴 -> 길이가 같으면서 경로가 겹치는 문자열 존재할 수 없음. 따라서 이미 방문 했다면 visited[y][x][c]에는 0이 들어있을 것임.
    }
    
    if (c == target.length()) {
        return 1; // 방문하지 않았고, target과 같다면(반복문안의 조건문에서 target과 한글자씩 비교하며 같을 때만 dfs()해주고 있으므로 길이가 target과 같다면 target과 같음을 의미함). 따라서 1개 찾았음을 표시.
    }
    
    result = 0;
    
    for (int i{}; i < 4; i++) {
        int tempy = y;
        int tempx = x;
        for (int j{}; j < K; j++) { // 현재 좌표 기준으로 상 하 좌 우로 k번째 칸까지 비교.
            int nexty = tempy + dir[i].y;
            int nextx = tempx + dir[i].x;
            
            if (nexty < 0 || nexty >= N || nextx < 0 || nextx > M) {
                break;
            }
            
            if (arr[nexty][nextx] == target[c]) {
                result += dfs(nexty, nextx, c+1);
            }
            
            tempy = nexty;
            tempx = nextx;
        }
    }
    
    return result;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M >> K;
    for (int i{}; i < N; i++) {
        cin >> arr[i];
    }
    cin >> target;
    
    vector<pair<int, int>> start;
    
    for (int i{}; i < N; i++) {
        for (int j{}; j < M; j++) {
            if (arr[i][j] == target[0]) {
                start.push_back({i, j}); // arr에서 target의 첫번째 문자와 같은 문자의 좌표 찾아 start벡터에 넣어줌.
            }
        }
    }
    
    memset(visited, -1, sizeof(visited));
    
    for (int i{}; i < start.size(); i++) {
        int y = start[i].first;
        int x = start[i].second;
        C += dfs(y, x, 1);
    }
    
    cout << C << '\n';
    
    return 0;
}
