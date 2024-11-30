//
// Created by mihne on 11/7/2024.
//

#include "../headers/Game.h"
#include <iostream>
#include <math.h>
#include "raylib.h"
    Game::Game() {
        std::cout<<"Jocul a fost creat"<<std::endl;
        camera = {0};



    }
void Game::addPlayer(const Player &p) {
        player=p;
    }
void Game::Start()  {
        std::cout<<"Jocul a inceput "<<std::endl;
        InitAudioDevice();
        camera.target=(Vector2) {0,0};
        camera.offset=(Vector2) {(float)800/2,(float)600/2};
        camera.rotation=0.0f;
        camera.zoom=3.0f;

    }
Game::~Game() {
        std::cout<<"Jocul a fost distrus "<<std::endl;
    }
void Game::Draw() {
        BeginMode2D(camera);
        player.Draw();
        EndMode2D();
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

        CAMERA :
        // float wheel= GetMouseWheelMove();
        // if (wheel!=0) {
        //     const float zoomIncrement=0.125f;
        //     camera.zoom+=(wheel*zoomIncrement);
        // }
        // camera.target=(Vector2) {0,0};


        camera.target = (Vector2){player.getPozx(),player.getPozy()};
        camera.zoom += ((float)GetMouseWheelMove()*0.05f);

        if (camera.zoom > 3.0f) camera.zoom = 3.0f;
        else if (camera.zoom < 0.1f) camera.zoom = 0.1f;
        if (IsKeyPressed(KEY_R))
        {
            camera.zoom = 1.0f;
        }

        std::cout<<"Coordonatele sint :"<<player.getPozx()<<" "<<player.getPozy()<<std::endl;
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



