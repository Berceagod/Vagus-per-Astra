//
// Created by mihne on 12/2/2024.
//

#ifndef ABULLETBURST_H
#define ABULLETBURST_H

#include "Abilitate.h"

class ABulletBurst : public Abilitate {
public:
    ABulletBurst();
    ABulletBurst(const std::string &nume, int nivel, float damage,float cd);
    virtual ~ABulletBurst();
};
#endif //ABULLETBURST_H
