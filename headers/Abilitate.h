//
// Created by mihne on 11/7/2024.
//

#ifndef ABILITATE_H
#define ABILITATE_H
#include <string>
#include <memory>
#include "raylib.h"

class Abilitate {
private:
    float damage;
    std::string name;
    int nivel;
    float cd;
protected:
    Texture2D texture;
public:
    Abilitate();
    Abilitate(const std::string &nume, int nivel, float damage,float cd);
    const std::string &getName();
    [[nodiscard]] int getNivel() const;
    [[nodiscard]]float getDamage() const;
    [[nodiscard]]float getCd() const;

    void setName(const std::string &name);
    void setNivel(int nivel);
    void setDamage(float damage);
    void setCd(float cd);



    ///Non-Virtual interfaces xoxo

    void Draw();

    ///Virtual methods 0_0

    [[nodiscard]]virtual std::unique_ptr<Abilitate> clone() const=0;
    virtual void ExecuteEffect() = 0;
    virtual ~Abilitate();
    virtual void LoadTextr()=0;


};


#endif //ABILITATE_H