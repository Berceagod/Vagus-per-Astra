#include <iostream>
///#include <array>
#include <chrono>
#include <thread>
#include <Helper.h>
#include <sstream>
///#include <setjmp.h>
#include "./headers/Inamic.h"
#include "./headers/Abilitate.h"
#include "./headers/Player.h"
#include "./headers/Game.h"



int main() {

    Inamic in1("Overlord",30,5,105);
    Player jucator(300,400,100,1,200,0);
    std::cout<<jucator<<std::endl;
    jucator.move(10 , 9);
    jucator.hit(10);
    jucator.lvlup(1);
    jucator.getKillXp(in1);
    if(jucator.CheckXP()==true)
        jucator.lvlup(1);
    std::cout<<jucator<<std::endl;
    jucator.getKillXp(in1);
    if(jucator.CheckXP()==true)
        jucator.lvlup(1);
    std::cout<<jucator<<std::endl;
    jucator.getKillXp(in1);
    if(jucator.CheckXP()==true)
        jucator.lvlup(1);
    jucator.getKillXp(in1);
    if(jucator.CheckXP()==true)
        jucator.lvlup(1);
    jucator.getKillXp(in1);
    if(jucator.CheckXP()==true)
        jucator.lvlup(1);
    std::cout<<jucator<<std::endl;

    Inamic in3("Overlord",30,5,605);
    jucator.getKillXp(in3);
    if(jucator.CheckXP()==true)
        jucator.lvlup(1);
    std::cout<<jucator<<std::endl;

    Abilitate Spell1("Small Bullet",1,5);
    std::cout<<Spell1<<std::endl;
    Abilitate Spell2("Big Bullet",1,20);
    std::cout<<Spell2<<std::endl;

    Inamic in2("Hivemind",30,5,25);
    std::cout<<in1<<std::endl;

    Game joc;
    joc.addPlayer(jucator);
    Game::Start();



        return 0;
    }