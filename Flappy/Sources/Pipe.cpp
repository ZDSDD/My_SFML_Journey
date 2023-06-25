//
// Created by User on 23.06.2023.
//

#include "../Headers/DEFINITIONS.hpp"
#include "../Headers/Pipe.hpp"

Pipe::Pipe(GameDataRef data) : _data(std::move(data)) {
    _landHeight = _data->assets.GetTexture("Land").getSize().y;
    _pipeSpawnYOffset = 0;
}

void Pipe::drawPipes() {
    for (const auto &pipeSprite: pipeSprites) {
        _data->window.draw(pipeSprite);
    }
}

void Pipe::spawnBottomPipe() {
    sf::Sprite sprite(_data->assets.GetTexture("Pipe Up"));
    sprite.setPosition(static_cast<float>(_data->window.getSize().x),
                       static_cast<float>(_data->window.getSize().y) - sprite.getGlobalBounds().height - _pipeSpawnYOffset);
    pipeSprites.push_back(sprite);
}


void Pipe::spawnTopPipe() {
    sf::Sprite sprite(_data->assets.GetTexture("Pipe Down"));
    sprite.setPosition(static_cast<float>(_data->window.getSize().x), -_pipeSpawnYOffset);
    pipeSprites.push_back(sprite);
    std::cout << pipeSprites.size() << std::endl;
}

void Pipe::movePipes(float dt) {
    if(!pipeSprites.empty() && (pipeSprites.front().getPosition().x < 0 - pipeSprites.front().getGlobalBounds().width)){
        pipeSprites.erase(pipeSprites.begin(),pipeSprites.begin()+1);
    }

    for (auto & pipeSprite : pipeSprites) {

        float movement = PIPE_MOVEMENT_SPEED * dt;
        pipeSprite.move(-movement, 0);
    }
    if(!scoringPipes.empty() && (scoringPipes.front().getPosition().x < 0 - scoringPipes.front().getGlobalBounds().width)){
        scoringPipes.erase(scoringPipes.begin(),scoringPipes.begin()+1);
    }

    for (auto & pipeSprite : scoringPipes) {

        float movement = PIPE_MOVEMENT_SPEED * dt;
        pipeSprite.move(-movement, 0);
    }

}

void Pipe::randomisePipeOffset() {
    _pipeSpawnYOffset = rand() % (_landHeight + 1);
}

const std::vector<sf::Sprite> &Pipe::getSprites() const {
    return this->pipeSprites;
}

void Pipe::spawnScoringPipe() {
    sf::Sprite sprite(_data->assets.GetTexture("Scoring Pipe"));
    sprite.setPosition(static_cast<float>(_data->window.getSize().x),0);
    sprite.setColor(sf::Color(0,0,0,0));
    scoringPipes.push_back(sprite);
}

std::vector<sf::Sprite> &Pipe::getScoringSprites() {
    return this->scoringPipes;
}
