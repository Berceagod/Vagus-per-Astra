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
std::unique_ptr<Abilitate> ABulletBurst::clone() const {
    return std::make_unique<ABulletBurst>(*this);
}
void ABulletBurst::ExecuteEffect() {
    std::cout << "Executing Bullet Burst: A burst of bullets deals "<< std::endl;
}
void ABulletBurst::LoadTextr() {
    texture=LoadTexture("../Textures/Default_Texture.jpg");
}

