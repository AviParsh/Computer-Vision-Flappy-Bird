#include <sstream>
#include "SplashState.hpp"
#include "MainMenuState.hpp"
#include "DEFINITIONS.hpp"
#include <iostream>

namespace avi
{
    SplashState::SplashState(GameDataRef data) : _data(data)
    {
    
    }

    void SplashState::Init()
    {
        //_data->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);
        //_background.setTexture(this->_data->assets.GetTexture("Splash State Background"));
        
    }


    void SplashState::HandleInput()
    {
        sf::Event event;
        while ( _data->window.pollEvent(event))
        {
            if(sf::Event::Closed==event.type)
            {
                _data->window.close();
                
            }
        }
        
        
    }

    void SplashState::HandleCamInput()
    {
        sf::Event event;
        while ( _data->window.pollEvent(event))
        {
            if(sf::Event::Closed==event.type)
            {
                _data->window.close();
                
            }
        }
        
    }


    void SplashState::Update(float dt)
    {
        if(_clock.getElapsedTime().asSeconds()>SPLASH_STATE_SHOW_TIME)
        {
            _data->machine.AddState(StateRef(new MainMenuState(_data)),true);
            
        }
            
            
    }
                               

    void SplashState::Draw(float dt)
    {
        _data->window.clear();
        _data->window.draw(_background);
        _data->window.display();
        
    }


}
