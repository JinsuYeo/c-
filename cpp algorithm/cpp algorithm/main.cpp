#include <iostream>
#include <algorithm>

using namespace std;

int w, m, k;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> w >> m >> k;
    if (w/2 <= m) {
        int t = w/2;
        k -= w%2;
        m -= t;
        k -= m;
        
        while (k > 0) {
            t--;
            k -= 3;
        }
        cout << t;
    } else {
        int t = m;
        w -= t*2;
        k -= w;
        
        while (k > 0) {
            t--;
            k -= 3;
        }
        cout << t;
    }
    
    return 0;
}
