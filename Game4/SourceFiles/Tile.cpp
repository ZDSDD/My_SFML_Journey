//
// Created by User on 18.06.2023.
//

#include "../Headers/Tile.h"

Tile::~Tile() {

}

sf::FloatRect Tile::getGlobalBounds() const {
    return sf::FloatRect();
}

Tile::Tile(sf::Texture &texture, sf::IntRect texture_rect, bool damaging):damaging(damaging) {
    this->sprite.setTexture(texture);
    this->sprite.setTextureRect(texture_rect);
}

void Tile::update() {

}

void Tile::render(sf::RenderTarget &renderTarget) {

}
