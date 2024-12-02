//
// Created by mihne on 12/2/2024.
//

#ifndef ANUKE_H
#define ANUKE_H

#include "Abilitate.h"

class ANuke : public Abilitate {
public:
    ANuke();
    ANuke(const std::string &nume, int nivel, float damage,float cd);
    virtual ~ANuke();
};

#endif //ANUKE_H
