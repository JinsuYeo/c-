#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int n, c, result;
int arr[101][101];
int visited[101][101];
queue<pair<int, int>> isIsland;
queue<pair<int, int>> isCoast;

int checki[4] = {0, 0, -1, 1};
int checkj[4] = {-1, 1, 0, 0};

void ibfs(){
    long s = isIsland.size();
    while(s) {
        int x, y;
        x = isIsland.front().first;
        y = isIsland.front().second;
        isIsland.pop();
        s--;
        for(int i{}; i < 4; i++) {
            int ci = x + checki[i];
            int cj = y + checkj[i];
            
            if(ci >= 1 && ci <= n && cj >= 1 && cj <= n && !visited[ci][cj]) {
                if(arr[ci][cj] == 1) {
                    isIsland.push(pair<int, int> {ci, cj});
                    visited[ci][cj] = 1;
                }
                if (arr[ci][cj] == 0) {
                    isCoast.push(pair<int, int> {x, y});
                }
            }
        }
    }
}

void cbfs(){
    long s = isCoast.size();
    while(s) {
        int x, y;
        x = isCoast.front().first;
        y = isCoast.front().second;
        isCoast.pop();
        s--;
        for(int i{}; i < 4; i++) {
            int ci = x + checki[i];
            int cj = y + checkj[i];
            
            if(ci >= 1 && ci <= n && cj >= 1 && cj <= n && !visited[ci][cj]) {
                if(arr[ci][cj] == 0) {
                    isCoast.push(pair<int, int> {ci, cj});
                    visited[ci][cj] = 1;
                }
                if(arr[ci][cj] == 1) {
                    if(c < result || result == 0) result = c;
                }
            }
        }
    }
}



int main() {
    cin >> n;
    
    for(int i{1}; i <= n; i++) {
        for (int j{1}; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i{1}; i <= n; i++) {
        for (int j{1}; j <= n; j++) {
            if(!visited[i][j] && arr[i][j] == 1) {
                visited[i][j] = 1;
                isIsland.push(pair<int, int>{i, j});
                while(!isIsland.empty()){
                    ibfs();
                }
                while (!isCoast.empty()) {
                    c++;
                    cbfs();
                }
                c = 0;
                memset(visited, false, sizeof(visited));
            }
        }
    }
    
    cout << result - 1 <<"\n";
     
    return 0;
}
