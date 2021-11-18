#include <iostream>
#include <vector>

enum day {SUN, MON, TUE, WED, THU, FRI, SAT};

using namespace std;

int main(int argc, const char * argv[]) {
    enum day days;
    char* day[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int mon {}, date {};
    cin >> mon >> date;
    int sum{};
    int d{};
    vector<int> mondate {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for(int i{}; i < mon; i++){
        sum += mondate[i];
    }
    d = (sum + date)%7;
    
    cout << day[d] << '\n';
    
        
    return 0;
}

 
