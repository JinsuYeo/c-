#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 10000;

int T, N, M;
bool prime[MAX];
vector<int> v;
bool visited[MAX];
queue<pair<int, int>> q;

int bfs(){
    q.push(make_pair(N, 0));
    visited[N] = true;
    
    while (!q.empty()) {
        int x = q.front().first;
        string s = to_string(x);
        int c = q.front().second;
        q.pop();
        
        if (x == M) {
            return c;
        }
        
        for (auto &i: v) {
            string t = to_string(i);
            int same{};
            for (int j{}; j < t.length(); j++) {
                if(t.at(j) == s.at(j)) same++;
            }
            if (same == 3 && !visited[i]) {
                q.push(make_pair(i, c+1));
                visited[i] = true;
            }
        }
    }

    return 0;
}

int main(void) {
    cin >> T;
    
    memset(prime, true, sizeof(prime));
    for (int i{2}; i < MAX; i++) {
        if (prime[i] == false) continue;
        for (int j{i+i}; j < MAX; j+=i) {
            prime[j] = false;
        }
    }
    
    for (int i{1000}; i < MAX; i++) {
        if (prime[i]) {
            v.push_back(i);
        }
    }
    
    for(int i{}; i < T; i++) {
        while (!q.empty()) {
            q.pop();
        }
        memset(visited, false, sizeof(visited));
        
        cin >> N >> M;
        
        if (N == M) {
            cout << 0 << '\n';
            continue;
        }
        
        cout << bfs() << '\n';
    }
        
    return 0;
}
