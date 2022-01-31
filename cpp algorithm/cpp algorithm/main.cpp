#include <iostream>

using namespace std;

int arr[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  
    int n{}, t{1000000};
    
    arr[0] = 1;
    arr[1] = 1;
    
    for(int i{2}; i <= t; i++) {
        for (int j{i*2}; j <= t; j += i) {
            if(arr[j] == 0) arr[j] = 1;
        }
    }
    
    while (cin >> n) {
        if(n == 0) return 0;
        
        int a{}, b{};
        for(int i{2}; i <= n; i++) {
            if(arr[i] == 0 && arr[n-i] == 0) {
                a = i;
                b = n-i;
                break;
            }
        }
        
        if(!a) cout << "Goldbach's conjecture is wrong.\n";
        else {
            cout << n << " = " << a << " + " << b << "\n";
        }
    }
    
    return 0;
}
