#include <iostream>

int arr[100];

using namespace std;
   
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n{}, count{};
    bool flag{};
    cin >> n;
    
    for(int i{}; i < n; i++) {
        int t{};
        cin >> t;
        arr[i] = t;
    }
    
    for(int i{}; i < n; i++) {
        if(arr[i] == 2) {
            count++;
            continue;
        } else if(arr[i] == 1) continue;
        for(int j{2}; j < arr[i]; j++) {
            if(arr[i]%j == 0){
                flag = 1;
                break;
            }
        }
        if(!flag) count++;
        flag = 0;
    }
    
    cout << count << "\n";
   
    
    return 0;
}
