#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  
    int n{}, m{}, fcount{}, tcount{}, count{};
    cin >> n >> m;
    
    for(long long i{5}; i <= n; i*=5) fcount += n/i;
    for(long long i{5}; i <= m; i*=5) fcount -= m/i;
    for(long long i{5}; i <= n-m; i*=5) fcount -= (n-m)/i;
    
    for(long long i{2}; i <= n; i*=2) tcount += n/i;
    for(long long i{2}; i <= m; i*=2) tcount -= m/i;
    for(long long i{2}; i <= n-m; i*=2) tcount -= (n-m)/i;
    
    count = tcount < fcount ? tcount : fcount;
    
    cout << count << "\n";
    
    return 0;
}
