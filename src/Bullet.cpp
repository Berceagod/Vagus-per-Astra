//
// Created by mihne on 12/5/2024.
//
#include "../headers/Bullet.h"
Bullet::Bullet(Vector2 position, int speed,float rotation,Texture2D texture) {
    this->position = position;
    this->speed = speed;
    this->rotation = rotation;
    this->texture=texture;
}
void Bullet::Draw() {
    Rectangle sourceRect = { 0, 0, (float)texture.width, (float)texture.height };
    Rectangle destRect = { position.x, position.y, (float)texture.width, (float)texture.height };
    Vector2 origin = { (float)texture.width / 2, (float)texture.height / 2 };

    DrawTexturePro(texture, sourceRect, destRect, origin, rotation, WHITE);
}

void Bullet::Update() {
    position.x += sin(rotation * DEG2RAD) * speed;
    position.y -= cos(rotation * DEG2RAD) * speed;
}
float Bullet::getPozX() {
    return position.x;
}
float Bullet::getPozY() {
    return position.y;
}

Bullet::~Bullet()=default;