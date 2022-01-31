#include <iostream>

using namespace std;

long long arr[13];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  
    int n{};
    cin >> n;
    
    arr[0] = 1;
    for (int i{1};  i <= n; i++) {
        arr[i] = i*arr[i-1];
    }
    
    cout << arr[n] <<"\n";
    
    return 0;
}
