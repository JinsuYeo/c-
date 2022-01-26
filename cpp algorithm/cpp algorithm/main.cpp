#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

char arr[10000000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n{};
    cin >> n;
    
    for (int i{}; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr+n);
    
    for (int i{}; i < n; i++) {
        cout << arr[i] << "\n";
    }
   
    return 0;
}
