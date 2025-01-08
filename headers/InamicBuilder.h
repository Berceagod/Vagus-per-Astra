//
// Created by mihne on 1/8/2025.
//

#ifndef INAMICBUILDER_H
#define INAMICBUILDER_H

#include <string>
#include <iostream>

class Fighter {
private:
    std::string name;
    int health;
    int speed;
    int damage;

public:
    Fighter() : name(""), health(0), speed(0), damage(0) {}

    void setName(const std::string &name) { this->name = name; }
    void setHealth(int health) { this->health = health; }
    void setSpeed(int speed) { this->speed = speed; }
    void setDamage(int damage) { this->damage = damage; }

    void printInfo() const {
        std::cout << "Fighter: " << name
                  << ", Health: " << health
                  << ", Speed: " << speed
                  << ", Damage: " << damage << std::endl;
    }
};

class FighterBuilder {
protected:
    Fighter *fighter;

public:
    virtual ~FighterBuilder() = default;

    virtual void createFighter() = 0;
    virtual void buildHealth() = 0;
    virtual void buildSpeed() = 0;
    virtual void buildDamage() = 0;

    Fighter *getFighter() { return fighter; }
};

class StandardFighterBuilder : public FighterBuilder {
public:
    void createFighter() override;
    void buildHealth() override;
    void buildSpeed() override;
    void buildDamage() override;
};

class BattleshipBuilder : public FighterBuilder {
public:
    void createFighter() override;
    void buildHealth() override;
    void buildSpeed() override;
    void buildDamage() override;
};


class InaimcDirector {
public:
    Fighter *buildInamic(FighterBuilder *builder);
};


#endif //INAMICBUILDER_H
