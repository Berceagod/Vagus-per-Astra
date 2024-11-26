//
// Created by mihne on 11/7/2024.
//

#ifndef ABILITATE_H
#define ABILITATE_H
#include <string>


class Abilitate {
private:
    float damage;
    std::string name;
    int nivel;
    float cd;
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

    friend std::ostream& operator<<(std::ostream& os, const Abilitate& ab);

    Abilitate& operator=(const Abilitate& other);

    virtual ~Abilitate();

};



#endif //ABILITATE_H