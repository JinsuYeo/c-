#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

int n;

vector<pair<int, int>> arr;
vector<int> seg_tree;

void update(int node, int start, int end, int index){
    if (start == end) {
        seg_tree[node] = 1;
        return;
        }
    int mid = (start+end)/2;
    if(index <= mid) update(node*2, start, mid, index);
    else update(node*2 + 1, mid + 1, end, index);
    seg_tree[node] = seg_tree[node*2] + seg_tree[node*2+1];
}

int cnt(int node, int start, int end, int left, int right){
    if(left > end || right < start) return 0;
    if(left <= start && right >= end) return seg_tree[node];
    int mid = (start+end)/2;
    int left_count = cnt(node*2, start, mid, left, right);
    int right_count = cnt(node*2 + 1, mid+1, end, left, right);
    return left_count + right_count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long c{};
    
    cin >> n;

    seg_tree.resize(n*4);
    arr.push_back({-1000000001, 0});
    for (int i{1}; i <= n; i++) {
        int t;
        cin >> t;
        arr.push_back({t, i});
    }
    
    sort(arr.begin(), arr.end());
    for (int i{1}; i <= n; i++) {
        c += (long long)cnt(1, 1, n, arr[i].second + 1, n);
        update(1, 1, n, arr[i].second);
    }
    cout << c;
    
    return 0;
}

