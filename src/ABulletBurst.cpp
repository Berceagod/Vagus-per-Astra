//
// Created by mihne on 12/2/2024.
//
#include "../headers/ABulletBurst.h"
#include <iostream>

ABulletBurst::ABulletBurst()=default;
ABulletBurst::ABulletBurst(const std::string &nume, int nivel, float damage, float cd)
    :Abilitate(nume,nivel,damage,cd){}
ABulletBurst::~ABulletBurst() {
    std::cout << "Bullet Burst ability has been destroyed" << std::endl;
}


