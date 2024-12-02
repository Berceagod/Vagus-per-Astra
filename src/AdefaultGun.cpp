//
// Created by mihne on 11/26/2024.
//
#include "../headers/AdefaultGun.h"
#include <iostream>
AdefaultGun::AdefaultGun()=default;
AdefaultGun::AdefaultGun(const std::string &nume, int nivel, float damage, float cd)
    : Abilitate(nume,nivel,damage,cd){}

AdefaultGun::~AdefaultGun() {
    std::cout<<"Default ability has been destroyed"<<std::endl;
}
std::unique_ptr<Abilitate> AdefaultGun::clone() const {
    return std::make_unique<AdefaultGun>(*this);
}
void AdefaultGun::ExecuteEffect() {
    std::cout << "Executing Bullet Burst: A burst of bullets deals "<< std::endl;
}
void AdefaultGun::LoadTextr() {
    texture=LoadTexture("../Textures/Default_Texture.jpg");
}
