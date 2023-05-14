//
// Created by User on 14.05.2023.
//

#include "Game.h"

Game::Game() {
    this->initWindow();
    this->initPlayer();
}

Game::~Game() {
    delete this->player;
    delete this->window;
}

//Functions
void Game::run() {
    while(this->window->isOpen()) {
        this->update();
        this->render();
    }
}


void Game::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(800,600),
                                        "Game 3",sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(60);
    this->window->setVerticalSyncEnabled(false);

}

void Game::update() {
    sf::Event e{};
    while(this->window->pollEvent(e)){
        if(e.type == sf::Event::Closed){
            this->window->close();
        }
        if(e.Event::key.code == sf::Keyboard::Escape){
            this->window->close();
        }
    }
    //Move player
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        this->player->move(-1.f,0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        this->player->move(1.f,0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        this->player->move(0.f,-1.0f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        this->player->move(0.f,1.f);
    }
}

void Game::render() {

    this->window->clear();

    //Draw all the stuff
    this->player->render(*this->window);
    this->window->display();
}

void Game::initPlayer() {
    this->player = new Player();
}
