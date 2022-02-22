#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int MAX{4000001};

int N, result;
bool num[MAX];
vector<int> prime;

void tp(){
    int low{}, high{};
    int n = (int)prime.size();
    int sum{2};
    
    while (low <= high && high < n) {
        if (sum < N) {
            sum += prime[++high];
        } else if(sum == N) {
            result++;
            sum += prime[++high];
        } else if(sum > N) {
            sum -= prime[low++];
            if (low > high) {
                high = low;
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        
    cin >> N;

    memset(num, 1, N+1);
    
    num[0] = false;
    num[1] = false;
    for (int i{2}; i <= N; i++) {
        if (num[i] == 0) continue;
        for (int j{i+i}; j <= N; j+=i) {
            num[j] = false;
        }
    }
    
    for (int i{}; i <= N; i++) {
        if (num[i]) prime.push_back(i);
    }
    
    tp();
    
    cout << result << '\n';
    
    return 0;
}
