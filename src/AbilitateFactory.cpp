//
// Created by mihne on 1/8/2025.
//
#include "../headers/AbilitateFactory.h"
std::shared_ptr<Abilitate> makeAbilitateFactory(TipAbilitate tip_abilitate) {
    if (tip_abilitate == TipAbilitate::BulletBurst) {
        return std::make_shared<ABulletBurst>();
    }
    if (tip_abilitate == TipAbilitate::Default) {
        return std::make_shared<AdefaultGun>();
    }
    if (tip_abilitate == TipAbilitate::ElectricField) {
        return std::make_shared<AElectricField>();
    }
    if (tip_abilitate == TipAbilitate::Nuke) {
        return std::make_shared<ANuke>();
    }

    return nullptr;
}