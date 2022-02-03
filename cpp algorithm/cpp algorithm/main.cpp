#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

vector<int> d;
int a, p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> a >> p;
    
    d.push_back(a);
    while(1) {
        bool flag = false;
        string s = to_string(d.back());
        int sum{};
        for(int i{}; i < s.length(); i++) {
            int t = s.at(i) - '0';
            sum += pow(t, p);
        }
        for(int i{}; i < d.size(); i++) {
            if(d.at(i) == sum) {
                cout << i << "\n";
                flag = true;
            }
        }
        d.push_back(sum);
        if(flag) break;
    }
    
    return 0;
}
