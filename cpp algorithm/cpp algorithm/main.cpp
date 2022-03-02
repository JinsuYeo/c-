#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s;
string result;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    getline(cin, s);

    bool flag{false};
    string target;
    for (int i{}; i < s.length(); i++) {
        if (s[i] == '<') {
            flag = true;
            if (target.length()) {
                reverse(target.begin(), target.end());
                result += target;
                target.clear();
            }
            result += "<";
            continue;
        }
        if (s[i] == '>') {
            flag = false;
            result += ">";
            continue;
        }
        
        if (flag) {
            result += s[i];
        } else if(!flag && s[i] == ' ') {
            reverse(target.begin(), target.end());
            result += target + " ";
            target.clear();
        }
        else {
            target += s[i];
        }
    }
    reverse(target.begin(), target.end());
    result += target;


    cout << result << '\n';
    
    return 0;
}
