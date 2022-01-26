#include <iostream>
#include <algorithm>

using namespace std;

long arr[100000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n{}, max{1}, temp{1}, index{};
    cin >> n;
    for(int i{}; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr+n);
    
    for(int i{1}; i < n; i++) {
        if(arr[i] == arr[i-1]){
            temp++;
            if(max < temp) {
                max = temp;
                index = i;
            }
        }
        else {
            temp = 1;
        }
    }
    
    cout << arr[index] <<"\n";
    
    return 0;
}
