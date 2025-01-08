//
// Created by mihne on 11/7/2024.
//

#include "../headers/Inamic.h"
#include <iostream>
//
// Created by mihne on 11/7/2024.
//

#include "../headers/Inamic.h"
#include <iostream>
// Inițializarea membrului static
// Inițializarea membrului static
template <typename DmgType>
int Inamic<DmgType>::Counter = 0;

// Constructor implicit
template <typename DmgType>
Inamic<DmgType>::Inamic()
    : hp(0), name("Nu exista"), dmg(0), xp(0) {}

// Constructor parametrizat
template <typename DmgType>
Inamic<DmgType>::Inamic(const std::string &name, int hp, DmgType damage, int xp)
    : name(name), hp(hp), dmg(damage), xp(xp) {}

// Getter pentru hp
template <typename DmgType>
int Inamic<DmgType>::getHp() const {
    return hp;
}

// Getter pentru name
template <typename DmgType>
std::string &Inamic<DmgType>::getName() {
    return name;
}

// Getter pentru dmg
template <typename DmgType>
DmgType Inamic<DmgType>::getDmg() const {
    return dmg;
}

// Getter pentru xp
template <typename DmgType>
int Inamic<DmgType>::getXp() const {
    return xp;
}

// Setter pentru name
template <typename DmgType>
void Inamic<DmgType>::setName(const std::string &name) {
    this->name = name;
}

// Setter pentru hp
template <typename DmgType>
void Inamic<DmgType>::setHp(int hp) {
    this->hp = hp;
}

// Setter pentru dmg
template <typename DmgType>
void Inamic<DmgType>::setDmg(DmgType dmg) {
    this->dmg = dmg;
}

// Setter pentru xp
template <typename DmgType>
void Inamic<DmgType>::setXp(int xp) {
    this->xp = xp;
}

// Incrementarea contorului static
template <typename DmgType>
void Inamic<DmgType>::CounterIncrement() {
    Counter++;
}

// Operator de atribuire
template <typename DmgType>
Inamic<DmgType> &Inamic<DmgType>::operator=(const Inamic &other) {
    if (this != &other) {
        hp = other.hp;
        name = other.name;
        dmg = other.dmg;
        xp = other.xp;
    }
    return *this;
}

// Nivel în sus
template <typename DmgType>
void Inamic<DmgType>::lvlup() {
    this->hp += static_cast<int>(this->hp * 0.10);
    this->dmg += static_cast<DmgType>(1);
}

// Destructor
template <typename DmgType>
Inamic<DmgType>::~Inamic() {
    std::cout << "Inamic distrus " << std::endl;
}