//
// Created by mihne on 11/7/2024.
//

#ifndef INAMIC_H
#define INAMIC_H
#include <string>
#include <string>
#include <iostream>

template <typename DmgType>
class Inamic {
private:
    int hp;
    std::string name;
    DmgType dmg; // Tipul general pentru damage
    int xp;
    static int Counter;

public:
    Inamic();
    Inamic(const std::string &name, int hp, DmgType damage, int xp);

    [[nodiscard]] int getHp() const;
    std::string &getName();
    [[nodiscard]] DmgType getDmg() const;
    [[nodiscard]] int getXp() const;

    void setName(const std::string &name);
    void setHp(int hp);
    void setDmg(DmgType dmg);
    void setXp(int xp);

    static void CounterIncrement();

    friend std::ostream &operator<<(std::ostream &os, const Inamic &in) {
        os << "Inamicul cu nume " << in.name
           << " cu hp-ul de " << in.hp
           << " si damage-ul " << in.dmg
           << " si da xp-ul: " << in.xp << std::endl;
        return os;
    }

    Inamic &operator=(const Inamic &other);

    void lvlup();

    ~Inamic();
};



#endif //INAMIC_H