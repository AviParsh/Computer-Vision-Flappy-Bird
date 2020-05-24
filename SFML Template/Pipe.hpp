#pragma once

#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include <vector>


namespace avi
{

    class Pipe
    {
    public:
        Pipe(GameDataRef data);
        void DrawPipes();
        void SpawnBottomPipe();
        void SpawnTopPipe();
        void SpawnInvisiblePipe();
        void MovePipes(float dt);
        void RandomizePipeOffset();
        
        void SpawnScoringPipe();
        
        
        
        const std::vector <sf::Sprite> &GetSprites() const;
        std::vector<sf::Sprite> &GetScoringSprites();
        
        
        
    private:
        GameDataRef _data;
        std::vector<sf::Sprite> pipeSprites;
        std::vector<sf::Sprite> scoringPipes;
        
        int _landHeight;
        int _pipeSpawnYOffset;
        
        
    };








}
