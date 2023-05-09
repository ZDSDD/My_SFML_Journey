//
// Created by User on 09.05.2023.
//

#include "Game.h"


Game::Game() {
    this->initVariables();
    this->initWindow();
}

Game::~Game() {

    delete this->window;
}

void Game::initWindow() {
    this->videoMode = sf::VideoMode(800, 600);
    this->window = new sf::RenderWindow(this->videoMode, "Game2", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(60);
}

void Game::initVariables() {
    this->endGame = false;
    this->spawnTimerMax = 30.f;
    this->spawnTimer = this->spawnTimerMax;
    this->maxSwagBalls = 10;
}

void Game::render() {
    this->window->clear();
    //Render stuff
    this->player.render(this->window);
    for(auto & item : this->swagBalls){
        item.render(*this->window);
    }
    this->window->display();
}

void Game::update() {

    this->pollEvents();
    this->spawnSwagBalls();
    this->player.update(this->window);
    this->updateCollision();
}

bool Game::running() const {
    return this->window->isOpen();
}

void Game::pollEvents() {
    while (this->window->pollEvent(this->event)) {
        switch (this->event.type) {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->event.key.code == sf::Keyboard::Escape) {
                    this->window->close();
                }
                break;
        }
    }
}

void Game::spawnSwagBalls() {
    //Timer
    if(this->spawnTimer < this->spawnTimerMax){
        this->spawnTimer += 1.f;
    }
    else{
        if(this->swagBalls.size() < this->maxSwagBalls){
            this->swagBalls.emplace_back(*this->window);
            this->spawnTimer = 0.f;
        }
    }
}

void Game::updateCollision() {
    for (size_t i = 0; i < this->swagBalls.size(); ++i) {
        if(this->player.getShape()
        .getGlobalBounds()
        .intersects(this->swagBalls[i].getShape().getGlobalBounds())){
            this->swagBalls.erase(this->swagBalls.begin()+i);
        }
    }
}
