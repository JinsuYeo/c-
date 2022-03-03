#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

int N;

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    vector<int> v(N);
    vector<int> result(N);
    stack<int> s;
    
    for (int i{}; i < N; i++) {
        cin >> v[i];
    }
    
    for (int i{}; i < v.size(); i++) {
        while (!s.empty() && v[s.top()] < v[i]) {
            result[s.top()] = v[i];
            s.pop();
        }
        s.push(i);
    }
    
    for_each(result.begin(), result.end(), [](int x){
        if (x == 0) {
            cout << -1 << " ";
        } else cout << x << " ";
    });
    
    return 0;
}
