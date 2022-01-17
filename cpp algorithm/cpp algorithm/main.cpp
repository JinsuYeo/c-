#include <iostream>
#include <algorithm>

using namespace std;

int dpl[1001], dpr[1001], arr[1001], maxarr[1001];

int main(int argc, const char * argv[]) {
    int n{}, result{1};
    cin >> n;
    for (int i {1}; i <= n; i++) {
        cin >> arr[i];
    }
    
    dpl[1] = 1;
    maxarr[1] = 1;
    dpr[n] = 1;
    maxarr[n] = 1;
    
    for(int i {2}; i <= n; i++) {
        dpl[i] = 1;
        for(int j{1}; j <= i-1; j++) {
            if(arr[j] < arr[i] && dpl[i] < dpl[j] + 1) {
                dpl[i] = dpl[j] + 1;
            }
        }
        maxarr[i] = dpl[i];
    }
    
    for(int i{n-1}; i >= 1; i--) {
        dpr[i] = 1;
        for(int k{n}; k > i; k--) {
            if(arr[k] < arr[i] && dpr[i] < dpr[k] + 1) {
                dpr[i] = dpr[k] + 1;
            }
        }
        maxarr[i] += dpr[i]-1;
    }
    
    for(int i{1}; i <= n; i++) {
        if(result < maxarr[i]) {
            result = maxarr[i];
        }
        
    }
    
    cout << result << endl;
    
    return 0;
}
