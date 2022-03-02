#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int N;
string s;
stack<int> st;
vector<int> v;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;

    for (int i{}; i < N; i++) {
        int t{};
        cin >> t;
        v.push_back(t);
    }

    int i{ 1 };
    for (int j{}; j < v.size(); j++) {
        while (st.top() != v[j]) {
            st.push(i);
            s += "+";
            i++;
        }
        if (v[j] == st.top())
        {
            st.pop();
            s += "-";
        }
    }
    
    for (auto c : s) 
        cout << c << "\n";

    return 0;
}
