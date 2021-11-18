#include <iostream>
#include <string>

class Player {
    std::string name;
    int health;
    int xp;
    
    void talk(std::string);
    bool is_dead();
};

int main(int argc, const char * argv[]) {
    Player* frank = new Player;
    Player hero;


    return 0;
}
