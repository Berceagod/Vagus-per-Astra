#include <iostream>
#include <array>
#include <chrono>
#include <sstream>
///#include <setjmp.h>
#include "./headers/Inamic.h"
#include "./headers/Abilitate.h"
#include "./headers/Player.h"
#include "./headers/Game.h"
#include "./headers/ANuke.h"
#include "./headers/AdefaultGun.h"
#include "./headers/AElectricField.h"
#include "raylib.h"
#include "raymath.h"
#include "headers/ABulletBurst.h"
#include "headers/Bullet.h"
int main() {
 const int screenWidth =  800;
 const int screenHeight = 600;
// a

 InitWindow(screenWidth, screenHeight, "Vagus per Astra");
 SetTargetFPS(60);

 Texture2D background = LoadTexture("../Textures/Space_Background.png");
 Texture2D background2 = LoadTexture("../Textures/Space_Background2.png");
 Texture2D background3 = LoadTexture("../Textures/Space_Background3.png");
 Texture2D background4 = LoadTexture("../Textures/Space_Background4.png");
 Game game;
 game.Start();

 while (!WindowShouldClose()) {
  game.HandleInput();

  BeginDrawing();
  ClearBackground(BLACK);

  // Draw everything inside the camera
  game.Draw(background4);

  EndDrawing();
 }
 UnloadTexture(background);
 UnloadTexture(background2);
 UnloadTexture(background3);
 UnloadTexture(background4);
 game.ShutDown();
 CloseWindow();
 ANuke b;
 AdefaultGun c;
 AElectricField d;
 ABulletBurst e;
 std::cout<<"AAAAAAA HEIGHT: "<<background.height<<"AAAAA WIDTH"<<background.width<<std::endl;
 return 0;
}

