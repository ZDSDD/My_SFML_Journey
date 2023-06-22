//
// Created by User on 21.06.2023.
//

#include "Game.h"

Game::Game(int height, int width) : height(height), width(width), delay(0.2f), timer(0.f), cell_size(16) {

    renderWindow = new sf::RenderWindow(sf::VideoMode(width * 16, height * 16), "SNAKE",
                                        sf::Style::Close | sf::Style::Titlebar);
    initTextures();
    initSprite();
    //this->snakeDeque.resize(height * width);
    this->snakeDeque.push_front({0, 0});
    this->snakeDeque.push_front({0, 1});
    this->currentDirection = Down;
    spawnFruit();
}

Game::~Game() {
    delete renderWindow;
}

void Game::update() {

    /* Update data BEFORE render it*/

    updateTime();
    updatePollEvents();
    updatePlayerInput();

}

void Game::render(sf::RenderTarget &renderTarget) {

/*  >Clear the window
    >Render map and snake
    >Display on the screen*/

    renderTarget.clear();

    renderMap(renderTarget);
    renderSnake(renderTarget);
    renderFruit(renderTarget);
    this->renderWindow->display();
}

void Game::run() {

    /*  GAME LOOP   */

    while (this->renderWindow->isOpen()) {
        update();
        render(*this->renderWindow);
    }
}

void Game::updatePollEvents() {

    /*CHECK IF CLOSE BUTTON WAS CLICKED*/

    sf::Event e{};
    while (this->renderWindow->pollEvent(e)) {
        switch (e.type) {
            case sf::Event::Closed:
                this->renderWindow->close();
                break;
            case sf::Event::KeyReleased:
                if (e.key.code == sf::Keyboard::E) {
                    if (delay > 0.05) {
                        delay -= 0.01;
                    }
                } else if (e.key.code == sf::Keyboard::R) {
                    if (delay < 1.f) {
                        delay += 0.01;
                    }
                }
        }

    }
}

void Game::updateSnake() {

    /*  SNAKE MOVEMENT  */

    point2d NextPos{};
    point2d Head = snakeDeque.front();

    /*  Check if the newDirection is not null, if it's any different from the current position
     *  and if it's not Left to Right / Up to Down movement  */
    if (newDirection && (newDirection != currentDirection)) {
        if (newDirection + currentDirection != 3 && newDirection + currentDirection != 7)
            currentDirection = newDirection;
    }
    newDirection = null;


    switch (currentDirection) {
        case Up:
            NextPos = {Head.x, Head.y - 1};
            currentDirection = Up;
            break;
        default:
        case Down:
            NextPos = {Head.x, Head.y + 1};
            currentDirection = Down;
            break;
        case Left:
            NextPos = {Head.x - 1, Head.y};
            currentDirection = Left;
            break;
        case Right:
            NextPos = {Head.x + 1, Head.y};
            currentDirection = Right;
            break;
    }
    if (NextPos.x >= this->width) NextPos.x = 0;
    if (NextPos.x == -1) NextPos.x = this->width - 1;
    if (NextPos.y >= this->height) NextPos.y = 0;
    if (NextPos.y == -1) NextPos.y = this->height - 1;

    //  Check if snake have eaten the apple //
    if (NextPos != fruit) {
        this->snakeDeque.pop_back();
    } else {
        spawnFruit();
    }
    //  Snakes eats itself when next position is within his body
    if(CheckCollision(NextPos)){
        for(size_t i = 0, n = snakeDeque.size(); i < n; ++i){
            if(NextPos == snakeDeque[i]) break;
            snakeDeque.pop_back();
        }
    }
    snakeDeque.push_front(NextPos);

}


void Game::updatePlayerInput() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        newDirection = Left;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        newDirection = Right;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        newDirection = Up;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        newDirection = Down;

    if (timer > delay) {
        timer = 0;
        updateSnake();
    }
}

void Game::renderSnake(sf::RenderTarget &renderTarget) {
    for (const auto &snake_part: this->snakeDeque) {
        snakeSprite.setPosition(snake_part.x * cell_size, snake_part.y * cell_size);
        renderTarget.draw(snakeSprite);
        //std::cout << snake_part.x << ':' << snake_part.y << std::endl;
    }
}

void Game::renderMap(sf::RenderTarget &renderTarget) {
    for (int x = 0; x < this->width; ++x) {
        for (int y = 0; y < this->height; ++y) {
            mapSprite.setPosition(x * cell_size, y * cell_size);
            mapSprite.setColor(sf::Color(y, 0, x));
            renderTarget.draw(mapSprite);
        }
    }
}

void Game::initTextures() {
    this->snakeTexture.loadFromFile("Textures/white.png");
    this->mapTexture = this->snakeTexture;
    this->fruitTexture = this->snakeTexture;
}

void Game::initSprite() {
    this->mapSprite.setTexture(mapTexture);
    this->snakeSprite.setTexture(this->snakeTexture);
    this->snakeSprite.setColor(sf::Color::Magenta);
    this->fruitSprite.setTexture(this->fruitTexture);
    this->fruitSprite.setColor(sf::Color::Green);
}

void Game::updateTime() {
    float time = clock.restart().asSeconds();
    //clock.restart();
    timer += time;
}

void Game::spawnFruit() {
    fruit.x = rand() % this->width;
    fruit.y = rand() % this->height;
}

void Game::renderFruit(sf::RenderTarget &renderTarget) {
    fruitSprite.setPosition(this->fruit.x * cell_size, this->fruit.y * cell_size);
    renderTarget.draw(this->fruitSprite);
}

bool Game::CheckCollision(Game::point2d &point2D)const {
    auto pt = snakeDeque.begin();
    while(pt != snakeDeque.end()){
        if(* pt == point2D) return true;
        ++pt;
    }
    return false;
}


bool Game::point2d::operator==(const Game::point2d &point2d) const {
    return x == point2d.x && y == point2d.y;
}

bool Game::point2d::operator!=(const Game::point2d &point2d) const {
    return x != point2d.x || y != point2d.y;
}
