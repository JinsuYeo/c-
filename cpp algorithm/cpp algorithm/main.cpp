#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long T;
int N, M;
long long result;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> T;
    cin >> N;
    vector<int> A(N);
    for (int i{}; i < N; i++) {
        cin >> A[i];
    }
    
    cin >> M;
    vector<int> B(M);
    for (int i{}; i < M; i++) {
        cin >> B[i];
    }
    
    vector<long long> v1, v2;
    
    int low{}, high{};
    long long sum{};
    while (low < A.size()) {
        sum += A[high++];
        v1.push_back(sum);
        if (high == A.size()) {
            low ++;
            high = low;
            sum = 0;
        }
    }
    
    low = 0;
    high = 0;
    sum = 0;
    while (low < B.size()) {
        sum += B[high++];
        v2.push_back(sum);
        if (high == B.size()) {
            low ++;
            high = low;
            sum = 0;
        }
    }
    
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    
    for (int i{}; i < v1.size(); i++) {
        long long num = T - v1[i];
        long long low = lower_bound(v2.begin(), v2.end(), num) - v2.begin();
        long long high = upper_bound(v2.begin(), v2.end(), num) - v2.begin();
        
        if (num == v2[low]) result += high - low;
    }
    
    cout << result << "\n";
    
    return 0;
}
