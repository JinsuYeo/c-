#include <cstdio>

int sorted[1000001];

void merge(int arr[], int m, int middle, int n) {
    int i = m;
    int j = middle + 1;
    int k = m;
    while (i <= middle && j <= n) {
        if(arr[i] <= arr[j]) {
            sorted[k] = arr[i];
            i++;
        } else {
            sorted[k] = arr[j];
            j++;
        }
        k++;
    }
    if (i > middle) {
        for(int t{j}; t <= n; t++) {
            sorted[k] = arr[t];
            k++;
        }
    } else {
        for(int t{i}; t <= middle; t++) {
            sorted[k] = arr[t];
            k++;
        }
    }
    
    for(int t = m; t <= n; t++) {
        arr[t] = sorted[t];
    }
}

void mergeSort(int arr[], int m, int n) {
    if(m < n) {
        int middle = (m + n) / 2;
        mergeSort(arr, m, middle);
        mergeSort(arr, middle+1, n);
        merge(arr, m, middle, n);
    }
}

int main(int argc, const char * argv[]) {
    int n{}, arr[1000001];
    scanf("%d", &n);
    
    for(int i{}; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    mergeSort(arr, 0, n-1);
    
    for(int i{}; i < n; i++) {
        printf("%d\n", arr[i]);
    }
    
    return 0;
}
