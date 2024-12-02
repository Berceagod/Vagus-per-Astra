//
// Created by mihne on 12/2/2024.
//
#include "../headers/AElectricField.h"
#include <iostream>
AElectricField::AElectricField() = default;
AElectricField::AElectricField(const std::string &nume, int nivel, float damage, float cd)
    :Abilitate(nume,nivel,damage,cd){}

std::unique_ptr<Abilitate> AElectricField::clone() const {
    return std::make_unique<AElectricField>(*this);
}
void AElectricField::ExecuteEffect() {
    std::cout << "Executing Bullet Burst: A burst of bullets deals "<< std::endl;
}

void AElectricField::LoadTextr() {
    texture=LoadTexture("../Textures/Default_Texture.jpg");
}

AElectricField::~AElectricField() {
    std::cout<<"Electric Field ability has been destroyed "<<std::endl;
}




