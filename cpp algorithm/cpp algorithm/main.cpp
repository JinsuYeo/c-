#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int N, x, y;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    vector<pair<int, int>> v(N);
    
    for (int i{}; i < N; i++) {
        cin >> x >> y;
        pair<int, int> p = make_pair(x, y);
        v[i] = p;
    }
    
    sort(v.begin(), v.end(), compare);
    
    for (auto el : v){
        cout << el.first << " " << el.second << '\n';
    }
    
    return 0;
}
