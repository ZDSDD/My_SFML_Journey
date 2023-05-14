//
// Created by User on 09.05.2023.
//

#include "Game.h"


Game::Game() {
    this->initFont();
    this->initText();
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

void Game::initFont() {
    if(!this->font.loadFromFile("resources/Fonts/16020_FUTURAM.ttf")){
        std::cout << "ERROR::GAME::INITFONTS::COULD NOT LOAD resources/Fonts/16020_FUTURAM.ttf\n";
    }
}
void Game::initText() {
    this->guiText.setFont(this->font);
    this->guiText.setCharacterSize(32);
    this->guiText.setString("test");

    //end game text
    this->endGameText.setFont(this->font);
    this->endGameText.setFillColor(sf::Color::Red);
    this->endGameText.setCharacterSize(60);
    this->endGameText.setPosition(sf::Vector2f(20,300));
    this->endGameText.setString("YOU ARE DEAD, EXIT THE GAME!");
}
void Game::initVariables() {
    this->points = 0;
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
    //render gui
    this->renderGui(*this->window);

    //render end text
    if(this->endGame){
        this->window->draw(this->endGameText);
    }

    //render window
    this->window->display();
}

void Game::update() {

    this->pollEvents();
    if(!this->endGame){

    }
    this->spawnSwagBalls();
    this->updatePlayer();
    this->updateCollision();
    this->updateGui();
}

bool Game::running() const {
    return this->window->isOpen(); // && !this->endGame;
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
            this->swagBalls.emplace_back(*this->window,this->randomizeType());
            this->spawnTimer = 0.f;
        }
    }
}

int Game::randomizeType() const {
    int type = SwagBallTypes::Default;
    int randValue = rand() % 100 + 1;
    if(randValue > 60 && randValue <= 80){ //60 - 80
        type = SwagBallTypes::Damaging;
    }else if (randValue > 80){ // 81 - 100
        type = SwagBallTypes::Healing;
    }
    return type;
}
void Game::updateCollision() {
    for (size_t i = 0; i < this->swagBalls.size(); ++i) {
        if(this->player.getShape()
        .getGlobalBounds()
        .intersects(this->swagBalls[i].getShape().getGlobalBounds())){
            switch(this->swagBalls[i].getType()){
                case SwagBallTypes::Default:
                    //Add points
                    this->points++;
                    break;
                case SwagBallTypes::Damaging:
                    this->player.takeDamage(1);
                    break;
                case SwagBallTypes::Healing:
                    this->player.takeHeal(1);
                    break;
            }

            //Remove the ball
            this->swagBalls.erase(this->swagBalls.begin()+i);
        }
    }
}



void Game::renderGui(sf::RenderTarget& target) {
    target.draw(this->guiText);
}

void Game::updateGui() {
    std::stringstream ss;

    ss <<"Points:\t" << this->points << '\n'
        << "Health:\t" <<  this->player.getHp()<<'/'<< this->player.getHpMax()<<'\n';

    this->guiText.setString(ss.str());
}

const bool &Game::getEndGame() const {
    return this->endGame;
}

void Game::updatePlayer() {
    this->player.update(this->window);
    if(this->player.getHp() <= 0){
        this->endGame=true;
    }
}

