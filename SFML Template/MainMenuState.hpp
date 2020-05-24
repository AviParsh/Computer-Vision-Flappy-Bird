#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"


namespace avi
{
    class MainMenuState : public State
    {
    public:
        MainMenuState(GameDataRef data);
        
        void Init();
        
        void HandleInput();
        void HandleCamInput();
        void Update(float dt);
        void Draw (float dt);
        
        
    private:
        GameDataRef _data;

        sf::Sprite _title;
        sf::Sprite _playButton;
        sf::Sprite _background;
        
    
    };
    


}
