#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[9][9];
bool row[9][10];
bool col[9][10];
bool small[9][10];

int change(int x, int y){
    return (y/3)*3 + x/3;
}

void dfs(int c){
    int y{c/9};
    int x{c%9};
    
    if (c == 81) {
        for (int i{}; i < 9; i++) {
            for (int j{}; j < 9; j++) {
                cout << arr[i][j] << " ";
            }
            cout << '\n';
        }
        exit(0);
    }
    
    if (arr[y][x]) {
        dfs(c+1);
    } else {
        for (int k{1}; k <= 9; k++) {
            if(!row[y][k] && !col[x][k] && !small[change(x, y)][k]){
                arr[y][x] = k;
                row[y][k] = true;
                col[x][k] = true;
                small[change(x, y)][k] = true;
                dfs(c+1);
                arr[y][x] = 0;
                row[y][k] = false;
                col[x][k] = false;
                small[change(x, y)][k] = false;
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    for (int i{}; i < 9; i++) {
        for (int j{}; j < 9; j++) {
            cin >> arr[i][j];
            if (arr[i][j]) {
                row[i][arr[i][j]] = true;
                col[j][arr[i][j]] = true;
                small[change(j, i)][arr[i][j]] = true;
            }
        }
    }
    
    dfs(0);

    return 0;
}
