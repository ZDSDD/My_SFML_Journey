//
// Created by User on 23.06.2023.
//

#include "Bird.hpp"
#include "DEFINITIONS.hpp"
#include <utility>

Bird::Bird(GameDataRef data) : _data(std::move(data)) {

    _animationIterator = 0;

    _birdFrames.push_back(this->_data->assets.GetTexture("Bird Frame 1"));
    _birdFrames.push_back(this->_data->assets.GetTexture("Bird Frame 2"));
    _birdFrames.push_back(this->_data->assets.GetTexture("Bird Frame 3"));
    _birdFrames.push_back(this->_data->assets.GetTexture("Bird Frame 4"));

    _birdSprite.setTexture(_birdFrames.at(_animationIterator));

    _birdSprite.setPosition(
            static_cast<float>(_data->window.getSize().x / 4) - (_birdSprite.getGlobalBounds().width / 2),
            static_cast<float>(_data->window.getSize().y / 4) - (_birdSprite.getGlobalBounds().height / 2)
    );
    _birdState = BIRD_STATE_STILL;

    sf::Vector2f origin = sf::Vector2f(_birdSprite.getGlobalBounds().width / 2,
                                       _birdSprite.getGlobalBounds().height / 2);

    _birdSprite.setOrigin(origin);

    _rotation = 0;

    this->acceleration = 0;
}


void Bird::drawBird() {

    _data->window.draw(_birdSprite);
}

void Bird::animate(float dt) {
    if (_clock.getElapsedTime().asSeconds() > BIRD_ANIMATION_DURATION / _birdFrames.size()) {
        ++_animationIterator;
        _animationIterator %= _birdFrames.size();
        _birdSprite.setTexture(_birdFrames.at(_animationIterator));
        _clock.restart();
    }

}

void Bird::update(float dt) {

    if (_birdState == BIRD_STATE_FLYING) {
        acceleration = 0;
        if(_rotation > MIN_ROTATION/4) _rotation = 0;
        this->_birdSprite.move(0, -FLYING_SPEED * dt);
        _rotation -= ROTATION_SPEED * dt;
        if(_rotation < -MAX_ROTATION){
            _rotation = -MAX_ROTATION;
        }
        _birdSprite.setRotation(_rotation);
    }
    else if (_birdState == BIRD_STATE_FALLING) {
        acceleration += 20;
        this->_birdSprite.move(0, (GRAVITY + acceleration) * dt);
        _rotation += (ROTATION_SPEED) * dt;
        if(_rotation > MIN_ROTATION){
            _rotation = MIN_ROTATION;
        }
        _birdSprite.setRotation(_rotation);
    }
    if (_movementClock.getElapsedTime().asSeconds() > FLYING_DURATION) {
        _movementClock.restart();
        _birdState = BIRD_STATE_FALLING;
    }
}

void Bird::tap() {
    _movementClock.restart();
    _birdState = BIRD_STATE_FLYING;
}

const sf::Sprite &Bird::getSprite() const {
    return _birdSprite;
}
