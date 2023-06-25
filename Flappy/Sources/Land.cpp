//
// Created by User on 23.06.2023.
//

#include "Land.hpp"
#include "DEFINITIONS.hpp"
Land::Land(GameDataRef data) : _data(std::move(data))
{
    sf::Sprite sprite( _data->assets.GetTexture("Land"));
    sf::Sprite sprite2( _data->assets.GetTexture("Land"));

    sprite.setPosition(0,static_cast<float>(_data->window.getSize().y) - sprite.getGlobalBounds().height);
    sprite2.setPosition(sprite.getGlobalBounds().width,static_cast<float>(_data->window.getSize().y) - sprite.getGlobalBounds().height);

    _landSprite.push_back(sprite);
    _landSprite.push_back(sprite2);
}

void Land::moveLand(float dt) {

    if(_landSprite.front().getPosition().x < 0 - _landSprite.front().getGlobalBounds().width){
        sf::Vector2f newPosition (_data->window.getSize().x,_landSprite.front().getPosition().y);
        _landSprite.front().setPosition(newPosition);
        std::swap(_landSprite.front(),_landSprite.back());
    }

    for(auto & i : _landSprite){
        float movement = PIPE_MOVEMENT_SPEED * dt;
        i.move(-movement,0.f);
    }
}

void Land::drawLand() {
    this->_data->window.draw(_landSprite.front());
    this->_data->window.draw(_landSprite.back());

}

const std::vector<sf::Sprite> &Land::GetSprite() const {
    return this->_landSprite;
}
