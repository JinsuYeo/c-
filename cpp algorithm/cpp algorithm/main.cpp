#include <iostream>
#include <algorithm>

using namespace std;

int arr[3], cSort[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n{3}, range{1000000};
//    cin >> n;
    for(int i{1}; i <= n; i++) {
        cin >> arr[i];
    }
    
    for(int i{1}; i <= n; i++) {
        cSort[arr[i]]++;
    }
    
    for (int i{1}; i <= range; i++) {
        if(cSort[i]) {
            for(int j{}; j < cSort[i]; j++) {
                cout << i << "\n";
            }
        }
    }
    
    return 0;
}
