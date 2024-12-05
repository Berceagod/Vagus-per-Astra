//
// Created by mihne on 11/7/2024.
//

#ifndef INAMIC_H
#define INAMIC_H
#include <string>


class Inamic{
private:
    int hp;
    std::string name;
    int dmg;
    int xp;
    static int Counter;
public:
    Inamic();
    Inamic(const std::string &name,int hp, int damage,int xp);
    [[nodiscard]] int getHp() const;
    std::string &getName();
    [[nodiscard]] int getDmg() const;
    [[nodiscard]] int getXp() const;

    void setName(const std::string &name);
    void setHp(int hp);
    void setDmg(int dmg);
    void setXp(int xp);
    static void CounterIncrement() ;
    friend std::ostream& operator<<(std::ostream& os, const Inamic& in);
    Inamic& operator=(const Inamic& other);

    void lvlup();

    ~Inamic();

};



#endif //INAMIC_H