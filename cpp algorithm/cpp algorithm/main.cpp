#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int N, temp;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    int j = 1;
    stack<int> st;
    string result{};
    
    for (int i{}; i < N; i++) {
        cin >> temp;
        if (!st.empty() && st.top() > temp) {
            cout << "NO";
            return 0;
        }
        while (st.empty() || st.top() != temp) {
            st.push(j++);
            result += "+\n";
        }
        st.pop();
        result += "-\n";
    }
    
    cout << result;
    
    return 0;
}
