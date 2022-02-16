#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <array>
#include <set>
#include <vector>

using namespace std;

int A, B, C;

typedef array<pair<int, int>, 3>  pi;
queue<pi> q;
set<pi> visited;

void bfs(){
    while (!q.empty()) {
        pi cur = q.front();
        pair<int, int> a = cur.at(0);
        pair<int, int> b = cur.at(1);
        pair<int, int> c = cur.at(2);
        int pa = a.first - a.second;
        int pb = b.first - b.second;
        int pc = c.first - c.second;
        q.pop();
        
        if (pa && c.second && c.second >= pa) {
            pi next = {make_pair(A, A), b, make_pair(C, c.second-pa)};
            if (!visited.count(next)) {
                q.push(next);
                visited.insert(next);
            }
        }
        if (pa && c.second && c.second <= pa) {
            pi next = {make_pair(A, a.second + c.second), b, make_pair(C, 0)};
            if (!visited.count(next)) {
                q.push(next);
                visited.insert(next);
            }
        }
        if (pb && c.second && c.second >= pb) {
            pi next = {a, make_pair(B, B), make_pair(C, c.second-pb)};
            if (!visited.count(next)) {
                q.push(next);
                visited.insert(next);
            }
        }
        if (pb && c.second && c.second <= pb) {
            pi next = {a, make_pair(B, b.second + c.second), make_pair(C, 0)};
            if (!visited.count(next)) {
                q.push(next);
                visited.insert(next);
            }
        }
        
        if (pa && b.second && b.second >= pa) {
            pi next = {make_pair(A, A),  make_pair(B, b.second-pa), c};
            if (!visited.count(next)) {
                q.push(next);
                visited.insert(next);
            }
        }
        if (pa && b.second && b.second <= pa) {
            pi next = {make_pair(A, a.second + b.second),  make_pair(B, 0), c};
            if (!visited.count(next)) {
                q.push(next);
                visited.insert(next);
            }
        }
        if (pc && b.second && b.second >= pc) {
            pi next = {a, make_pair(B, b.second-pc), make_pair(C, C)};
            if (!visited.count(next)) {
                q.push(next);
                visited.insert(next);
            }
        }
        if (pc && b.second && b.second <= pc) {
            pi next = {a, make_pair(B, 0), make_pair(C, c.second + b.second)};
            if (!visited.count(next)) {
                q.push(next);
                visited.insert(next);
            }
        }
        
        if (pb && a.second && a.second >= pb) {
            pi next = {make_pair(A, a.second-pb), make_pair(B, B), c};
            if (!visited.count(next)) {
                q.push(next);
                visited.insert(next);
            }
        }
        if (pb && a.second && a.second <= pb) {
            pi next = {make_pair(A, 0), make_pair(B, b.second + a.second), c};
            if (!visited.count(next)) {
                q.push(next);
                visited.insert(next);
            }
        }
        if (pc && a.second && a.second >= pc) {
            pi next = {make_pair(A, a.second-pc), b, make_pair(C, C)};
            if (!visited.count(next)) {
                q.push(next);
                visited.insert(next);
            }
        }
        if (pc && a.second && a.second <= pc) {
            pi next = {make_pair(A, 0), b, make_pair(C, c.second + a.second)};
            if (!visited.count(next)) {
                q.push(next);
                visited.insert(next);
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> A >> B >> C;
    pi start = {make_pair(A, 0), make_pair(B, 0), make_pair(C, C)};
    
    q.push(start);
    visited.insert(start);
    
    bfs();
    vector<int> v;
    
    auto it = visited.begin();
    while (it != visited.end()) {
        if (it->at(0).second == 0) {
            v.push_back(it->at(2).second);
        }
        it++;
    }
        
    sort(v.begin(), v.end());
    for (auto e: v) {
        cout << e << " ";
    }
    
    
    return 0;
}
