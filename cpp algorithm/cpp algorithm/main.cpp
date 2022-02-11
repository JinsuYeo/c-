#include <iostream>
#include <algorithm>
#include <vector>
#define END first
#define START second

using namespace std;

typedef pair<int, int> pi;
vector<pi> v;

int n, c;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for (int i{}; i < n ; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({b, a});
    }
    
    sort(v.begin(), v.end());
    
    int cur = v.at(0).END;
    c = 1;
    
    for (int i{1}; i < v.size(); i++) {
        if (cur <= v.at(i).START) {
            cur = v.at(i).END;
            c++;
        }
    }
    
    cout << c;
    
    return 0;
}
