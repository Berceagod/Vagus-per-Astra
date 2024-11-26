//
// Created by mihne on 11/26/2024.
//

#ifndef ADEFAULTGUN_H
#define ADEFAULTGUN_H

#include "Abilitate.h"

class AdefaultGun: public Abilitate {
    public:
    AdefaultGun(const std::string &nume, int nivel, float damage,float cd);
    virtual ~AdefaultGun();
};



#endif //ADEFAULTGUN_H
