#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 4000;

int N;
long long result;
long long arr[4][MAX];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    for (int i{}; i < N; i++) {
        for (int j{}; j < 4; j++) {
            cin >> arr[j][i];
        }
    }
    
    vector<long long> v;
    for (int i{}; i < N; i++) {
        for(int j{}; j < N; j++) {
            v.push_back(arr[2][i] + arr[3][j]);
        }
    }
    
    sort(v.begin(), v.end());
    
    for (int i{}; i < N; i++) {
        for (int j{}; j < N; j++) {
            long long num = arr[0][i] + arr[1][j];
            long long low = lower_bound(v.begin(), v.end(), -num) - v.begin();
            long long high = upper_bound(v.begin(), v.end(), -num) - v.begin();
            
            if (-num == v[low]) {
                result += high-low;
            }
        }
    }
    
    cout << result << "\n";
    
    
    return 0;
}
