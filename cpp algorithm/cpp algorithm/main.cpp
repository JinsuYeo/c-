#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 1000001;

int T, N;
int prime[MAX];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    memset(prime, 1, sizeof(prime));
    prime[0] = 0;
    prime[1] = 0;
    for (int i{2}; i < MAX; i++) {
        if(!prime[i]) continue;
        for (int j{i+i}; j < MAX; j+=i) {
            prime[j] = 0;
        }
    }
    
    cin >> T;
    for (int t{}; t < T; t++) {
        int count{};
        cin >> N;
        
        vector<int> v;
        for (int i{2}; i <= N; i++) {
            if (prime[i]) {
                v.push_back(i);
            }
        }
        
        for (int i{}; i < v.size(); i++) {
            int target = N - v[i];
            auto result = lower_bound(v.begin(), v.end(), target) - v.begin();
            
            if (v[result] == target) {
                count++;
                v[result] = N;
            }
        }
        
        cout << count << "\n";
    }
    
    return 0;
}
