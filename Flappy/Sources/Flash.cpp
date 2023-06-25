//
// Created by User on 24.06.2023.
//

#include "Flash.h"

Flash::Flash(GameDataRef data) : _data(data) {
    _shape = sf::RectangleShape(sf::Vector2f(_data->window.getSize()));
    _shape.setFillColor(sf::Color(255, 255, 255, 0));
    _flashOn = true;
}

void Flash::show(float dt) {
    if (_flashOn) {
        int alpha = (int) _shape.getFillColor().a + (FLASH_SPEED * dt);

        if (alpha >= 255.f) {
            alpha = 255.f;
            _flashOn = false;
        }
        _shape.setFillColor(sf::Color(255, 255, 255, alpha));
    } else {
        int alpha = (int) _shape.getFillColor().a - (FLASH_SPEED * dt);

        if (alpha <= 0.f) {
            alpha = 0.f;
            _flashOn = false;
        }
        _shape.setFillColor(sf::Color(255, 255, 255, alpha));
    }
}

void Flash::draw() {
    this->_data->window.draw(this->_shape);
}
