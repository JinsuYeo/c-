#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

const int MAX {2002};

int N;
typedef struct{
    int x1;
    int x2;
    int y1;
    int y2;
} RECT;

typedef struct{
    int x;
    int y;
} DIR;
DIR dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

vector<RECT> rects;
bool arr[MAX][MAX]; // 직사각형 그릴 배열(-500 ~ 500)
bool visited[MAX][MAX];

int C;

void dfs(int x, int y){
    visited[y][x] = true;
    
    for (int i{}; i < 4; i++) {
        int nexty = y + dir[i].y;
        int nextx = x + dir[i].x;
        
        if (nexty < 0 || nexty >= MAX || nextx < 0 || nextx >= MAX) {
            continue;
        }
        if (!visited[nexty][nextx] && arr[nexty][nextx]) {
            dfs(nextx, nexty);
            visited[nexty][nextx] = true;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    for (int i{}; i < N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        RECT rect = {(x1 + 500)*2, (x2 + 500)*2, (y1 + 500)*2, (y2 + 500)*2};
        rects.push_back(rect);
    }
    
    for (int i{}; i < rects.size(); i++) {
        RECT rect = rects[i];
        memset(*(arr + rect.y1) + rect.x1, 1, rect.x2-rect.x1 + 1);
        memset(*(arr + rect.y2) + rect.x1, 1, rect.x2-rect.x1 + 1);
        for (int j{rect.y1}; j <= rect.y2; j++) {
            arr[j][rect.x1] = 1;
        }
        for (int j{rect.y1}; j <= rect.y2; j++) {
            arr[j][rect.x2] = 1;
        }
    }
    bool zero{false};
    for(int i{}; i < MAX; i++) {
        for (int j{}; j < MAX; j++) {
            if (arr[i][j] && !visited[i][j]) {
                C++;
                dfs(j, i);
            }
        }
    }
    if (arr[1000][1000]) {
        zero = true;
    }
    
    if (zero) {
        C--;
    }
    
    cout << C;
    
    return 0;
}
