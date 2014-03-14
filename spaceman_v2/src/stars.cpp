#include "stars.h"

star::star(){
    
    flickerRate = ofRandom(2,5);
    starSize = int(ofRandom(2,5));
    
    xPos =int(ofRandom(0,ofGetWindowWidth()-starSize));
    yPos =int(ofRandom(0,ofGetWindowHeight()-starSize));
    light = ofRandom(10,245);
    rise = true;
    
    
}


void  star::draw() {
    
    if(light >=255){
        
        rise = false;
    }
    
    if (light <=10){
        
        flickerRate = ofRandom(2,8);
        starSize =ofRandom(2,3);
        rise = true;
        xPos =int(ofRandom(0,ofGetWindowWidth()-starSize));
        yPos =int(ofRandom(0,ofGetWindowHeight()-starSize));
        
    }
    if (rise == true){
        light += flickerRate;
        
    }
    
    if(rise == false){
        light -= flickerRate;
        
    }
    ofSetColor(light);
    ofRect(xPos, yPos, starSize, starSize);
    
}




