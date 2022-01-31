#include <iostream>
#include <algorithm>

using namespace std;

int seg[2000000];

int init(int node, int start, int end) {
    if(start == end) return seg[node] = 1;
    int mid = (start + end) / 2;
    return seg[node] = init(node * 2, start, mid) + init(node*2 + 1, mid + 1, end);
}

int update(int node, int start, int end, int order) {
    seg[node]--;
    if(start == end) return 0;
    else {
        int mid = (start + end) / 2;
        if(order <= mid) return update(2 * node, start, mid, order);
        else return update(2 * node + 1, mid + 1, end, order);
    }
}

int query(int node, int start, int end, int order) {
    if (start == end) return start;
    int mid = (start + end) / 2;
    if(order <= seg[2 * node]) return query(2 * node, start, mid, order);
    else return query(2 * node + 1, mid + 1, end, order - seg[2 * node]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n{}, k{};
    cin >> n >> k;
    
    init(1, 1, n);
    
    int index = 1;
    
    cout << "<";
    
    for(int i{}; i < n; i++) {
        int size = n - i;
        index += k - 1;
        
        if(index%size == 0) index = size;
        else if(index > size) index %= size;
        
        int num = query(1, 1, n, index);
        
        update(1, 1, n, num);
        
        if (i == n-1) cout << num << ">";
        else cout << num << ", ";
    }
    
    
    return 0;
}
