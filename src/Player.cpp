//
// Created by mihne on 11/7/2024.
//

#include "../headers/Player.h"
#include <iostream>
#include <math.h>

#include "../headers/AdefaultGun.h"

Player::Player() {
        this->pozx= 0;
        this->pozy= 0;
        this->lvl = 0;
        ///this->abilitati = std::vector<Abilitate>();
        this->hp=0;
        this->xplvlup=200;
        this->xpcurent=0;
        image = LoadTexture("../Textures/Spaceship.png");
        position.x=(GetScreenWidth()-image.width)/2;
        position.y=(GetScreenHeight()-image.height)/2;
        speed=Vector2{0,0};
        acceleration=0.0;
        rotation=0.0;
        Player_Size=20.0;
        shipHeight = (Player_Size/2)/tanf(20*DEG2RAD);
        collider = (Vector3){position.x + sin(rotation*DEG2RAD)*(shipHeight/2.5f), position.y - cos(rotation*DEG2RAD)*(shipHeight/2.5f), 12};
        DefSpeed = 3;
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

    [[nodiscard]] Vector2 Player::getPozitie() const {
        return position;
    }
    [[nodiscard]] Vector2  Player::getSpeed() const {
        return speed;
    }
    [[nodiscard]] float Player::getRotation() const {
        return rotation;
    }
    [[nodiscard]] float Player::getdefspeed() const {
        return DefSpeed;
    }
    [[nodiscard]] float Player::getspeedx() const {
        return speed.x;
    }
    [[nodiscard]] float Player::getspeedy() const {
        return speed.y;
    }
     [[nodiscard]] float Player::getPozx() const {
        return position.x;
    }
     [[nodiscard]] float Player::getPozy() const {
        return position.y;
    }
    [[nodiscard]] float Player::getAccel() const {

        return acceleration;
    }



    // std::vector<Abilitate> &Player::getAbilitati() {
    //     return abilitati;
    // }
    // void Player::addAbilitate(const Abilitate &abilitate) {
    //     abilitati.push_back(abilitate);
    // }

    void Player::setPozitie(Vector2 position) {
        this->position=position;
    }
    void Player::setSpeed(float speedx, float speedy) {
        this->speed.x=speedx;
        this->speed.y=speedy;
    }

    void Player::setPozx(float x) {
        this->position.x=x;
    }
    void Player::setPozy(float y) {
        this->position.y=y;
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
            ///abilitati = other.abilitati;
            xplvlup = other.xplvlup;
            xpcurent=other.xpcurent;
        }
        return *this;
    }
    Player::~Player() {
        std::cout << "Playerul a fost distrus" << std::endl;
        for(Abilitate* abilitate : abilitati) {
            delete abilitate;
        }
        UnloadTexture(image);
    }

    void Player::addAbility(Abilitate* abilitate) {
        for (Abilitate* a : abilitati) {
            if (typeid(*a) == typeid(*abilitate)) {
                throw AbilityAlreadyThere();
            }
        }
        abilitati.push_back(abilitate);
    }
    void Player::AbilitiesCheck() const {
        for (Abilitate* abilitate : abilitati) {
            AdefaultGun* abilitateA = dynamic_cast<AdefaultGun*>(abilitate);
            if (abilitateA) {
                std::cout << "Abilitatea A a fost gasita!" << std::endl;
            }
        }

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






void Player::Draw() {
        Rectangle sourceRect = { 0.0f, 0.0f, (float)image.width, (float)image.height };
        Rectangle destRect = { position.x, position.y, (float)image.width, (float)image.height };
        Vector2 origin = { (float)image.width / 2, (float)image.height / 2 };
        DrawTexturePro(image, sourceRect, destRect, origin, rotation, WHITE);
}
void Player::MoveForward() {
        if (acceleration < 1) acceleration += 0.04f;
}
void Player::MoveBackward() {
        if (acceleration > -1) acceleration -= 0.24f;

    }
void Player::RotateLeft() {
    rotation -=1.5;
}
void Player::RotateRight() {
    rotation +=1.5;
}
void Player::SlowDown() {
        if (acceleration > 0) acceleration -= 0.02f;
        else if (acceleration < 0) acceleration = 0;
}
void Player::PlayerStrafeLeft() {
        position.x -= (cos(rotation * DEG2RAD) * DefSpeed)/4;
        position.y -= (sin(rotation * DEG2RAD) * DefSpeed) /4;
}
void Player::PlayerStrafeRight() {
        position.x += ( cos(rotation * DEG2RAD) * DefSpeed)/4;
        position.y += ( sin(rotation * DEG2RAD) * DefSpeed)/4;
    }


