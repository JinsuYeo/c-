#include <iostream>
#include <string>

using namespace std;
   
int arr[101];

int gcd(int a, int b) {
    int t = a % b;
    while(t != 0) {
        a = b;
        b = t;
        t = a % b;
    }
    return b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n{};
    cin >> n;
    for(int i{}; i < n; i++) {
        int t{};
        long long sum{};
        cin >> t;
        for(int j{1}; j <= t; j++) {
            cin >> arr[j];
        }
        for(int j{1}; j <= t - 1; j++) {
            for(int k{j+1}; k <= t; k++) {
                sum += gcd(arr[j], arr[k]);
            }
        }
        cout << sum << "\n";
    }
    
    
    return 0;
}
