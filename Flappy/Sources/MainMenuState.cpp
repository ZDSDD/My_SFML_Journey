//
// Created by User on 22.06.2023.
//

#include "MainMenuState.hpp"
#include "DEFINITIONS.hpp"
#include "GameState.hpp"
#include "GameOverState.hpp"

MainMenuState::MainMenuState(GameDataRef data) : _data(std::move(data)) {
}

void MainMenuState::Init() {

    //Load textures from the resources for: MAIN MENU, TITLE and PLAY BUTTON
    this->_data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
    this->_data->assets.LoadTexture("Title", GAME_TITLE_FILEPATH);
    this->_data->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);

    //Set aforementioned textures to the sprites
    _background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
    _title.setTexture(this->_data->assets.GetTexture("Title"));
    _playButton.setTexture(this->_data->assets.GetTexture("Play Button"));

    //CENTER SPRITES ON THE SCREEN AND SET THEIR HEIGHT
    _title.setPosition((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width) / 2, SCREEN_HEIGHT / 7);

    _playButton.setPosition((SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2),
                            (SCREEN_HEIGHT / 2) - (_title.getGlobalBounds().height) / 2);

}

void MainMenuState::HandleInput() {
    sf::Event event{};

    while (this->_data->window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                this->_data->window.close();
                break;
        }
        if (_data->input.IsSpriteClicked(_playButton, sf::Mouse::Left, this->_data->window)) {
            std::cout << "Go to game screen" << std::endl;
            _data->machine.AddState(StateRef(new GameState(this->_data)), true);
        }
    }
}

void MainMenuState::Update(float dt) {

}

void MainMenuState::Draw(float dt) {
    this->_data->window.clear();

    this->_data->window.draw(this->_background);
    this->_data->window.draw(this->_title);
    this->_data->window.draw(this->_playButton);

    this->_data->window.display();
}
