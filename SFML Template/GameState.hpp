#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Pipe.hpp"
#include "Land.hpp"
#include "Bird.hpp"
#include "Collision.hpp"
#include "Flash.hpp"
#include "HUD.hpp"


namespace avi
{
    class GameState : public State
    {
    public:
        GameState(GameDataRef data);
        
        void Init();
        
        void HandleInput();
        void HandleCamInput();
        void Update(float dt);
        void Draw (float dt);
        
        
    private:
        GameDataRef _data;
        sf::Sprite _background;
        Pipe *pipe;
        Land *land;
        Bird *bird;
        Collision collision;
        Flash *flash;
        HUD *hud;
        
        
        
        sf::Clock _clock;
        
        int _gameState;
        int _score;
         
        
    
    };
    


}
