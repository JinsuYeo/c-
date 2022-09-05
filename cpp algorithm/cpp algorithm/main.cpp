#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int N;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    
    stack<char> st;
    
    for (int i{}; i < N; i++) {
        string s;
        cin >> s;
        
        for(int i{}; i < s.length(); i++){
            char c = s[i];
            if (c == '(' || (c == ')' && st.empty())) {
                st.push(c);
            } else if(c == ')' && st.top() == '(') {
                st.pop();
            }
        }
        
        if (st.empty()) cout << "YES" << '\n';
        else {
            cout << "NO" << '\n';
            while (!st.empty()) {
                st.pop();
            }
        }
    }
    
    return 0;
}
