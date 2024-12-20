//
// Created by mihne on 11/7/2024.
//
#pragma once
#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "raylib.h"
#include "CostumExceptions.h"
#include "Bullet.h"
class Game{
private:
    Player player;
    Camera2D camera;
    std::vector<Bullet> bullets;
    Texture2D bulletTexture;
public:
    Game();
    void addPlayer(const Player &p);
    void Start();
    void Draw(Texture2D &background);
    void Update();
    void HandleInput();
    void ShutDown();

    float getCameraTargetx();
    float getCameraTargety();
    float getCameraZoom();
    ~Game();
};



#endif //GAME_H