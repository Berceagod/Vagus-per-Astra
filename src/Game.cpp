//
// Created by mihne on 11/7/2024.
//

#include "../headers/Game.h"
#include <iostream>
#include <math.h>
    Game::Game() {
        std::cout<<"Jocul a fost creat"<<std::endl;
        camera = {0};
        camera.target = (Vector2){player.getPozx(),player.getPozy()};
        camera.rotation=0.0f;
        camera.zoom=2.0f;


    }
void Game::addPlayer(const Player &p) {
        player=p;
    }
void Game::Start()  {
        std::cout<<"Jocul a inceput "<<std::endl;
    }
Game::~Game() {
        std::cout<<"Jocul a fost distrus "<<std::endl;
    }
void Game::Draw() {

        player.Draw();

    }
void Game::HandleInput() {
    ///PLAYER
         if (IsKeyDown(KEY_D)||IsKeyDown(KEY_RIGHT)) {
            player.RotateRight();
        }
         if (IsKeyDown(KEY_A)||IsKeyDown(KEY_LEFT)) {
            player.RotateLeft();
        }


        player.setSpeed(sin(player.getRotation()*DEG2RAD)*player.getdefspeed(),-cos(player.getRotation()*DEG2RAD)*player.getdefspeed());

        if (IsKeyDown(KEY_W)||IsKeyDown(KEY_UP)) {
            player.MoveForward();
        }
        else player.SlowDown();
         if (IsKeyDown(KEY_S)||IsKeyDown(KEY_DOWN)) {
            player.MoveBackward();
        }
         else player.SlowDown();
        if (IsKeyDown(KEY_E)) {
            player.PlayerStrafeRight();
        }
        if (IsKeyDown(KEY_Q)) {
            player.PlayerStrafeLeft();
        }

        player.setPozx(player.getPozx()+(player.getspeedx() * player.getAccel()));
        player.setPozy(player.getPozy()+(player.getspeedy() * player.getAccel()));

        /// CAMERA :
        camera.target = (Vector2){player.getPozx(),player.getPozy()};
        camera.zoom += ((float)GetMouseWheelMove()*0.05f);

        if (camera.zoom > 3.0f) camera.zoom = 3.0f;
        else if (camera.zoom < 0.1f) camera.zoom = 0.1f;
        if (IsKeyPressed(KEY_R))
        {
            camera.zoom = 1.0f;
        }
    }