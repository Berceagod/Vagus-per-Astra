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
#include "raymath.h"

// Camera2D camera = { 0 };
//
 const int screenWidth =  800;
 const int screenHeight = 600;
//
// void GameStartup() {
//     InitAudioDevice();
//     camera.target=(Vector2) {0,0};
//     camera.offset=(Vector2) {(float)screenWidth/2,(float)screenHeight/2};
//     camera.rotation=0.0f;
//     camera.zoom=3.0f;
// }
// void GameUpdate()
// {
//     float wheel= GetMouseWheelMove();
//     if (wheel!=0) {
//         const float zoomIncrement=0.125f;
//         camera.zoom+=(wheel*zoomIncrement);
//     }
//     camera.target=(Vector2) {0,0};
// }
// void GameRender()
// {
//     BeginMode2D(camera);
//
//     EndMode2D();
// }
// void GameShutdown() {
//     CloseAudioDevice();
// }



int main() {


    // Inamic in1("Overlord",30,5,105);
    // Player jucator(300,400,100,1,200,0);
    // std::cout<<jucator<<std::endl;
    // jucator.move(10 , 9);
    // jucator.hit(10);
    // jucator.lvlup(1);
    // jucator.getKillXp(in1);
    // if(jucator.CheckXP()==true)
    //     jucator.lvlup(1);
    // std::cout<<jucator<<std::endl;
    // jucator.getKillXp(in1);
    // if(jucator.CheckXP()==true)
    //     jucator.lvlup(1);
    // std::cout<<jucator<<std::endl;
    // jucator.getKillXp(in1);
    // if(jucator.CheckXP()==true)
    //     jucator.lvlup(1);
    // jucator.getKillXp(in1);
    // if(jucator.CheckXP()==true)
    //     jucator.lvlup(1);
    // jucator.getKillXp(in1);
    // if(jucator.CheckXP()==true)
    //     jucator.lvlup(1);
    // std::cout<<jucator<<std::endl;
    //
    // Inamic in3("Overlord",30,5,605);
    // jucator.getKillXp(in3);
    // if(jucator.CheckXP()==true)
    //     jucator.lvlup(1);
    // std::cout<<jucator<<std::endl;
    //
    // Abilitate Spell1("Small Bullet",1,5,2);
    // std::cout<<Spell1<<std::endl;
    // Abilitate Spell2("Big Bullet",1,20,4);
    // std::cout<<Spell2<<std::endl;
    //
    // Inamic in2("Hivemind",30,5,25);
    // std::cout<<in1<<std::endl;
    //
    // Game joc;
    // joc.addPlayer(jucator);
    // Game::Start();
    //



    // 800x450 is 16:9
    InitWindow(screenWidth, screenHeight, "Vagus per Astra");
    SetTargetFPS(60);
    Color Lightblue=Color(173,216,230,255);
    Texture2D background = LoadTexture("../Textures/Space_Background.png");



    Game game;

    // GameStartup();
    game.Start();



    while (!WindowShouldClose()) {

         game.HandleInput();
        // GameUpdate();

        BeginDrawing();
         ClearBackground(Lightblue);
         // DrawTextureEx(background, Vector2{0,0},0, 6, WHITE);

        Vector2 backgroundOffset = {
         game.getCameraTargetx() - screenWidth / game.getCameraZoom(),
         game.getCameraTargety() - screenHeight / game.getCameraZoom()
        };
        float scale = 10.0f * game.getCameraZoom();
        DrawTextureEx(background, Vector2{-backgroundOffset.x, -backgroundOffset.y}, 0, scale, WHITE);

         game.Draw();

        EndDrawing();
    }
    UnloadTexture(background);
    game.ShutDown();
    CloseWindow();


        return 0;
    }