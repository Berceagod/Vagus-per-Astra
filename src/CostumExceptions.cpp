//
// Created by mihne on 12/2/2024.
//
#include "../headers/CostumExceptions.h"
#include <iostream>
const char* AbilityAlreadyThere::what() const noexcept {
    return "Ability is already added to the array";
}