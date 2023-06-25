//
// Created by User on 22.06.2023.
//

#include "GameState.hpp"

GameState::GameState(GameDataRef data) : _data(std::move(data)) {
}

void GameState::Init() {
    std::cout << "Game state" << std::endl;

    if (!_hitSoundBuffer.loadFromFile(HIT_SOUND_FILEPATH))
    {
        std::cout << "Error Loading Hit Sound Effect" << std::endl;
    }

    if (!_wingSoundBuffer.loadFromFile(WING_SOUND_FILEPATH))
    {
        std::cout << "Error Loading Wing Sound Effect" << std::endl;
    }

    if (!_pointSoundBuffer.loadFromFile(POINT_SOUND_FILEPATH))
    {
        std::cout << "Error Loading Point Sound Effect" << std::endl;
    }

    _hitSound.setBuffer(_hitSoundBuffer);
    _wingSound.setBuffer(_wingSoundBuffer);
    _pointSound.setBuffer(_pointSoundBuffer);

    this->_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
    this->_data->assets.LoadTexture("Pipe Up", PIPE_UP_FILEPATH);
    this->_data->assets.LoadTexture("Pipe Down", PIPE_DOWN_FILEPATH);
    this->_data->assets.LoadTexture("Land", LAND_FILEPATH);
    this->_data->assets.LoadTexture("Bird Frame 1", BIRD_FRAME_1_FILEPATH);
    this->_data->assets.LoadTexture("Bird Frame 2", BIRD_FRAME_2_FILEPATH);
    this->_data->assets.LoadTexture("Bird Frame 3", BIRD_FRAME_3_FILEPATH);
    this->_data->assets.LoadTexture("Bird Frame 4", BIRD_FRAME_4_FILEPATH);
    this->_data->assets.LoadTexture("Scoring Pipe", SCORING_DOWN_FILEPATH);
    this->_data->assets.LoadFont("Flappy Font", FLAPPY_FONT_FILEPATH);
    _background.setTexture(this->_data->assets.GetTexture("Game Background"));
    land = new Land(_data);
    pipe = new Pipe(_data);
    bird = new Bird(_data);
    flash = new Flash(_data);
    hud = new HUD(_data);
    _gameState = GameStates::eReady;
    _score = 0;
    hud->updateScore(_score);

}

void GameState::HandleInput() {
    sf::Event event{};

    while (this->_data->window.pollEvent(event)) {
        if (sf::Event::Closed == event.type) {
            this->_data->window.close();
        }
        if (_data->input.IsSpriteClicked(_background, sf::Mouse::Left, this->_data->window)) {
            if (GameStates::eGameOver != _gameState) {
                _gameState = GameStates::ePlaying;
                bird->tap();
                _wingSound.play();
            }
        }
    }
}

void GameState::Update(float dt) {
    if (GameStates::eGameOver != _gameState) {
        bird->animate(dt);
        land->moveLand(dt);
    }
    if (_gameState == GameStates::ePlaying){
        pipe->movePipes(dt);
        if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY) {
            pipe->randomisePipeOffset();
            pipe->spawnBottomPipe();
            pipe->spawnTopPipe();
            pipe->spawnScoringPipe();

            clock.restart();
        }
        bird->update(dt);
        std::vector<sf::Sprite> landSprites = land->GetSprite();

        for(const auto & landSprite : landSprites){
            if(Collision::CheckSpriteCollision(bird->getSprite(),landSprite)){
                _gameState = GameStates::eGameOver;
                clock.restart();
                _hitSound.play();
            }
        }
        std::vector<sf::Sprite> pipeSprites = pipe->getSprites();

        for(const auto & pipeSprite : pipeSprites){
            if(Collision::CheckSpriteCollision(bird->getSprite(),0.625f,pipeSprite,1.f)){
                _gameState = GameStates::eGameOver;
                clock.restart();
                _hitSound.play();
            }
        }
        auto & scoringPipes = pipe->getScoringSprites();
            if(!scoringPipes.empty())
            if(Collision::CheckSpriteCollision(bird->getSprite(),0.625f,scoringPipes.front(),1.f)){
                ++_score;
                _pointSound.play();
                std::cout << "\n SCORE:\t" << _score << '\n';
                scoringPipes.erase(scoringPipes.begin());
                this->hud->updateScore(_score);
            }

    }
    if(_gameState == GameStates::eGameOver){
        this->flash->show(dt);
        if(clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEARS){

            _data->machine.AddState(StateRef( new GameOverState(this->_data,this->_score)));
        }
    }
}

void GameState::Draw(float dt) {
    this->_data->window.clear();

    this->_data->window.draw(this->_background);

    this->hud->draw();
    this->pipe->drawPipes();
    this->land->drawLand();
    this->bird->drawBird();
    this->flash->draw();

    this->_data->window.display();
}

