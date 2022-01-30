#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;
   
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long n{};
    cin >> n;
    vector<int> v;
    
    if(n == 0) {
        cout << "0\n";
        return 0;
    }

    while (n != 0) {
        if(n%-2 != 0) {
            v.push_back(1);
            n = (n-1)/-2;
        } else {
            v.push_back(0);
            n /= -2;
        }
    }
    
    reverse(v.begin(), v.end());
    
    for(int &i: v) {
        cout << i;
    }
    cout << "\n";
    
    
    return 0;
}
