#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int T;
int c{};
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        string s;
        int n;
        cin >> s >> n;
        bool order = true;
        
        deque<int> v;
        
        string tstr;
        cin >> tstr;
        tstr.erase(0, 1);
        tstr.erase(tstr.length() - 1, 1);
        stringstream ss(tstr);
        string t;
        
        while (getline(ss, t, ',')) {
            v.push_back(stoi(t));
        }
        
        int flag = 1;
        for(int j = 0; j < s.length(); j++) {

            if(s.at(j) == 'R') {
                order = !order;
            }
            if(s.at(j) == 'D') {
                if (v.empty()) {
                    cout << "error\n";
                    flag = 0;
                    break;
                }
                else {
                    if (order) {
                        v.pop_front();
                    }
                    if(!order){
                        v.pop_back();
                    }
                    
                }
            }
        }

        if(flag) {
            if(order) {
                cout << '[';
                for (int j = 0; j < v.size(); j++) {
                    if(j == v.size()-1) cout << v[j];
                    else cout << v[j] << ',';
                }
                cout << "]\n";
            }
            if(!order) {
                cout << '[';
                for (int j = v.size()-1; j >= 0; j--) {
                    if(j == 0) cout << v[j];
                    else cout << v[j] << ',';
                }
                cout << "]\n";
            }
        }
        
        v.clear();
    }


    

    return 0;
}
