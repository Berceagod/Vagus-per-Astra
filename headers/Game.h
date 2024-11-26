//
// Created by mihne on 11/7/2024.
//
#pragma once
#ifndef GAME_H
#define GAME_H

#include "Player.h"
class Game{
private:
    Player player;
    Camera2D camera;
public:
    Game();
    void addPlayer(const Player &p);
    static void Start();
    void Draw();
    void Update();
    void HandleInput();

    ~Game();
};



#endif //GAME_H