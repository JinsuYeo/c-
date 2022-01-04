#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    int h{}, m{};
    cin >> h >> m;
    
    if(m < 45) {
        m = 15 + m;
        if(h == 0)
            h = 23;
        else h--;
    } else {
        m -= 45;
    }
    
    cout << h << " " << m << endl;
    
    return 0;
}
