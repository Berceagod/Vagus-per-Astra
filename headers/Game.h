//
// Created by mihne on 11/7/2024.
//

#ifndef GAME_H
#define GAME_H

#include "Player.h"
class Game{
private:
    Player jucator;
public:
    Game();
    void addPlayer(const Player &p);
    static void Start();
    ~Game();
};



#endif //GAME_H