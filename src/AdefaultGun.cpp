//
// Created by mihne on 11/26/2024.
//
#include "../headers/AdefaultGun.h"
#include <iostream>
AdefaultGun::AdefaultGun(const std::string &nume, int nivel, float damage, float cd)
    : Abilitate(nume,nivel,damage,cd){}
AdefaultGun::~AdefaultGun() {
    std::cout<<" Abilitatea default a fost distrusa";
}

