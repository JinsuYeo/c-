#include <iostream>
#include <algorithm>

using namespace std;

int n, m, c;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    // n이 세로, m이 가로
    
    if (n <= 1) {
        c = 1;
    } else if(n == 2 && m >= 7) {
        c = 4;
    } else if(n == 2 && m < 7) {
        c = (m-1)/2 + 1;
    } else if(n >= 3 && m >= 7) {
        c = m - 2;
    } else if(n >= 3 && m < 7) {
        if (m >= 4) {
            c = 4;
        } else c = m;
    }
   
    cout << c;
    
    return 0;
}
