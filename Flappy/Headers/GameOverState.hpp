//
// Created by User on 22.06.2023.
//

#ifndef FLAPPY_GAMEOVERSTATE_HPP
#define FLAPPY_GAMEOVERSTATE_HPP

#include "State.hpp"
#include "Game.hpp"

class GameOverState : public State {
public:
    explicit GameOverState(GameDataRef data, int score);

    void Init() override;

    void HandleInput() override;

    void Update(float dt) override;

    void Draw(float dt) override;

private:
    GameDataRef _data;

    sf::Sprite _background;
    sf::Sprite _bird;

    sf::Sprite _gameOverTitle;
    sf::Sprite _medal;
    sf::Sprite _restartButton;
    sf::Sprite _gameOverContainer;

    sf::Text _scoreText;
    sf::Text _highScoreText;

    int _score;
    int _highScore;
};


#endif //FLAPPY_GAMEOVERSTATE_HPP
