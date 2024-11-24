//
// Created by mihne on 11/7/2024.
//

#include "../headers/Game.h"
#include <iostream>

    Game::Game() {
        std::cout<<"Jocul a fost creat"<<std::endl;
    }
void Game::addPlayer(const Player &p) {
        jucator=p;
    }
void Game::Start()  {
        std::cout<<"Jocul a inceput "<<std::endl;
    }
Game::~Game() {
        std::cout<<"Jocul a fost distrus "<<std::endl;
    }