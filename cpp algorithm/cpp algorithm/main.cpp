#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Score{
public:
    string name;
    int kor;
    int eng;
    int math;
    Score(string s, int k, int e, int m)
    : name{s}, kor{k}, eng{e}, math{m} {}
};

bool compare(Score a, Score b){
    if(a.kor == b.kor && a.eng == b.eng && a.math == b.math) return a.name < b.name;
    else if(a.kor == b.kor && a.eng == b.eng) return a.math > b.math;
    else if(a.kor == b.kor) return a.eng < b.eng;
    else return a.kor > b.kor;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n{}, k{}, e{}, m{};
    string s;
    vector<Score> v;
    
    cin >> n;
    for(int i{}; i < n; i++) {
        cin >> s >> k >> e >> m;
        v.push_back(Score(s, k, e, m));
    }
    
    sort(v.begin(), v.end(), compare);
    
    for (int i{}; i < n; i++)
        cout << v.at(i).name << "\n";
    
    return 0;
}
