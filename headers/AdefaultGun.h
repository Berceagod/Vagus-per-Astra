//
// Created by mihne on 11/26/2024.
//

#ifndef ADEFAULTGUN_H
#define ADEFAULTGUN_H

#include "Abilitate.h"

class AdefaultGun: public Abilitate {
    public:
    AdefaultGun();
    AdefaultGun(const std::string &nume, int nivel, float damage,float cd);

    [[nodiscard]]std::unique_ptr<Abilitate> clone() const override;
    void ExecuteEffect() override;
    void LoadTextr() override;
    ~AdefaultGun() override;
};



#endif //ADEFAULTGUN_H
