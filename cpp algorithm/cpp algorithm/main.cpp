#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>

using namespace std;

int k, n;
array<long long, 10001> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k >> n;
    for (int i{1}; i <= k; i++) {
        cin >> arr[i];
    }
    
    long long max{}, sum{}, result{};
    for (int i{1}; i < 32; i++) {
        for(int j{1}; j <= k; j++) {
            sum += (arr[j]/(pow(2, i)-1));
        }
        if(sum >= n && max < pow(2, i) - 1) max = pow(2, i) - 1;
        if(sum < n) break;
        sum = 0;
    }
    
    max = result;
    
    while (1) {
        bool flag = false;
        for (int i{1}; i < 32; i++) {
            for(int j{1}; j <= k; j++) {
                sum += (arr[j]/(max + (pow(2, i)-1)));
            }
            if(sum >= n) result = max + pow(2, i) - 1;
            if(i == 1 && sum < n) {
                flag = true;
                break;
            }
            if(sum < n) break;
            sum = 0;
        }
        if (flag) {
            break;
        }
        sum = 0;
        max = result;
    }
    
       
    cout << result << "\n";
    
    return 0;
}
