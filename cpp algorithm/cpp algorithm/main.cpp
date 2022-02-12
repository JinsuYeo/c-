#include <iostream>
#include <algorithm>

using namespace std;

int E, S, M, result;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> E >> S >> M;
    
    bool flag{false};
    int i{1};
    while(!flag) {
        int e{}, s{}, m{};
        e = i%15 == 0 ? 15 : i%15;
        s = i%28 == 0 ? 28 : i%28;
        m = i%19 == 0 ? 19 : i%19;
        if (e == E && s == S && m == M) {
            result = i;
            flag = true;
        }
        i++;
    }
    
    cout << result;
    
    return 0;
}
