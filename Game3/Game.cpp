//
// Created by User on 14.05.2023.
//

#include <sstream>
#include "Game.h"

Game::Game() {
    this->initTextures();
    this->initWindow();
    this->initPlayer();
    this->initEnemies();
    this->initGUI();
    this->initWorld();
    this->initSystem();
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

void Game::initGUI() {
    if (this->font.loadFromFile("Fonts/Mistral.ttf")) {
        this->pointText.setFont(this->font);
        this->pointText.setFillColor(sf::Color::White);
        this->pointText.setCharacterSize(32);
        this->pointText.setString("test");
    }

}

void Game::initWorld() {
    if (this->backgroundTexture.loadFromFile("Textures/background1.jpg")) {
        this->worldBackground.setTexture(this->backgroundTexture);
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
    this->timerMax = 33.f;
    this->spawnTimer = this->timerMax;
}

void Game::update() {

    this->updatePollEvents();
    this->updateInput();
    this->updateBullet();
    this->player->update();
    this->updateEnemies();
    this->updateCombat();
    this->updateGUI();
    this->updateWorld();
    this->updateCollision();
}

void Game::render() {

    this->window->clear();

    this->renderWorld();

    //Draw all the stuff
    this->player->render(*this->window);

    for (auto &bullet: this->bullets) {
        bullet->render(*this->window);
    }

    for (auto &enemy: this->enemies) {
        enemy->render(*this->window);
    }

    this->renderGUI();

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
                        this->player->getPos().x + this->player->getBounds().width / 2,
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
    //SPAWNING
    this->spawnTimer += 0.5f;
    if (this->spawnTimer >= this->timerMax) {
        this->enemies.push_back(new Enemy(rand() % (this->window->getSize().x - 60) + 10.f,
                                          10.f, rand() % 3 + 0.5f));
        this->spawnTimer = 0;
    }

    //UPDATE
    unsigned counter = 0;
    for (auto *enemy: this->enemies) {
        enemy->update();

        //Bullet culling (top of screen)
        if (enemy->getBounds().top + enemy->getBounds().height > this->window->getSize().y) {
            //Delete bullet
            delete this->enemies.at(counter);
            this->enemies.erase(this->enemies.begin() + counter);
            --counter;
            std::cout << this->enemies.size() << '\n';
        }
        ++counter;
    }
}

void Game::updateGUI() {
//    std::stringstream ss;
//    ss << "points: " << this->points;
this->pointText.setString(this->points);
}

void Game::renderGUI() {
    this->window->draw(this->pointText);
}

void Game::updateCombat() {
    for (int i = 0; i < this->enemies.size(); ++i) {
        for (int j = 0; j < this->bullets.size(); ++j) {
            if (this->enemies[i]->getBounds().intersects(this->bullets[j]->getBounds())) {
                delete this->enemies[i];
                this->enemies.erase(this->enemies.begin() + i);
                delete this->bullets[j];
                this->bullets.erase(this->bullets.begin() + j);
                break;
            }
        }
    }
}

void Game::renderWorld() {
    this->window->draw(this->worldBackground);
}

void Game::updateWorld() {

}

void Game::updateCollision() {
    //LEFT WORLD COLLISION
    if (this->player->getBounds().left < 0.f) {
        this->player->setPosition(0.f, this->player->getBounds().top);
    }
    //RIGHT WORLD COLLISION
    else if (this->player->getBounds().left+this->player->getBounds().width > this->window->getSize().x) {
        this->player->setPosition(this->window->getSize().x -this->player->getBounds().width, this->player->getBounds().top);
    }
    //TOP WORLD COLLISION
    if (this->player->getBounds().top < 0.f) {
        this->player->setPosition(this->player->getBounds().left, 0.f);
    }
    //BOTTOM WORLD COLLISION
    else if (this->player->getBounds().top + this->player->getBounds().height > this->window->getSize().y) {
        this->player->setPosition(this->player->getBounds().left, this->window->getSize().y-this->player->getBounds().height);
    }
}

void Game::initSystem() {
this->points = 0;
}
