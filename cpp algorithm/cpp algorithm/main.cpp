#include <iostream>

using namespace std;
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n{}, a{}, b{}, tb{}, ts{}, t{1};
    cin >> n;
    for(int i{}; i < n; i++) {
        t = 1;
        cin >> a >> b;
        
        if(a == b) {
            cout << a <<"\n";
            continue;
        }
        
        ts = a < b ? a : b;
        tb = a > b ? a : b;

        while((tb*t)%ts) {
            t++;
        }
        
        cout << tb*t << "\n";
    }
    
    return 0;
}
