#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

vector<int> v;
bool visited[8];
vector<int> sorted;

int T, N, result, sum;

void dfs(int start) {
    if (sorted.size() == v.size()) {
        for (int i{1}; i < sorted.size(); i++) {
            sum += abs(sorted.at(i-1) - sorted.at(i));
        }
        result = max(result, sum);
        sum = 0;
    }
    for (int i{}; i < v.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            sorted.push_back(v.at(i));
            dfs(i);
            visited[i] = false;
            sorted.pop_back();
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> T;
    for (int i{}; i < T; i++) {
        cin >> N;
        v.push_back(N);
    }
    
    sort(v.begin(), v.end());
    
    for (int i{}; i < v.size(); i++) {
        visited[i] = true;
        sorted.push_back(v[i]);
        dfs(i);
        sorted.pop_back();
        visited[i] = false;
    }
    
    cout << result << '\n';
    
    return 0;
}
