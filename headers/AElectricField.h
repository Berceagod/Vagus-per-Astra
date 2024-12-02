//
// Created by mihne on 12/2/2024.
//

#ifndef AELECTRICFIELD_H
#define AELECTRICFIELD_H

#include "Abilitate.h"

class AElectricField : public Abilitate {
public:
    AElectricField();
    AElectricField(const std::string &nume, int nivel, float damage,float cd);

    [[nodiscard]]std::unique_ptr<Abilitate> clone() const override;
    void ExecuteEffect() override;
    void LoadTextr() override;
     ~AElectricField() override;
};
#endif //AELECTRICFIELD_H
