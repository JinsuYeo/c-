#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int n, c;
int arr[26][26];
bool visited[26][26];
vector<int> cv;

void dfs(int i, int j){
    visited[i][j] = 1;
    c++;
    if(j > 1 && arr[i][j-1] == 1 && !visited[i][j-1]) dfs(i, j-1);
    if(j < n && arr[i][j+1] == 1 && !visited[i][j+1]) dfs(i, j+1);
    if(i > 1 && arr[i-1][j] == 1 && !visited[i-1][j]) dfs(i-1, j);
    if(i < n && arr[i+1][j] == 1 && !visited[i+1][j]) dfs(i+1, j);
}

int main() {
    cin >> n;
    for(int i{1}; i <= n; i++) {
        for(int j{1}; j <= n; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }
    
    for(int i{1}; i <= n; i++) {
        for(int j{1}; j <= n; j++) {
            if(!visited[i][j] && arr[i][j] == 1) {
                dfs(i, j);
                cv.push_back(c);
                c = 0;
            }
        }
    }
    
    sort(cv.begin(), cv.end());
    
    cout << cv.size() << "\n";
    for(int i{}; i < cv.size(); i++) {
        cout << cv.at(i) << "\n";
    }
   
    return 0;
}
