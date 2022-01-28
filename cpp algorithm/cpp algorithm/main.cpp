#include <iostream>

using namespace std;
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a{}, b{}, tb{}, ts{}, max{1}, t{1};
    cin >> a >> b;
    
    ts = a < b ? a : b;
    tb = a > b ? a : b;
    for(int i{1}; i <= ts; i++) {
        if((tb%i) == 0 && (ts%i) == 0 && max < i) max = i;
    }
    while((tb*t)%ts) {
        t++;
    }
    cout << max << "\n" << tb*t << "\n";
    
    return 0;
}
