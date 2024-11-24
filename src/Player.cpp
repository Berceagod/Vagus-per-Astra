//
// Created by mihne on 11/7/2024.
//

#include "../headers/Player.h"
#include <iostream>

    Player::Player() {
        this->pozx= 0;
        this->pozy= 0;
        this->lvl = 0;
        this->abilitati = std::vector<Abilitate>();
        this->hp=0;
        this->xplvlup=200;
        this->xpcurent=0;
    };
    Player::Player(float x, float y,int health,int level,int xplvl,int xpcur) : pozx{x},pozy{y}, hp{health}, lvl{level}, xplvlup{xplvl}, xpcurent{xpcur} {};
    Player::Player(const Player& other) =default;

    [[nodiscard]] int Player::getHp() const {
        return hp;
    }
    [[nodiscard]] int Player::getLvl() const {
        return lvl;
    }
    [[nodiscard]] int Player::getXplvlup() const {
        return xplvlup;
    }
    [[nodiscard]] int Player::getXpcurent () const {
        return xpcurent;
    }

    [[nodiscard]] float Player::getPozitiex() const {
        return pozx;
    }
    [[nodiscard]] float Player::getPozitiey() const {
        return pozy;
    }
    std::vector<Abilitate> &Player::getAbilitati() {
        return abilitati;
    }
    void Player::addAbilitate(const Abilitate &abilitate) {
        abilitati.push_back(abilitate);
    }

    void Player::setPozitie(float x, float y) {
        this->pozx=x;
        this->pozy=y;
    }

    void Player::setHp(int hp) {
        this->hp = hp;
    }
    void Player::setLvl(int lvl) {
        this->lvl = lvl;
    }
    void Player::setXpcurent(int xpcurent) {
        this->xpcurent=xpcurent;
    }
    void Player::setXplevelup(int xplevelup) {
        this->xplvlup=xplevelup;
    }
    Player& Player::operator=(const Player& other) {
        if (this != &other) {
            pozx=other.pozx;
            pozy=other.pozy;
            hp = other.hp;
            lvl = other.lvl;
            abilitati = other.abilitati;
            xplvlup = other.xplvlup;
            xpcurent=other.xpcurent;
        }
        return *this;
    }
    Player::~Player() {
        std::cout << "Playerul a fost distrus" << std::endl;
    }

     std::ostream& operator<<(std::ostream& os, const Player& p) {
        os<<"Playerul este aici -> x: "<<p.pozx<<" "<<p.pozy << " Are hpul "<< p.hp<< " si lvl "<<p.lvl << " si xp  "<<p.xpcurent<<" din "<<p.xplvlup<<std::endl;
        return os;

    }
    void Player::move(float x, float y) {
        pozx += x;
        pozy += y;
    }
    void Player::hit( int dmg )
    {
        this->hp = this-> hp-dmg;
    }
    void Player::lvlup(int level) {
        this->lvl=this->lvl+level;
    }
    [[nodiscard]] bool Player::alive() const {
        return hp>0;
    }
    void Player::getKillXp(const Inamic& in) {
        this->xpcurent=this->xpcurent+in.getXp();
    }
    [[nodiscard]]bool Player::CheckXP() {
        if(this->xpcurent>this->xplvlup) {
            this->xpcurent=this->xpcurent-this->xplvlup;
            this->xplvlup=this->xplvlup+static_cast<int>(this->xplvlup*1.20);
            return true;
        }
        return false;
    }