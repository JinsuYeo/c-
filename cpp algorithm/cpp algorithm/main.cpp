#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int n{};
    cin >> n;
    
    for(int i{}; i < n; i++){
        for(int k{}; k < n-i-1; k++) {
            cout << " ";
        }
        for(int j{}; j < 2*i + 1; j++) {
            if(i == 0 || i == n - 1 || j == 0 || j == 2*i) cout << "*";
            else cout << " ";
        }
        cout << '\n';
    }
        
    return 0;
}

 

