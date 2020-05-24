#pragma once


#include <SFML/Graphics.hpp>

namespace avi

{

    class Collision
    {
    public:
        Collision();
        
        bool checkSpriteCollision(sf::Sprite sprite1,sf::Sprite sprite2);
        bool checkSpriteCollision(sf::Sprite sprite1,float scale1,sf::Sprite sprite2,float scale2);

    
    
    };








}
