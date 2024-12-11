

#ifndef BULLET_H
#define BULLET_H
#pragma once
#include "raylib.h"
#include "raymath.h"
class Bullet{
private:
    Vector2 position;
    int speed;
    float rotation;
    float damage;
    Texture2D texture;
public:
    Bullet(Vector2 position,int speed,float rotation,Texture2D texture);
    void Update();
    void Draw();
    float getPozX();
    float getPozY();
    ~Bullet();

};

#endif //BULLET_H
