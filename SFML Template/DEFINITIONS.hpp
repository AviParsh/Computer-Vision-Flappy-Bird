#pragma once


#define SCREEN_WIDTH 768.0
#define SCREEN_HEIGHT 1024.0
#define SPLASH_STATE_SHOW_TIME 0

#define SPLASH_SCENE_BACKGROUND_FILEPATH "/Users/aviparshionikar/Documents/SFML/SFML Template/SFML Template/Resources/res/Splash Background.png"

#define MAIN_MENU_BACKGROUND_FILEPATH "/Users/aviparshionikar/Documents/SFML/SFML Template/SFML Template/Resources/res/sky.png"

#define GAME_BACKGROUND_FILEPATH "/Users/aviparshionikar/Documents/SFML/SFML Template/SFML Template/Resources/res/sky.png"

#define GAME_OVER_BACKGROUND_FILEPATH "/Users/aviparshionikar/Documents/SFML/SFML Template/SFML Template/Resources/res/sky.png"


#define GAME_TITLE_FILEPATH "/Users/aviparshionikar/Documents/SFML/SFML Template/SFML Template/Resources/res/title.png"

#define PLAY_BUTTON_FILEPATH "/Users/aviparshionikar/Documents/SFML/SFML Template/SFML Template/Resources/res/PlayButton.png"

#define PIPE_UP_FILEPATH "/Users/aviparshionikar/Documents/SFML/SFML Template/SFML Template/Resources/res/PipeUp.png"
#define PIPE_DOWN_FILEPATH "/Users/aviparshionikar/Documents/SFML/SFML Template/SFML Template/Resources/res/PipeDown.png"
#define SCORING_PIPE_FILEPATH "/Users/aviparshionikar/Documents/SFML/SFML Template/SFML Template/Resources/res/InvisibleScoringPipe.png"

#define PIPE_MOVEMENT_SPEED 200.0f

#define PIPE_SPAWN_FREQUENCY 6.0f

#define LAND_FILEPATH "/Users/aviparshionikar/Documents/SFML/SFML Template/SFML Template/Resources/res/Land.png"

#define BIRD_FRAME_1_FILEPATH "/Users/aviparshionikar/Documents/SFML/SFML Template/SFML Template/Resources/res/bird-01.png"
#define BIRD_FRAME_2_FILEPATH "/Users/aviparshionikar/Documents/SFML/SFML Template/SFML Template/Resources/res/bird-02.png"
#define BIRD_FRAME_3_FILEPATH "/Users/aviparshionikar/Documents/SFML/SFML Template/SFML Template/Resources/res/bird-03.png"
#define BIRD_FRAME_4_FILEPATH "/Users/aviparshionikar/Documents/SFML/SFML Template/SFML Template/Resources/res/bird-04.png"

#define BIRD_ANIMATION_DURATION 0.4f
#define BIRD_STATE_FALLING 1
#define BIRD_STATE_FLYING 2
#define BIRD_STATE_STILL 3

#define GRAVITY 350.0f
//350
#define FLYING_SPEED 350.0f
//350
#define FLYING_DURATION 0.25f
//.25

#define ROTATION_SPEED 100.0f

enum GameStates
{
    eReady,
    ePlaying,
    eGameOver,
    
};

#define FLASH_SPEED 1500.0f

#define FLAPPY_FONT_FILEPATH "/Users/aviparshionikar/Documents/SFML/SFML Template/SFML Template/Resources/fonts/FlappyFont.ttf"
#define GAME_OVER_BODY_FILEPATH "/Users/aviparshionikar/Documents/SFML/SFML Template/SFML Template/Resources/res/Game-Over-Body.png"
#define GAME_OVER_TITLE_FILEPATH "/Users/aviparshionikar/Documents/SFML/SFML Template/SFML Template/Resources/res/Game-Over-Title.png"
#define HIGHSCORE_FILEPATH "/Users/aviparshionikar/Documents/SFML/SFML Template/SFML Template/Resources/Highscore.txt"

#define TIME_BEFORE_GAME_OVER_APPEARS 1.5f

#define BRONZE_MEDAL_FILEPATH "/Users/aviparshionikar/Documents/SFML/SFML Template/SFML Template/Resources/res/Bronze-Medal.png"
#define SILVER_MEDAL_FILEPATH "/Users/aviparshionikar/Documents/SFML/SFML Template/SFML Template/Resources/res/Silver-Medal.png"
#define GOLD_MEDAL_FILEPATH "/Users/aviparshionikar/Documents/SFML/SFML Template/SFML Template/Resources/res/Gold-Medal.png"
#define PLATINUM_MEDAL_FILEPATH "/Users/aviparshionikar/Documents/SFML/SFML Template/SFML Template/Resources/res/Platinum-Medal.png"


#define BRONZE_MEDAL_SCORE 0
#define SILVER_MEDAL_SCORE 5
#define GOLD_MEDAL_SCORE 25
#define PLATINUM_MEDAL_SCORE 100
#define CLOSED_PALM_FILEPATH "/Users/aviparshionikar/Documents/SFML/SFML Template/SFML Template/Resources/closed_palm_effective1.xml"




