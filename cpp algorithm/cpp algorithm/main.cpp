#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <iomanip>

using namespace std;

string S, result;
stack<char> st;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> S;
    
    for (int i{}; i < S.length(); i++) {
        if (S[i] >= 'A' && S[i] <= 'Z') {
            result += S[i];
        } else {
            switch (S[i]) {
                case '(':
                    st.push('(');
                    break;
                case '*':
                case '/':
                    while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
                        result += st.top();
                        st.pop();
                    }
                    st.push(S[i]);
                    break;
                case '-':
                case '+':
                    while (!st.empty() && st.top() != '(') {
                        result += st.top();
                        st.pop();
                    }
                    st.push(S[i]);
                    break;
                case ')':
                    while (!st.empty() && st.top() != '(') {
                        result += st.top();
                        st.pop();
                    }
                    st.pop();
                    break;
                default:
                    break;
            }
        }
    }
    
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    
    cout << result << "\n";
    
    return 0;
}
