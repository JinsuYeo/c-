#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int S, N, M;
int result;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> S >> M >> N;
    vector<int> A(M), B(N);
    for (int i{}; i < M; i++) {
        cin >> A[i];
    }
    for (int i{}; i < N; i++) {
        cin >> B[i];
    }
    
    vector<int> v1(1, 0), v2(1, 0);
    int low{}, high{};
    int sum{};
    while (low < A.size()) {
        sum += A[high++];
        if (sum <= S)
            v1.push_back(sum);
        else {
            low++;
            high = low;
            sum = 0;
        }
        
        if (high == A.size()) high = 0;
        if ((!low && !high) || high+1 == low) {
            low++;
            high = low;
            sum = 0;
        }
    }
    
    low = 0;
    high = 0;
    sum = 0;
    while (low < B.size()) {
        sum += B[high++];
        if (sum <= S)
            v2.push_back(sum);
        else {
            low++;
            high = low;
            sum = 0;
        }
        
        if (high == B.size()) high = 0;
        if ((!low && !high) || high+1 == low) {
            low++;
            high = low;
            sum = 0;
        }
    }
    
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    
    for (int i{}; i < v1.size(); i++) {
        int num = S - v1[i];
        int low =  static_cast<int>(lower_bound(v2.begin(), v2.end(), num) - v2.begin());
        int high = static_cast<int>(upper_bound(v2.begin(), v2.end(), num) - v2.begin());
        
        if(num == v2[low]) result += high - low;
    }
    
    cout << result << "\n";
    
    return 0;
}
