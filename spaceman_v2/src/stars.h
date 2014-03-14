#ifndef STAR_H
#define STAR_H


#include "ofMain.h"

class star{
    
public:
    
    star();
	
    void update();
    void draw();
    
    int xPos, yPos, starSize;
    float flickerRate, light;
    bool rise;
    
    
};

#endif // STAR_H
