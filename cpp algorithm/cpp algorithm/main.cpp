#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <iomanip>

using namespace std;

int N;
string S;
stack<double> st;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    cin >> S;
    
    vector<double> temp(S.length());

    char c{'A'};
    for (int i{}; i < N; i++) {
        double t{};
        cin >> t;
        for (int j{}; j < S.length(); j++) {
            if(S[j] == c) {
                temp[j] = t;
            }
        }
        c++;
    }
    
    for (int i{}; i < S.length(); i++) {
        if(S[i] >= 'A' && S[i] <= 'Z') {
            st.push(temp[i]);
        } else {
            if (S[i] == '+') {
                double calc = st.top();
                st.pop();
                calc += st.top();
                st.pop();
                st.push(calc);
            }
            if (S[i] == '-') {
                double calc = st.top();
                st.pop();
                calc = st.top() - calc;
                st.pop();
                st.push(calc);
            }
            if (S[i] == '/') {
                double calc = st.top();
                st.pop();
                calc = st.top()/calc;
                st.pop();
                st.push(calc);
            }
            if (S[i] == '*') {
                double calc = st.top();
                st.pop();
                calc *= st.top();
                st.pop();
                st.push(calc);
            }
        }
    }
    
    cout << fixed << setprecision(2);
    
    cout << st.top() << "\n";
    
    return 0;
}
