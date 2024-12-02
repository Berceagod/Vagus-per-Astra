//
// Created by mihne on 12/2/2024.
//
#include "../headers/ANuke.h"
#include <iostream>
ANuke::ANuke()=default;
ANuke::ANuke(const std::string &nume, int nivel, float damage, float cd)
    : Abilitate(nume,nivel,damage,cd){}
ANuke::~ANuke() {
    std::cout<<"Nuke ability has been destroyed "<<std::endl;
}
std::unique_ptr<Abilitate> ANuke::clone() const {
    return std::make_unique<ANuke>(*this);
}
void ANuke::ExecuteEffect() {
    std::cout << "Executing Bullet Burst: A burst of bullets deals "<< std::endl;
}
void ANuke::LoadTextr() {
    texture=LoadTexture("../Textures/Default_Texture.jpg");
}

