#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, result{};
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    
    for (int i{}; i < N; i++) cin >> A[i];
    for (int i{}; i < N; i++) cin >> B[i];
    
    vector<int> tempA(A.begin(), A.end());
    sort(tempA.begin(), tempA.end(), greater<>());
    
    vector<int> tempB(B.begin(), B.end());
    sort(tempB.begin(), tempB.end());
    
    for (int i{}; i < N; i++) {
        result += tempA[i] * tempB[i];
    }
    
    cout << result;
    
    
    return 0;
}
