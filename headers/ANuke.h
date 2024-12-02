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
    [[nodiscard]]std::unique_ptr<Abilitate> clone() const override;
    void ExecuteEffect() override;
    void LoadTextr() override;
     ~ANuke() override;

};

#endif //ANUKE_H
