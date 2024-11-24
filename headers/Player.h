//
// Created by mihne on 11/7/2024.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include "Abilitate.h"
#include "Inamic.h"


class Player {
private:
    float pozx;
    float pozy;
    int hp;
    int lvl;
    std::vector<Abilitate> abilitati;
    int xplvlup;
    int xpcurent;

public:
    Player();
    Player(float x, float y,int health,int level,int xplvl,int xpcur);
    Player(const Player& other);

    [[nodiscard]] int getHp() const;
    [[nodiscard]] int getLvl() const;
    [[nodiscard]] int getXplvlup() const;
    [[nodiscard]] int getXpcurent () const;

    [[nodiscard]] float getPozitiex() const;
    [[nodiscard]] float getPozitiey() const;
    std::vector<Abilitate> &getAbilitati();
    void addAbilitate(const Abilitate &abilitate);

    void setPozitie(float x, float y);

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



};



#endif //PLAYER_H
