#include "../headers/Game.h"
#include <iostream>
#include <math.h>
#include "raylib.h"
#include "../headers/AdefaultGun.h"


Game::Game() {
    std::cout << "Jocul a fost creat" << std::endl;
    camera = {0};
}

void Game::addPlayer(const Player &p) {
    player = p;
}

void Game::Start() {
    std::cout << "Jocul a inceput" << std::endl;
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
        }
    }
    player.AbilitiesCheck();


    player.setPozx(player.getPozx() + (player.getspeedx() * player.getAccel()));
    player.setPozy(player.getPozy() + (player.getspeedy() * player.getAccel()));

    // Camera updates
    camera.target = (Vector2){player.getPozx(), player.getPozy()};
    camera.zoom += ((float)GetMouseWheelMove() * 0.05f);

    // Clamp zoom values
    if (camera.zoom > 3.0f)
        camera.zoom = 3.0f;
    else if (camera.zoom < 0.1f)
        camera.zoom = 0.1f;

    // Reset zoom and rotation
    if (IsKeyPressed(KEY_R)) {
        camera.zoom = 1.0f;
        camera.rotation = 0.0f;
        player.setPozx(900);
        player.setPozy(900);
    }

    std::cout << "Coordonatele sint: " << player.getPozx() << " " << player.getPozy() << std::endl;
}

void Game::ShutDown() {
    CloseAudioDevice();
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
