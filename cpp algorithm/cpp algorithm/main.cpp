#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int N, x, y;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    set<int, less<>> s;
    
    cin >> N;
    
    for (int i{}; i < N; i++) {
        int n{};
        cin >> n;
        s.insert(n);
    }
    
    for (int el : s) {
        cout << el << " ";
    }
    
    return 0;
}
