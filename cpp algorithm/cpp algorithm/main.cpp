#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Member {
public:
    int _age;
    string _name;
    int _n;
    Member(int age, string name, int n): _age{age}, _name{name}, _n{n} {};
};

bool compare(Member a, Member b){
    if(a._age == b._age) return a._n < b._n;
    else return a._age < b._age;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n{}, t{};
    string s;
    vector<Member> v;
    
    cin >> n;
    for(int i{1}; i <= n; i++) {
        cin >> t >> s;
        v.push_back(Member(t, s, i));
    }
    
    sort(v.begin(), v.end(), compare);
    
    for(int i{}; i < n; i++) {
        cout << v.at(i)._age << " " << v.at(i)._name << "\n";
    }
    
    return 0;
}
