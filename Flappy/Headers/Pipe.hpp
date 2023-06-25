//
// Created by User on 23.06.2023.
//

#ifndef FLAPPY_PIPE_HPP
#define FLAPPY_PIPE_HPP

#include "Game.hpp"

class Pipe {
public:
    explicit Pipe(GameDataRef data);

    virtual ~Pipe() = default;

    void spawnBottomPipe();

    void spawnTopPipe();

    void movePipes(float dt);

    void spawnScoringPipe();

    void drawPipes();

    void randomisePipeOffset();

    const std::vector<sf::Sprite> &getSprites()const;
    std::vector<sf::Sprite> &getScoringSprites();

private:
    GameDataRef _data;
    std::vector<sf::Sprite> pipeSprites;
    std::vector<sf::Sprite> scoringPipes;
    int _landHeight;
    int _pipeSpawnYOffset;
};


#endif //FLAPPY_PIPE_HPP
