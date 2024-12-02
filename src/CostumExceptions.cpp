//
// Created by mihne on 12/2/2024.
//
#include "../headers/CostumExceptions.h"
#include <iostream>

AbilityAlreadyThere::AbilityAlreadyThere(int level) {
    this->currlevel = level;
    this->msg="Ability already there with the level "+std::to_string(level);
}


const char* AbilityAlreadyThere::what() const noexcept {
    return msg.c_str();
}

AbilityMaxLevelExceeded::AbilityMaxLevelExceeded(int level) {
    this->currlevel = level;
    this->msg="Ability max level reached , Ability is maxed at : "+std::to_string(level);
}
const char* AbilityMaxLevelExceeded::what() const noexcept {
    return msg.c_str();
}

const char* OutOfBounds::what() const noexcept {
    return "Player out of bounds ";
}
