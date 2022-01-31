#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  
    int n{}, count{};
    cin >> n;
    
    for(int i{1}; i <= n; i++) {
        int t = i;
        while(t){
            if(t%5 == 0) {
                count++;
                t /= 5;
            } else break;
        }
    }
    
    cout << count << "\n";
    
    return 0;
}
