#include <iostream>
#include <algorithm>
#include <array>
#include <queue>

using namespace std;

const int MAX = 100001;

int N, K;
bool subin[MAX];

int bfs(){
    queue<pair<int, int>> q;

    subin[N] = true;
    q.push(make_pair(N, 0));
    
    while (!q.empty()) {
        int x = q.front().first;
        int c = q.front().second;
        q.pop();
        
        if (x == K)
            return c;

        
        if (x+1 < MAX && !subin[x+1]) {
            q.push(make_pair(x+1, c+1));
            subin[x+1] = true;
        }
        if (x-1 >= 0 && !subin[x-1]) {
            q.push(make_pair(x-1, c+1));
            subin[x-1] = true;
        }
        if (x*2 < MAX && !subin[x*2]) {
            q.push(make_pair(x*2, c+1));
            subin[x*2] = true;
        }
    }
    return 0;
}

int main(void) {
    cin >> N >> K;
    
    cout << bfs() << "\n";
    
    return 0;
}
