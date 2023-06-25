//
// Created by User on 22.06.2023.
//

#ifndef FLAPPY_MAINMENUSTATE_HPP
#define FLAPPY_MAINMENUSTATE_HPP

#include "State.hpp"
#include "Game.hpp"

class MainMenuState : public State {
public:
    explicit MainMenuState(GameDataRef data);

    void Init() override;

    void HandleInput() override;

    void Update(float dt) override;

    void Draw(float dt) override;

private:
    GameDataRef _data;

    sf::Sprite _background;
    sf::Sprite _title;
    sf::Sprite _playButton;
};


#endif //FLAPPY_MAINMENUSTATE_HPP
