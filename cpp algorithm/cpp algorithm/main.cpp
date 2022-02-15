#include <iostream>
#include <algorithm>
#include <array>
#include <cstdio>

using namespace std;

int N, M;
long long result;
array<array<int, 51>, 51> rect;

int rect_sum(int nstart, int mstart, int nend, int mend) {
    int sum{};
    for (int i{nstart}; i <= nend; i++) {
        for (int j{mstart}; j <= mend; j++) {
            sum += rect[i][j];
        }
    }
    
    return sum;
}

int main(void) {
    cin >> N >> M;
    for(int i {}; i < N; i++) {
        for (int j{}; j < M; j++) {
            scanf("%1d", &rect[i][j]);
        }
    }
    
    for(int i{}; i < N-2; i++) {
        for (int j{i+1}; j < N-1; j++) {
            long long pd{1};
            pd *= rect_sum(0, 0, i, M-1);
            pd *= rect_sum(i+1, 0, j, M-1);
            pd *= rect_sum(j+1, 0, N-1, M-1);
            
            result = max(result, pd);
        }
    }
    
    for (int i{}; i < M-2; i++) {
        for (int j{i+1}; j < M-1; j++) {
            long long pd{1};
            pd *= rect_sum(0, 0, N-1, i);
            pd *= rect_sum(0, i+1, N-1, j);
            pd *= rect_sum(0, j+1, N-1, M-1);
            
            result = max(result, pd);
        }
    }
    
    for (int i{}; i < M-1; i++) {
        for (int j{}; j < N-1; j++) {
            long long pd{1};
            pd *= rect_sum(0, 0, N-1, i);
            pd *= rect_sum(0, i+1, j, M-1);
            pd *= rect_sum(j+1, i+1, N-1, M-1);
            
            result = max(result, pd);
        }
    }
       
    for (int i{M-1}; i >= 0; i--) {
        for (int j{}; j < N-1; j++) {
            long long pd{1};
            pd *= rect_sum(0, 0, j, i);
            pd *= rect_sum(j+1, 0, N-1, i);
            pd *= rect_sum(0, i+1, N-1, M-1);
            
            result = max(result, pd);
        }
    }
    
    for (int i{}; i < N-1; i++) {
        for (int j{}; j < M-1; j++) {
            long long pd{1};
            pd *= rect_sum(0, 0, i, M-1);
            pd *= rect_sum(i+1, 0, N-1, j);
            pd *= rect_sum(i+1, j+1, N-1, M-1);
            
            result = max(result, pd);
        }
    }
    
    for (int i{N-1}; i >= 0; i--) {
        for (int j{}; j < M-1; j++) {
            long long pd{1};
            pd *= rect_sum(0, 0, i, j);
            pd *= rect_sum(0, j+1, i, M-1);
            pd *= rect_sum(i+1, 0, N-1, M-1);
            
            result = max(result, pd);
        }
    }

    cout << result << '\n';
    
    return 0;
}
