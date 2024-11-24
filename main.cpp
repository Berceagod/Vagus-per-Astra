#include <iostream>
///#include <array>
#include <chrono>
#include <sstream>
///#include <setjmp.h>
#include "./headers/Inamic.h"
#include "./headers/Abilitate.h"
#include "./headers/Player.h"
#include "./headers/Game.h"
#include "raylib.h"


int main() {

    // 800x450 is 16:9
    InitWindow(800, 450, "Raylib");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(SKYBLUE);

        EndDrawing();
    }

    CloseWindow();


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