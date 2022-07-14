#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int N, M;
unordered_map<int, int> A;
vector<int> B;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    for (int i{}; i < N; i++) {
        int t{};
        cin >> t;
        A.insert(make_pair(t, t));
    }
    
    cin >> M;
    for (int i{}; i < M; i++) {
        int t{};
        cin >> t;
        B.push_back(t);
    }
    
    for (auto b: B) {
        if(A[b]) cout << 1 << " ";
        else cout << 0 << " ";
    }
    
    return 0;
}
