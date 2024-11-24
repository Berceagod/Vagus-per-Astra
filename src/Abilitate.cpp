//
// Created by mihne on 11/7/2024.
//

#include "../headers/Abilitate.h"
#include <iostream>
    Abilitate::Abilitate() {
        this->damage=0;
        std::string name="nu exista";
        this->nivel=0;
    };
Abilitate::Abilitate(const std::string &nume, int nivel, int damage) {
    this->name = nume;
    this->nivel = nivel;
    this->damage = damage;
}
const std::string &Abilitate::getName() {
    return this->name;
}
[[nodiscard]] int Abilitate::getNivel() const {
    return this->nivel;
}
[[nodiscard]]int Abilitate::getDamage() const {
    return this->damage;
}

void Abilitate::setName(const std::string &name) {
    this->name = name;
}
void Abilitate::setNivel(int nivel) {
    this->nivel = nivel;
}
void Abilitate::setDamage(int damage) {
    this->damage = damage;
}


std::ostream& operator<<(std::ostream& os, const Abilitate& ab) {
    os<<"Nume abilitate :"<<ab.name<<" cu nivelul "<<ab.nivel<<" si damage "<<ab.damage<<std::endl;
    return os;
}

Abilitate& Abilitate::operator=(const Abilitate& other)=default;

Abilitate::~Abilitate() {
    std::cout << "Abilitate distrusa" << std::endl;
}