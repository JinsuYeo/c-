#include <iostream>

using namespace std;
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n{}, a{}, b{};
    cin >> n;
    for(int i{}; i < n; i++) {
        int gcf{}, lcm{}, t{}, at{}, bt{};
        cin >> a >> b;
        t = a % b;
        at = a;
        bt = b;
        while(t != 0) {
            at = bt;
            bt = t;
            t = at % bt;
        }
        gcf = bt;
        lcm = (a*b)/gcf;
        cout << lcm << "\n";
    }
    
    return 0;
}
