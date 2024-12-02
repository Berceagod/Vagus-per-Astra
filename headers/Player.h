//
// Created by mihne on 11/7/2024.
//
#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include "Abilitate.h"
#include "Inamic.h"
#include "raylib.h"
#include <array>

class Player {
private:
    float pozx;
    float pozy;
    int hp;
    int lvl;
    std::vector<Abilitate*> abilitati;
    int xplvlup;
    int xpcurent;
    Texture2D image;
    Vector2 position;
    Vector2 speed;
    float acceleration;
    float rotation;
    Vector3 collider;
    float shipHeight;
    float Player_Size;
    float DefSpeed;
public:
    Player();
    Player(float x, float y,int health,int level,int xplvl,int xpcur);
    Player(const Player& other);

    [[nodiscard]] int getHp() const;
    [[nodiscard]] int getLvl() const;
    [[nodiscard]] int getXplvlup() const;
    [[nodiscard]] int getXpcurent () const;
    [[nodiscard]] Vector2 getPozitie() const;
    [[nodiscard]] Vector2 getSpeed() const;
    [[nodiscard]] float getRotation() const;
    [[nodiscard]] float getdefspeed() const;
    [[nodiscard]] float getspeedx() const;
    [[nodiscard]] float getspeedy() const;
    [[nodiscard]] float getPozx () const;
    [[nodiscard]] float getPozy () const;
    [[nodiscard]] float getAccel () const;
    ///std::vector<Abilitate> &getAbilitati();
    ///void addAbilitate(const Abilitate &abilitate);

    void setPozitie(Vector2 positie);
    void setSpeed(float speedx, float speedy);
    void setPozx(float x);
    void setPozy(float y);

    void setHp(int hp);
    void setLvl(int lvl);
    void setXpcurent(int xpcurent);
    void setXplevelup(int xplevelup);
    Player& operator=(const Player& other);
    ~Player();

    friend std::ostream& operator<<(std::ostream& os, const Player& p);
    void move(float x, float y);
    void hit( int dmg );
    void lvlup(int level);
    [[nodiscard]] bool alive() const;
    void getKillXp(const Inamic& in);
    [[nodiscard]]bool CheckXP();

    void addAbility(Abilitate* abilitate);
    void AbilitiesCheck() const;


    void Draw();
    void RotateLeft();
    void RotateRight();
    void MoveForward();
    void MoveBackward();
    void SlowDown();
    void PlayerStrafeRight();
    void PlayerStrafeLeft();
};



#endif //PLAYER_H
