#pragma once

#include <SFML/Graphics.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include "DEFINITIONS.hpp"
#include <iostream>

namespace avi
{

    class InputManager
    {
    
    public:
        
        InputManager();
        ~InputManager(){};
        
        bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
        cv::Rect IsPalmClosed();
        bool IsPalmClosedNormal();
        int test();
        
        cv::VideoCapture getCap();
        
        void setFound(bool _found);
        bool getFound();
        sf::Vector2i GetMousePosition( sf::RenderWindow &window);
        
    private:
        cv::CascadeClassifier closed_palm_cascade;
        cv::VideoCapture cap;
        bool found;
        cv::Rect lastPos;
        
        
    };










}
