#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, result;

vector<int> p;
vector<int> z;
vector<int> m;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for (int i{}; i < n; i++) {
        int t{};
        cin >> t;
        if (t < 0) {
            m.push_back(t);
        } else if(t == 0) z.push_back(t);
        else if(t == 1) result += 1;
        else p.push_back(t);
    }
    
    sort(m.begin(), m.end());
    sort(p.begin(), p.end(), greater<int>());
    
    if (m.size() % 2 == 0) {
        for (int i{}; i < m.size(); i += 2) {
            result += m.at(i) * m.at(i+1);
        }
    } else if(m.size()%2 != 0) {
        if (!z.empty()) {
            m.pop_back();
        } else {
            result += m.back();
            m.pop_back();
        }
        for (int i{}; i < m.size(); i+=2) {
            result += m.at(i) * m.at(i+1);
        }
    }
    
    if (p.size()%2 != 0) {
        result += p.back();
        p.pop_back();
    }
    for (int i{}; i < p.size(); i+=2) {
        result += p.at(i) * p.at(i+1);
    }
    
    cout << result << '\n';
    
    return 0;
}
