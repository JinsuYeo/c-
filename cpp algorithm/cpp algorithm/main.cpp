#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Point {
public:
    int x;
    int y;
    Point(): Point(0, 0){};
    Point(int a, int b): x{a}, y{b}{};
};

ostream &operator<<(ostream& os, const Point &p) {
    os << p.x << " " << p.y;
    return os;
}

bool compare(Point &a, Point &b) {
    if(a.y == b.y) return a.x < b.x;
    else return a.y < b.y;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n{}, x{}, y{};
    cin >> n;
    
    vector<Point> p;
    
    for(int i{}; i < n; i++) {
        cin >> x;
        cin >> y;
        Point point{x, y};
        p.push_back(point);
    }
    
    sort(p.begin(), p.end(), compare);
    
    for(int i{}; i < n; i++) {
        cout << p.at(i) << "\n";
    }
    
    return 0;
}
