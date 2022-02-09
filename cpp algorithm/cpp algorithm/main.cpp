#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int n;
vector<pair<int, int>> v;

void hanoi(int n, int from, int temp, int to) {
    if (n == 1) {
        v.push_back(make_pair(from, to));
    } else {
        hanoi(n-1, from, to, temp);
        v.push_back(make_pair(from, to));
        hanoi(n-1, temp, from, to);
    }
}

int main()
{
    cin >> n;

    hanoi(n, 1, 2, 3);
    
    cout << v.size() << "\n";
    for (auto e: v) {
        cout << e.first << " " << e.second << "\n";
    }
    
    return 0;
}
