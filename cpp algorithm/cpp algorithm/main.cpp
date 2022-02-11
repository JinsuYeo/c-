#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define X first
#define Y second

const int MAX = 1 << 30;

typedef pair<int, int> pairii;
vector<pairii> v;

int dist(int low, int high){
    int lowx = v[low].X;
    int lowy = v[low].Y;
    int highx = v[high].X;
    int highy = v[high].Y;
    
    int distx = highx - lowx;
    int disty = highy - lowy;
    
    return distx*distx + disty*disty;
}

int check(int low, int high) {
    if (low == high) return MAX;
    if (low + 1 >= high) return dist(low, high);
    
    int min = dist(low, high);
    int mid = (low+high)/2;
    int t{};
    
    if ((t = check(low, mid)) < min) {
        min = t;
    }
    if ((t = check(mid+1, high)) < min) {
        min = t;
    }
    
    vector<pairii> v2;
    int line = v[mid].X;
    for (int i{mid}; i >= low; i--) {
        int x = v[i].X;
        int dis = line - x;
        dis *= dis;
        if (min <= dis) break;
        else v2.push_back({v[i].Y, v[i].X});
    }
    for (int i{mid+1}; i <= high; i++) {
        int x = v[i].X;
        int dis = line - x;
        dis *= dis;
        if (min <= dis) break;
        else v2.push_back({v[i].Y, v[i].X});
    }
    
    int size = static_cast<int>(v2.size());
    if (!size) return min;
    
    sort(v2.begin(), v2.end());
    
    for(int i{}; i < size; i++){
        int ix = v2[i].Y, iy = v2[i].X;
        for(int j{i+1}; j < size; j++){
            int jx = v2[j].Y, jy = v2[j].X;
            int distx = jx - ix, disty = jy - iy;
            if(min <= disty * disty) break;
            if(min <= distx * distx) continue;
            
            int dist = distx*distx + disty*disty;
            if(dist < min)
                min = dist;
        }
    }
    
    return min;
}

int main() {
    int n;
    cin >> n;
    for (int i{}; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    
    sort(v.begin(), v.end());
    
    cout << check(0, n-1);
    
    return 0;
}
