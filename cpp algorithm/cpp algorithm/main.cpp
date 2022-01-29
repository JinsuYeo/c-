#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
   
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s;
    vector<char> v;
    int n{}, m{1};
    int sum{};

    cin >> s >> n;
    
    for(int i{(int)s.length()-1}; i >= 0; i--){
        if(s.at(i) < 'A') {
            sum += m*(int(s.at(i)-'0'));
        } else {
            sum += m*(int(s.at(i)-'A'+10));
        }
        m *= n;
    }
    
    cout << sum << "\n";
    
    return 0;
}
