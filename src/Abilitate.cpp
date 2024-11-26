//
// Created by mihne on 11/7/2024.
//

#include "../headers/Abilitate.h"
#include <iostream>
    Abilitate::Abilitate() {
        this->damage=0;
        std::string name="nu exista";
        this->nivel=0;
        this->cd=0;
    };
Abilitate::Abilitate(const std::string &nume, int nivel, float damage, float cd) {
    this->name = nume;
    this->nivel = nivel;
    this->damage = damage;
    this->cd = cd;
}
const std::string &Abilitate::getName() {
    return this->name;
}
[[nodiscard]] int Abilitate::getNivel() const {
    return this->nivel;
}
[[nodiscard]]float Abilitate::getDamage() const {
    return this->damage;
}
[[nodiscard]]float Abilitate::getCd() const {
    return this->cd;
}

void Abilitate::setName(const std::string &name) {
    this->name = name;
}
void Abilitate::setNivel(int nivel) {
    this->nivel = nivel;
}
void Abilitate::setDamage(float damage) {
    this->damage = damage;
}
void Abilitate::setCd(float cd) {
    this->cd = cd;
}

std::ostream& operator<<(std::ostream& os, const Abilitate& ab) {
    os<<"Nume abilitate :"<<ab.name<<" cu nivelul "<<ab.nivel<<" si damage "<<ab.damage<<std::endl<<" si cooldown : "<<ab.cd<<std::endl;
    return os;
}

Abilitate& Abilitate::operator=(const Abilitate& other)=default;

 Abilitate::~Abilitate() {
    std::cout << "Abilitate distrusa" << std::endl;
}