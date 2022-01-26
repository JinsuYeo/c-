#include <iostream>
#include <algorithm>

using namespace std;

int arr[5000000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n{}, t{};
    cin >> n >> t;
    
    for (int i{}; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr+n);
    
    cout << arr[t-1] << "\n";
    
   
    return 0;
}
