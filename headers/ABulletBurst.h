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

    [[nodiscard]]std::unique_ptr<Abilitate> clone() const override;
    void ExecuteEffect() override;
    void LoadTextr() override;
    ~ABulletBurst() override;

};
#endif //ABULLETBURST_H
