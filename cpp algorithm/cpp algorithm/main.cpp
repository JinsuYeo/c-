#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, K;
string s = "<";
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> K;
    
    queue<int> q;
    for (int i{1}; i < N+1; i++) {
        q.push(i);
    }
    
    while (!q.empty()) {
        for (int i{}; i < K-1; i++) {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        int temp = q.front();
        q.pop();
        if (!q.empty()) {
            s += to_string(temp)+ ", ";
        } else s += to_string(temp);
    }
    
    cout << s << ">";
    
    return 0;
}
