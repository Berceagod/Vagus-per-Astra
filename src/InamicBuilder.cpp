#include "../headers/InamicBuilder.h"

// StandardFighterBuilder
void StandardFighterBuilder::createFighter() {
    fighter = new Fighter();
    fighter->setName("Standard Fighter");
}

void StandardFighterBuilder::buildHealth() {
    fighter->setHealth(100);
}

void StandardFighterBuilder::buildSpeed() {
    fighter->setSpeed(50);
}

void StandardFighterBuilder::buildDamage() {
    fighter->setDamage(30);
}

// BattleshipBuilder
void BattleshipBuilder::createFighter() {
    fighter = new Fighter();
    fighter->setName("Battleship");
}

void BattleshipBuilder::buildHealth() {
    fighter->setHealth(300);
}

void BattleshipBuilder::buildSpeed() {
    fighter->setSpeed(20);
}

void BattleshipBuilder::buildDamage() {
    fighter->setDamage(50);
}

// FighterDirector
Fighter *InaimcDirector::buildInamic(FighterBuilder *builder) {
    builder->createFighter();
    builder->buildHealth();
    builder->buildSpeed();
    builder->buildDamage();
    return builder->getFighter();
}

