#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int L, C;
string s;
vector<char> v;
bool isVowel[16];
void dfs(int size, int index, int vowel, int consonant){
    if (size == L && vowel >= 1 && consonant >= 2) {
        cout << s << '\n';
        return;
    }
    
    for (int i{index}; i < C; i++) {
        s += v[i];
        if(isVowel[i]) {
            dfs(size+1, i+1, vowel+1, consonant);
        } else {
            dfs(size+1, i+1, vowel, consonant+1);
        }
        s.pop_back();
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> L >> C;
    for (int i{}; i < C; i++) {
        char t;
        cin >> t;
        v.push_back(t);
    }
    
    sort(v.begin(), v.end());
    
    for (int i{}; i < C; i++) {
        int t = v[i];
        if (t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u') {
            isVowel[i] = true;
        }
    }
    
    dfs(0, 0, 0, 0);

    return 0;
}
