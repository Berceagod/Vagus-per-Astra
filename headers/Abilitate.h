//
// Created by mihne on 11/7/2024.
//

#ifndef ABILITATE_H
#define ABILITATE_H
#include <string>


class Abilitate {
private:
    int damage;
    std::string name;
    int nivel;
public:
    Abilitate();
    Abilitate(const std::string &nume, int nivel, int damage);
    const std::string &getName();
    [[nodiscard]] int getNivel() const;
    [[nodiscard]]int getDamage() const;

    void setName(const std::string &name);
    void setNivel(int nivel);
    void setDamage(int damage);


    friend std::ostream& operator<<(std::ostream& os, const Abilitate& ab);

    Abilitate& operator=(const Abilitate& other);

    ~Abilitate();

};



#endif //ABILITATE_H