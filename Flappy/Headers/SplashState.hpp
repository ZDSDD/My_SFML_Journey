#pragma once

#include "State.hpp"
#include "Game.hpp"


class SplashState : public State {
public:
    explicit SplashState(GameDataRef data);

    void Init() override;

    void HandleInput() override;

    void Update(float dt) override;

    void Draw(float dt) override;

private:
    GameDataRef _data;

    sf::Clock _clock;

    sf::Sprite _background;
};
