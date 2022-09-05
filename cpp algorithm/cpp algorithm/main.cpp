#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    cin >> N;
    vector<int> v1(N);
    for (int i{}; i < N; i++) {
        cin >> v1[i];
    }
    sort(v1.begin(), v1.end());
    
    cin >> M;
    vector<int> v2(M);
    for (int i{}; i < M; i++) {
        cin >> v2[i];
    }
    
    
    for (int i{}; i < M; i++) {
        auto low = lower_bound(v1.begin(), v1.end(), v2[i]);
        auto high = upper_bound(v1.begin(), v1.end(), v2[i]);
        
        cout << high - low << " ";
    }
    
    return 0;
}
