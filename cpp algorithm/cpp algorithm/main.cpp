#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, S, result{1 << 30};

int gcd(int a, int b) {
    int c{};
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    
    return a;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> S;
    vector<int> A(N);

    for (int i{}; i < N; i++)
        cin >> A[i];
    A.push_back(S);
    
    sort(A.begin(), A.end());
    
    vector<int> v;
    for (int i{}; i < N; i++) {
        int temp = A[i+1] - A[i];
        result = min(result, temp);
        v.push_back(temp);
    }
    
    for (int i{}; i < v.size(); i++) {
        if (result && v[i] % result) {
            result = gcd(v[i], result);
        }
    }
    
    cout << result << "\n";
    
    return 0;
}
