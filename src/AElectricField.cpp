//
// Created by mihne on 12/2/2024.
//
#include "../headers/AElectricField.h"
#include <iostream>
AElectricField::AElectricField() = default;
AElectricField::AElectricField(const std::string &nume, int nivel, float damage, float cd)
    :Abilitate(nume,nivel,damage,cd){}
AElectricField::~AElectricField() {
    std::cout<<"Electric Field ability has been destroyed "<<std::endl;
}


