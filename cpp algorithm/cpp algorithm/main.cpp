#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n{};
    string s;
    cin >> n;
    
    vector<char> stack;
    vector<string> v;
    
    for(int i{}; i < n; i++) {
        cin >> s;
        v.push_back(s);
    }
    
    for(int i{}; i < n; i++) {
        for (int j{}; j < v.at(i).length(); j++) {
            if(v.at(i).at(j) == '(')
                stack.push_back(v.at(i).at(j));
            else if(v.at(i).at(j) == ')' && stack.size() != 0 && stack.back() == '(')
                stack.pop_back();
            else if(v.at(i).at(j) == ')' && (stack.size() == 0 || stack.back() != '('))
                stack.push_back(v.at(i).at(j));
        }
        if(stack.size()) cout << "NO" << "\n";
        else if(!stack.size()) cout << "YES" << "\n";
        
        stack.clear();
    }
    
    
    return 0;
}
