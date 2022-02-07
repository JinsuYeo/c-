#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int t;
long long n, result;
long long arr[100001];
bool visited[100001];
vector<pair<int, int>> vec[100001];

void dfs(int start) {
    visited[start] = 1;
    
    for (int i{}; i < vec[start].size(); i++) {
        int x = vec[start][i].first;
        int len = vec[start][i].second;
        if(!visited[x]) {
            arr[x] = arr[start] + len;
            if (arr[x] > result) {
                result = arr[x];
                t = x;
            }
            dfs(x);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i{}; i < n-1; i++) {
        int a, b{}, c;
        cin >> a;
        cin >> b;
        while(b != -1) {
            cin >> c;
            vec[a].push_back(make_pair(b, c));
            vec[b].push_back(make_pair(a, c));
            cin >> b;
        }
    }
    

    dfs(1);
    memset(arr, 0, sizeof(arr));
    memset(visited, false, sizeof(visited));
    dfs(t);
    
    cout << result;
    
    return 0;
}
