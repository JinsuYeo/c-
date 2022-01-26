#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int arr[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n{}, t{};
    cin >> n;
    
    for (int i{}; i < n; i++) {
        cin >> t;
        arr[t]++;
    }
    
    for (int i{1}; i <= 10000; i++) {
        if(arr[i]){
            for (int j{}; j < arr[i]; j++) {
                cout << i << "\n";
            }
        }
    }
   
    return 0;
}
