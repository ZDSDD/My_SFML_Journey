//
// Created by User on 16.06.2023.
//

#ifndef GAME4_PLAYER_H
#define GAME4_PLAYER_H


class Player {
private:
    sf::Sprite sprite;
    sf::Texture textureSheet;

    //Animation

    //Movement

    //Core


    //INITIALIZERS
    void initSprite();
    void initTexture();

public:
    //Constructor / Destructor
    Player();
    virtual ~Player();

    //UPDATE & RENDER
    void update();
    void render(sf::RenderTarget & renderTarget);


};


#endif //GAME4_PLAYER_H
