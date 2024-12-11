#include "../headers/Game.h"
#include <iostream>
#include <math.h>
#include "raylib.h"
#include "../headers/AdefaultGun.h"

#define width 800   //Dimensiunile ecranului
#define height 600
Game::Game() {
    std::cout << "Jocul a fost creat" << std::endl;
    camera = {0};
}

void Game::addPlayer(const Player &p) {
    player = p;
}

void Game::Start() {
    std::cout << "Jocul a inceput" << std::endl;
    bulletTexture=LoadTexture("../Textures/Default_Texture.jpg");
    InitAudioDevice();
    camera.target = (Vector2){player.getPozx(), player.getPozy()}; // Start camera on player
    camera.offset = (Vector2){800 / 2, 600 / 2};                   // Center camera on screen
    camera.rotation = 0.0f;
    camera.zoom = 1.0f; // Start at normal zoom
}

Game::~Game() {
    std::cout << "Jocul a fost distrus" << std::endl;
}

void Game::Draw(Texture2D &background) {
    BeginMode2D(camera);

    // Draw the background
    DrawTextureEx(
        background,
        Vector2{-camera.target.x * 0.1f, -camera.target.y * 0.1f}, // Parallax offset
        0.0f,
        10.0f, // Scale factor
        WHITE);

    // Draw the player
    player.Draw();
    for (auto &bullet : bullets) {
        bullet.Draw();
    }
    EndMode2D();
}
void Game::HandleInput() {
    // Player controls
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
        player.RotateRight();
    }
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
        player.RotateLeft();
    }

    player.setSpeed(sin(player.getRotation() * DEG2RAD) * player.getdefspeed(),
                    -cos(player.getRotation() * DEG2RAD) * player.getdefspeed());

    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
        player.MoveForward();
    } else
        player.SlowDown();

    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) {
        player.MoveBackward();
    } else
        player.SlowDown();

    if (IsKeyDown(KEY_E)) {
        player.PlayerStrafeRight();
    }
    if (IsKeyDown(KEY_Q)) {
        player.PlayerStrafeLeft();
    }
    if (IsKeyDown(KEY_T)) {
        try {
            player.addAbility(new AdefaultGun());
        }catch (const AbilityAlreadyThere& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;

        }catch (const AbilityMaxLevelExceeded& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    }
    player.AbilitiesCheck();

try {
    player.setPozx(player.getPozx() + (player.getspeedx() * player.getAccel()));
    player.setPozy(player.getPozy() + (player.getspeedy() * player.getAccel()));
    if(player.getPozy()<0.0f||player.getPozx()<0||player.getPozx()>2000||player.getPozy()>2000)
    {
        throw OutOfBounds();
    }
}catch(const OutOfBounds& e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
};
    // Camera updates
    camera.target=(Vector2){0,0};
    // camera.target = (Vector2){player.getPozx(), player.getPozy()};
    camera.offset=(Vector2){-player.getPozx()+width/2.0f, -player.getPozy()+height/2.0f};
    camera.zoom += ((float)GetMouseWheelMove() * 0.05f);

    // Clamp zoom values
    if (camera.zoom > 3.0f)
        camera.zoom = 3.0f;
    else if (camera.zoom < 0.1f)
        camera.zoom = 0.1f;

   /// Camera lock in:
      if(camera.offset.x>0) {
          camera.offset.x = 0;
      }
     if(camera.offset.y>0) {
         camera.offset.y=0;
     }
    if(camera.offset.x < -1200) {
        camera.offset.x= -1200;
    }
    if(camera.offset.y <-1400) {
        camera.offset.y= -1400;
    }

    // Reset zoom and rotation
    if (IsKeyPressed(KEY_R)) {
        camera.zoom = 1.0f;
        camera.rotation = 0.0f;
        player.setPozx(900);
        player.setPozy(900);
    }

    if (IsKeyDown(KEY_F)) {
        std::cout << "Coordonatele sunt: " << player.getPozx() << " " << player.getPozy() << std::endl;
        std::cout<<" Camera are offset pe x de: "<<camera.offset.x<<"Si pe y de : "<<camera.offset.y<<std::endl;
    }

///BUllet logic
    if(IsKeyDown(KEY_SPACE)) {
        bullets.emplace_back(
        Vector2{player.getPozx(), player.getPozy()},
        10, // Speed
        player.getRotation(),
        bulletTexture
        );
    }
    for (auto it = bullets.begin(); it != bullets.end(); ) {
        it->Update();
        if (it->getPozX() < 0 || it->getPozY() < 0 ||
            it->getPozX() > 2000 || it->getPozY() > 2000) {
            it = bullets.erase(it);
            } else {
                ++it;
            }
    }

}

void Game::ShutDown() {
    CloseAudioDevice();
    UnloadTexture(bulletTexture);
}

float Game::getCameraTargetx() {
    return camera.target.x;
}
float Game::getCameraTargety() {
    return camera.target.y;
}
float Game::getCameraZoom() {
    return camera.zoom;
}
