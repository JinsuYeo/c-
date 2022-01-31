#include <iostream>

using namespace std;

int arr[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  
    int a{}, b{};
    cin >> a >> b;
    
    arr[0] = 1;
    arr[1] = 1;
    
    for(int i{2}; i <= b; i++) {
        for(int j{i*2}; j <= b; j += i) {
            if(arr[j] == 0) arr[j] = 1;
        }
    }
    
    for(int i{a}; i <= b; i++) {
        if(arr[i] == 0) cout << i << "\n";
    }
    
    return 0;
}
