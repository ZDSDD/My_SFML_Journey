#pragma once

#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024



///     SPLASH START

#define SPLASH_STATE_SHOW_TIME 1.0
#define SPLASH_SCENE_BACKGROUND_FILEPATH "Resources/res/Splash Background.png"

///    MAIN MENU

#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/res/sky.png"

#define GAME_TITLE_FILEPATH "Resources/res/title.png"

#define PLAY_BUTTON_FILEPATH "Resources/res/PlayButton.png"

///     GAME

#define GAME_BACKGROUND_FILEPATH "Resources/res/sky.png"
#define PIPE_UP_FILEPATH "Resources/res/PipeUp.png"
#define PIPE_DOWN_FILEPATH "Resources/res/PipeDown.png"
#define SCORING_DOWN_FILEPATH "Resources/res/InvisibleScoringPipe.png"
#define PIPE_MOVEMENT_SPEED 200.f
#define PIPE_SPAWN_FREQUENCY 1.5f
#define LAND_FILEPATH "Resources/res/land.png"
#define BIRD_FRAME_1_FILEPATH "Resources/res/bird-01.png"
#define BIRD_FRAME_2_FILEPATH "Resources/res/bird-02.png"
#define BIRD_FRAME_3_FILEPATH "Resources/res/bird-03.png"
#define BIRD_FRAME_4_FILEPATH "Resources/res/bird-04.png"
#define BIRD_ANIMATION_DURATION 0.4f
#define FLAPPY_FONT_FILEPATH "Resources/fonts/FlappyFont.ttf"

//sounds
#define HIT_SOUND_FILEPATH "Resources/audio/Hit.wav"
#define POINT_SOUND_FILEPATH "Resources/audio/Point.wav"
#define WING_SOUND_FILEPATH "Resources/audio/Wing.wav"

//bird states
#define BIRD_STATE_STILL 1
#define BIRD_STATE_FALLING 2
#define BIRD_STATE_FLYING 3

//physics
#define GRAVITY 200.f
#define FLYING_SPEED 555.f
#define FLYING_DURATION 0.15f

//ROTATION OF THE BIRD
#define ROTATION_SPEED 80.f
#define MAX_ROTATION 15.f
#define MIN_ROTATION 88.f

enum GameStates{
    eReady,
    ePlaying,
    eGameOver
};


///     GAME_OVER

#define TIME_BEFORE_GAME_OVER_APPEARS 1.5f
#define GAME_OVER_BACKGROUND_FILEPATH "Resources/res/sky.png"
#define GAME_OVER_TITLE_FILEPATH "Resources/res/Game-Over-Title.png"
#define GAME_OVER_BODY_FILEPATH "Resources/res/Game-Over-Body.png"
#define GOLD_MEDAL_FILEPATH "Resources/res/Gold-Medal.png"
#define SILVER_MEDAL_FILEPATH "Resources/res/Silver-Medal.png"
#define PLATINUM_MEDAL_FILEPATH "Resources/res/Platinum-Medal.png"
#define BRONZE_MEDAL_FILEPATH "Resources/res/Bronze-Medal.png"

#define BRONZE_MEDAL_SCORE 0
#define SILVER_MEDAL_SCORE 5
#define GOLD_MEDAL_SCORE 25
#define PLATINUM_MEDAL_SCORE 100

#define FLASH_SPEED 1500.f




