#include <iostream>
#include <algorithm>
#include <array>
#include <vector>

using namespace std;

array<int, 11> arr;
vector<int> v;

int T, N;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> T;
    for (int i{}; i < T; i++) {
        cin >> N;
        v.push_back(N);
    }
    
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    
    for(int i{4}; i < 11; i++) {
        arr[i] = arr[i-3] + arr[i-2] + arr[i-1];
    }
    
    for (auto e: v) {
        cout << arr[e] << '\n';
    }
    
    return 0;
}
