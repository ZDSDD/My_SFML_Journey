//
// Created by User on 22.06.2023.
//

#ifndef FLAPPY_GAMESTATE_HPP
#define FLAPPY_GAMESTATE_HPP

#include "DEFINITIONS.hpp"
#include "State.hpp"
#include "Game.hpp"
#include "Pipe.hpp"
#include "Land.hpp"
#include "Bird.hpp"
#include "Collision.hpp"
#include "Flash.h"
#include "HUD.hpp"
#include "GameOverState.hpp"
class GameState : public State {
public:
    explicit GameState(GameDataRef data);

    ~GameState() override = default;

    void Init() override;

    void HandleInput() override;

    void Update(float dt) override;

    void Draw(float dt) override;

private:
    GameDataRef _data;

    sf::Sprite _background;
    sf::Sprite _bird;

    Pipe *pipe;
    Land *land;
    Bird *bird;
    Collision collision;
    Flash *flash;
    HUD *hud;

    sf::Clock clock;
    int _gameState;
    int _score;

    sf::SoundBuffer _hitSoundBuffer;
    sf::SoundBuffer _wingSoundBuffer;
    sf::SoundBuffer _pointSoundBuffer;

    sf::Sound _hitSound;
    sf::Sound _wingSound;
    sf::Sound _pointSound;


};


#endif //FLAPPY_GAMESTATE_HPP
