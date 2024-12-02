//
// Created by mihne on 11/7/2024.
//

#include "../headers/Inamic.h"
#include <iostream>
int Inamic::Counter = 0;
    Inamic::Inamic() {
        this->hp=0;
        this->xp = 0;
        this->name="Nu exista";
        this->dmg=0;
    };
Inamic::Inamic(const std::string &name,int hp, int damage,int xp) {
    this->name = name;
    this->hp = hp;
    this->dmg = damage;
    this->xp=xp;
}
[[nodiscard]] int Inamic::getHp() const {
    return hp;
}
std::string &Inamic::getName() {
    return name;
}
[[nodiscard]] int Inamic::getDmg() const {
    return dmg;
}
[[nodiscard]] int Inamic::getXp() const {
    return xp;
}
void Inamic::setName(const std::string &name) {
    this->name = name;
}
void Inamic::setHp(int hp) {
    this->hp = hp;
}
void Inamic::setDmg(int dmg) {
    this->dmg = dmg;
}
void Inamic::setXp(int xp) {
    this->xp = xp;
}
std::ostream& operator<<(std::ostream& os, const Inamic& in) {
    os<<"Inamicul cu nume "<<in.name<<" cu hp ul de "<<in.hp<<" si damageul "<<in.dmg<<" si da xp-ul : "<<in.xp<<std::endl;
    return os;
}
Inamic& Inamic::operator=(const Inamic& other) {
    if (this != &other) {
        hp=other.hp;
        name=other.name;
        dmg=other.dmg;
        xp=other.xp;
    }
    return *this;

}
void Inamic::lvlup() {
    this->hp = this->hp+static_cast<int>(this->hp*0.10);
    this->dmg = this->dmg+1;
}

void Inamic::CounterIncrement() {
    Counter++;
}


Inamic::~Inamic() {
    std::cout << "Inamic distrus " << std::endl;
};