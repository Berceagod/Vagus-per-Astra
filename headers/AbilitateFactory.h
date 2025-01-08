//
// Created by mihne on 1/8/2025.
//

#ifndef ABILITATEFACTORY_H
#define ABILITATEFACTORY_H
#include "../headers/Abilitate.h"
#include "../headers/ABulletBurst.h"
#include "../headers/AdefaultGun.h"
#include "../headers/AElectricField.h"
#include "../headers/ANuke.h"
#include <iostream>

enum class TipAbilitate{BulletBurst,Default,ElectricField,Nuke};

std::shared_ptr<Abilitate> makeAbilitateFactory(TipAbilitate tip_abilitate);

#endif //ABILITATEFACTORY_H
