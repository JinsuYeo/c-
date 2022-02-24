#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, S;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> S;
    vector<int> v(N);
    for (int i{}; i < N; i++) {
        cin >> v[i];
    }
    
    int half {N/2};
    
    vector<int> first(1 << (N-half));
    for (int i{}; i < 1 << (N-half); i++) {
        for (int j{}; j < (N-half); j++) {
            if (i & (1 << j)) {
                first[i] += v[j];
            }
        }
    }
    
    vector<int> second(1 << half);
    for (int i{}; i < 1 << half; i++) {
        for (int j{}; j < half; j++) {
            if (i & (1 << j)) {
                second[i] += v[j+(N-half)];
            }
        }
    }
    
    sort(first.begin(), first.end());
    sort(second.begin(), second.end(), greater<int>());
    
    int i1{}, i2{};
    long long result{};
    while (i1 < 1 << (N-half) && i2 < 1 << half) {
        int sum = first[i1] + second[i2];
        if (sum == S) {
            long long cnt1 = 1, cnt2 = 1;
            i1++;
            i2++;
            while (i1 < 1 << (N-half) && first[i1] == first[i1 - 1]) {
                i1++;
                cnt1++;
            }
            while (i2 < 1 << half && second[i2] == second[i2 - 1]) {
                i2++;
                cnt2++;
            }
            result += cnt1 * cnt2;
        } else if(sum < S) {
            i1++;
        } else if(sum > S) {
            i2++;
        }
    }
    
    if (S == 0) {
        result--;
    }
    
    cout << result << "\n";
    
    return 0;
}
