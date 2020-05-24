#include "Game.hpp"
#include "SplashState.hpp"

#include <stdlib.h>
#include <time.h>
#include <iostream>

namespace avi
{

Game::Game(int width, int height, std::string title)

{
    srand(time(NULL));
    
    _data->window.create(sf::VideoMode(width,height),title, sf::Style::Close | sf::Style::Titlebar);
    _data->machine.AddState(StateRef(new SplashState(this->_data)));
    
    this->Run();
    
    
}


void Game::Run()
{
    
    float newTime, frameTime, interpolation;
    float currentTime = this->_clock.getElapsedTime().asSeconds();
    float accumulator = 0.0f;
    
    int i = 0;

    while(this->_data->window.isOpen())
    {
        this->_data->machine.ProcessStateChanges();
        
        newTime =this->_clock.getElapsedTime().asSeconds();
        frameTime = newTime-currentTime;
        
        if(frameTime>0.25f){
            frameTime=0.25f;
        }
        
        currentTime = newTime;
        accumulator+=frameTime;
        
        //accumulator>=dt
        //while(accumulator>=dt)
      //  {
            cv::waitKey(1);
            
            
            
            this->_data->machine.GetActiveState()->HandleCamInput();
            
            this->_data->machine.GetActiveState()->Update(dt);
            
            accumulator-=dt;
            
      //  }
        
        
        interpolation  = accumulator/dt;
        this->_data->machine.GetActiveState()->Draw(dt);
        
        
    }
    
    
    
}



}
