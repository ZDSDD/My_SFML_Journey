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
        this->updatePollEvents();
        if (this->player->getHp() > 0) {
            this->update();
        }
        this->render();
    }
}

void Game::initGUI() {
    //LOAD THE FONT
    if (this->font.loadFromFile("Fonts/16020_FUTURAM.ttf")) {
        //POINTS TEXT
        this->pointText.setPosition(700.f, 25.f);
        this->pointText.setFont(this->font);
        this->pointText.setFillColor(sf::Color::White);
        this->pointText.setCharacterSize(16);
        this->pointText.setString("test");

        //GAME OVER TEXT
        this->gameOverText.setFont(this->font);
        this->gameOverText.setFillColor(sf::Color::White);
        this->gameOverText.setCharacterSize(16);
        this->gameOverText.setString("GAME OVER");
        this->gameOverText.setPosition(
                this->window->getSize().x / 2.f - this->gameOverText.getGlobalBounds().width / 2.f,
                this->window->getSize().y / 2.f - this->gameOverText.getGlobalBounds().height / 2.f
        );
    }

    //Init player GUI
    this->playerHpBar.setSize(sf::Vector2f(300.f, 25.f));
    this->playerHpBar.setFillColor(sf::Color(255, 0, 0, 100));
    this->playerHpBar.setPosition(sf::Vector2f(20.f, 20.f));
    this->playerHpBarBack = this->playerHpBar;
    this->playerHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));
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
    this->timerMax = 15.f;
    this->spawnTimer = this->timerMax;
}

void Game::update() {

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

    //Game over screen
    if (this->player->getHp() <= 0) {
        this->window->draw(this->gameOverText);
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
            std::cout << this->bullets.size() << '\n';
            --counter;
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
        }
            //Bullets touching the player ship
        else if (enemy->getBounds().intersects(this->player->getBounds())) {
            this->player->loseHp(enemies.at(counter)->getDMG());
            delete this->enemies.at(counter);
            this->enemies.erase(this->enemies.begin() + counter);
            --counter;

        }
        ++counter;
    }
}

void Game::updateGUI() {
    std::stringstream ss;
    ss << "points: " << this->points;
    this->pointText.setString(ss.str());

    //Update player GUI
    float hpPercent = static_cast<float> (this->player->getHp()) / (this->player->getHpMax());
    this->playerHpBar.setSize(sf::Vector2f(300.f * hpPercent, this->playerHpBar.getSize().y));

}

void Game::renderGUI() {
    this->window->draw(this->pointText);
    this->window->draw(this->playerHpBarBack);
    this->window->draw(this->playerHpBar);
}

void Game::updateCombat() {
    for (int i = 0; i < this->enemies.size(); ++i) {
        for (int j = 0; j < this->bullets.size(); ++j) {
            if (this->enemies[i]->getBounds().intersects(this->bullets[j]->getBounds())) {
                this->points += enemies[i]->getPoints();
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
    else if (this->player->getBounds().left + this->player->getBounds().width > this->window->getSize().x) {
        this->player->setPosition(this->window->getSize().x - this->player->getBounds().width,
                                  this->player->getBounds().top);
    }
    //TOP WORLD COLLISION
    if (this->player->getBounds().top < 0.f) {
        this->player->setPosition(this->player->getBounds().left, 0.f);
    }
        //BOTTOM WORLD COLLISION
    else if (this->player->getBounds().top + this->player->getBounds().height > this->window->getSize().y) {
        this->player->setPosition(this->player->getBounds().left,
                                  this->window->getSize().y - this->player->getBounds().height);
    }
}

void Game::initSystem() {
    this->points = 0;
}
