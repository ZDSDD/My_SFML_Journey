//
// Created by User on 07.05.2023.
//

#include "Game.h"

///Private functions

void Game::initFonts() {

    if (this->font.loadFromFile("resources/Fonts/Mistral.ttf")) {
        std::cout << "Mistral font loaded successfully\n";
    } else {
        std::cout << "FAILED to load Mistral font\n";
    }
    if (this->font.loadFromFile("resources/Fonts/16020_FUTURAM.ttf")) {
        std::cout << "FUTURAM font loaded successfully\n";
    } else {
        std::cout << "FAILED to load FUTURAM font\n";
    }
}

void Game::initText() {
    this->uiText.setFont(this->font);
    this->uiText.setCharacterSize(12);
    this->uiText.setFillColor(sf::Color::White);
    this->uiText.setString("uiText example setting");
}

void Game::initVariables() {
    this->window = nullptr;

    //GameLogic
    this->endGame = false;
    this->points = 0;
    this->health = 10;
    this->enemySpawnTimerMax = 10.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 10;
    this->mouseHeld = false;

}

void Game::initWindow() {
    this->videoMode.height = 600;
    this->videoMode.width = 800;
    this->window = new sf::RenderWindow(this->videoMode, "My first game", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}

void Game::initEnemies() {
    this->enemy.setPosition(10.f, 10.f);
    this->enemy.setSize(sf::Vector2f(100.f, 100.f));
    this->enemy.setFillColor(sf::Color::Cyan);
}


///Constructors
Game::Game() {
    this->initVariables();
    this->initWindow();
    this->initEnemies();
    this->initFonts();
    this->initText();
}

Game::~Game() {
    delete this->window;
}

///accessors
bool Game::isRunning() const {
    return this->window->isOpen();
}

bool Game::getEndGame() const {
    return this->endGame;
}


///Public functions
void Game::spawnEnemy() {
/*
 * Spawns enemies
 * -Sets a random type
 * -Sets a random position.
 * -Sets a random color.
 * -Adds enemy to the vector.
 * */

    this->enemy.setPosition(
            static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
            0.f);

    //randomize enemy type
    int type = rand() % 5;

    switch(type){
        case 0:
            this->enemy.setSize(sf::Vector2f(33.f, 33.f));
            this->enemy.setFillColor(sf::Color::Magenta);
            break;
        case 1:
            this->enemy.setSize(sf::Vector2f(50.f, 50.f));
            this->enemy.setFillColor(sf::Color::Blue);
            break;
        case 2:
            this->enemy.setSize(sf::Vector2f(100.f, 100.f));
            this->enemy.setFillColor(sf::Color::Cyan);
            break;
        case 3:
            this->enemy.setSize(sf::Vector2f(66.f, 66.f));
            this->enemy.setFillColor(sf::Color::Magenta);
            break;
        case 4:
            this->enemy.setSize(sf::Vector2f(130.f, 130.f));
            this->enemy.setFillColor(sf::Color::Green);
            break;
        default:
            this->enemy.setSize(sf::Vector2f(30.f, 13.f));
            this->enemy.setFillColor(sf::Color::Yellow);
            break;
    }

    //spawn the enemy
    this->enemies.push_back(this->enemy);
}

void Game::pollEvents() {
    while (this->window->pollEvent(this->ev)) {
        switch (ev.type) {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (ev.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break;
        }
    }
}

void Game::updateEnemies() {
    if (this->enemies.size() < this->maxEnemies) {
        if (this->enemySpawnTimer >= this->enemySpawnTimerMax) {
            this->spawnEnemy();
            this->enemySpawnTimer = 0.f;
        } else {
            this->enemySpawnTimer += 100.f;
        }
    }
    //move the enemies
    for (int i = 0; i < this->enemies.size(); ++i) {
        this->enemies[i].move(0.f, 1.f);
        //if the enemy is past the bottom of the screen,
        if (this->enemies[i].getPosition().y > this->window->getSize().y) {
            this->enemies.erase(this->enemies.begin() + i);
            this->health -= 1;
            this->ShowHealth();
        }
    }
    //check if clicked upon
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (!mouseHeld) {
            mouseHeld = true;
            for (size_t i = 0; i < this->enemies.size(); ++i) {
                if (this->enemies[i].getGlobalBounds().contains(this->mousePosView)) {

                    //Gain points
                    if(this->enemies[i].getFillColor() == sf::Color::Magenta){
                        this->points += 10;
                    }
                    else if(this->enemies[i].getFillColor() == sf::Color::Blue){
                        this->points += 25;
                    }
                    else if(this->enemies[i].getFillColor() == sf::Color::Cyan){
                        this->points += 33;
                    }
                    else if(this->enemies[i].getFillColor() == sf::Color::Green){
                        this->points += 111;
                    }
                    else if(this->enemies[i].getFillColor() == sf::Color::Yellow){
                        this->points += 1411;
                    }
                    this->points += 10;
                    //Delete the enemy
                    this->enemies.erase(this->enemies.begin() + i);
                    break;
                    //escape the loop
                }
            }
        }
    } else {
        mouseHeld = false;
    }
}

void Game::update() {
    this->pollEvents();

    if (!endGame) {
        this->updateMousePositions();
        this->updateText();
        this->updateEnemies();
    }
    if (this->health <= 0) {
        endGame = true;
    }
}

void Game::updateText() {
    std::stringstream ss;
    ss << "Points: " << this->points << '\n'
        << "Health: " << this->health << '\n';
    this->uiText.setString(ss.str());
}

void Game::updateMousePositions() {
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::renderEnemies(sf::RenderTarget &target) {
    for (auto &e: this->enemies) {
        target.draw(e);
    }
}

void Game::renderText(sf::RenderTarget &target) const {
    target.draw(this->uiText);
}

void Game::render() {

    this->window->clear();

    this->renderEnemies(*(this->window));

    this->renderText(*(this->window));

    this->window->display();
}


void Game::showPoints() const {
    std::cout << this->points << std::endl;
}

void Game::ShowHealth() const {
    std::cout << this->health << std::endl;
}







