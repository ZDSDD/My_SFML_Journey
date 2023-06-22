//
// Created by User on 16.06.2023.
//

#ifndef GAME4_PLAYER_H
#define GAME4_PLAYER_H

enum PLAYER_ANIMATION_STATES {
    IDLE,
    MOVING_LEFT,
    MOVING_RIGHT,
    JUMP,
    FALLING
};

class Player {

private:
    //Sprite and textures
    sf::Sprite sprite;
    sf::Texture textureSheet;
    sf::Clock animationTimer;

    //Animation
    short animationState{};
    sf::IntRect currentFrame;
    bool animationSwitch;

    //Physics
    sf::Vector2f velocity;
    float velocityMax;
    float velocityMin;
    float acceleration;
    float drag;
    float gravity;
    float velocityMaxY;

    //INITIALIZERS
    void initSprite();

    void initTexture();

    void initVariables();

    void initAnimation();

    void initPhysics();

public:
    //Constructor / Destructor
    Player();

    virtual ~Player();

    //      Getters
    bool getAnimSwitch();
    const sf::FloatRect getGlobalBounds() const;
    const sf::Vector2f getPosition() const;


    ///     Utility       ////
    void move( float dir_x,  float dir_y);
    void resetAnimationTimer();

    ///     Update      ////
    void updateMovement();

    void updateAnimations();

    void updatePhysics();

    void update();


    ///      Render     ////
    void render(sf::RenderTarget &renderTarget);


    ///     Setters   ///

    void setPosition(const float x, const float y);

    void resetVelocityY();
};


#endif //GAME4_PLAYER_H
