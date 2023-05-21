//
// Created by User on 14.05.2023.
//

#include "Game.h"

Game::Game() {
    this->initTextures();
    this->initWindow();
    this->initPlayer();
    this->initEnemies();
}

Game::~Game() {
    delete this->player;
    delete this->window;

    //Delete textures

    for (auto &i: this->textures) {
        delete i.second;
    }

    //Delete bullets
    for (auto *i: this->bullets) {
        delete i;
    }
    //Delete enemies
    for (auto *i: this->enemies) {
        delete i;
    }
}

//Functions
void Game::run() {
    while (this->window->isOpen()) {
        this->update();
        this->render();
    }
}

void Game::initPlayer() {
    this->player = new Player();
}

void Game::initTextures() {
    this->textures["BULLET"] = new sf::Texture();
    this->textures["BULLET"]->loadFromFile("Textures/bullet.png");
}

void Game::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600),
                                        "Game 3", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(60);
    this->window->setVerticalSyncEnabled(false);

}

void Game::initEnemies() {
    this->timerMax = 100.f;
    this->spawnTimer = this->timerMax;
}

void Game::update() {

    this->updatePollEvents();
    //Move player
    this->updateInput();
    this->updateBullet();
    this->player->update();
    this->updateEnemies();
}

void Game::render() {

    this->window->clear();

    //Draw all the stuff
    this->player->render(*this->window);

    for (auto &bullet: this->bullets) {
        bullet->render(*this->window);
    }

    for (auto &enemy: this->enemies) {
        enemy->render(*this->window);
    }

    this->window->display();
}


void Game::updatePollEvents() {
    sf::Event e{};
    while (this->window->pollEvent(e)) {
        if (e.type == sf::Event::Closed) {
            this->window->close();
        }
        if (e.Event::key.code == sf::Keyboard::Escape) {
            this->window->close();
        }
    }
}

void Game::updateInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        this->player->move(-1.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        this->player->move(1.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        this->player->move(0.f, -1.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        this->player->move(0.f, 1.f);
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAttack()) {
        this->bullets.push_back(
                new Bullet(
                        this->textures["BULLET"],
                        this->player->getPos().x + this->player->getBounds().width/2,
                        this->player->getPos().y,
                        0.f,
                        -1.f,
                        7.f)
        );
    }
}

void Game::updateBullet() {


    unsigned counter = 0;
    for (auto &bullet: this->bullets) {
        bullet->update();

        //Bullet culling (top of screen)
        if (bullet->getBounds().top + bullet->getBounds().height < 0.f) {
            //Delete bullet
            delete this->bullets.at(counter);
            this->bullets.erase(this->bullets.begin() + counter);
            --counter;
            std::cout << this->bullets.size() << '\n';
        }
        ++counter;
    }
}

void Game::updateEnemies() {
    this->spawnTimer += 0.5f;
    if(this->spawnTimer >= this->timerMax){
        this->enemies.push_back(new Enemy(rand() % 200 + 5, rand() % 100 + 20));
        this->spawnTimer=0;
    }
}




