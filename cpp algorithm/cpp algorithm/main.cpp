#include <iostream>
#include <array>
#include <vector>

using namespace std;

long long n, c;

array<long long, 500001> arr;
array<long long, 500001> sorted;

void merge(int start, int mid, int end) {
    int i = start;
    int j = mid + 1;
    int k = start;
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            sorted[k++] = arr[i++];
        } else {
            c += mid-i+1;
            sorted[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        sorted[k++] = arr[i++];
    }
    while (j <= end) {
        sorted[k++] = arr[j++];
    }
    
    for (int i{start}; i <= end; i++) {
        arr[i] = sorted[i];
    }
}

void merge_sort(int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        merge_sort(start, mid);
        merge_sort(mid+1, end);
        merge(start, mid, end);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for (int i{1}; i <= n; i++) {
        cin >> arr[i];
    }
    
    merge_sort(1, n);
    
    cout << c;
    
    return 0;
}

