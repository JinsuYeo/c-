#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 10000;

int T, N, M;
bool visited[MAX];
queue<pair<int, string>> q;

string bfs(){
    q.push(make_pair(N, ""));
    visited[N] = true;
    
    while (!q.empty()) {
        int x = q.front().first;
        string result = q.front().second;
        q.pop();
        
        if (x == M) {
            return result;
        }
        
        if (!visited[(x*2)%10000]) {
            q.push(make_pair((x*2)%10000, result+"D"));
            visited[(x*2)%10000] = true;
        }
        
        if (!visited[x == 0 ? 9999 : x-1]) {
            q.push(make_pair(x == 0 ? 9999 : x-1, result+"S"));
            visited[x == 0 ? 9999 : x-1] = true;
        }
        
        int temp{};
        temp = (x%1000)*10;
        temp += x/1000;
        
        if (!visited[temp]) {
            q.push(make_pair(temp, result+"L"));
            visited[temp] = true;
        }
        
        temp = x/10;
        temp += (x%10)*1000;
        if (!visited[temp]) {
            q.push(make_pair(temp, result+"R"));
            visited[temp] = true;
        }
    }

    return 0;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> T;
    
    for(int i{}; i < T; i++) {
        while (!q.empty()) {
            q.pop();
        }
        memset(visited, false, sizeof(visited));
        
        cin >> N >> M;
        
        if (N == M) {
            cout << "" << '\n';
            continue;
        }
        
        cout << bfs() << '\n';
    }
        
    return 0;
}
