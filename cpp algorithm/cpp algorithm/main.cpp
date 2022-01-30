#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>


using namespace std;
   
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a{}, b{}, n{}, sum{};
    vector<int> v;
    vector<int> result;
    cin >> a >> b >> n;
    for(int i{}; i < n; i++) {
        int t{};
        cin >> t;
        v.push_back(t);
    }
    reverse(v.begin(), v.end());
    
    for(int i{}; i < n; i++) {
        sum += v.at(i) * pow(a, i);
    }
    
    while(sum != 0) {
        result.push_back(sum%b);
        sum /= b;
    }
    
    reverse(result.begin(), result.end());
    for(auto r: result) {
            cout << r << " ";
    }
    cout << "\n";
    
    return 0;
}
