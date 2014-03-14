#include "testApp.h"
#include "ofMain.h"



//--------------------------------------------------------------
void testApp::setup(){
    ////////////stars
    ofBackground(30);
    for(int i=0; i<=300; i++) {
        star stars;
        myStars.push_back(stars);
    }

    
	spaceman.loadImage("spaceman.png");
    
    ofSetVerticalSync( true );
    ofSetFrameRate( 60 );
    
    soundStream.listDevices();
    
	int bufferSize = 256;
    
	left.assign(bufferSize, 0.0);
	volHistory.assign(400, 0.0);
	bufferCounter	= 0;
	drawCounter		= 0;
	smoothedVol     = 0.0;
	scaledVol		= 0.0;
	soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
    
    position.x = ofGetWidth()/2.0;
    position.y = ofGetHeight()/2.0;
    velocity.x = 8;
    velocity.y = 5;
    currentModeStr = "1 - sound stream [on]";
    
   
}

//--------------------------------------------------------------
void testApp::update(){
    
    //////stars
    for (int i = 0; i < NUM; i++){
        time[i]= ofRandom(20);
    }

    
 	scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 3, true);
	float wave = cos(ofGetElapsedTimef());
    //rotated = (wave+15)*scaledVol*100;
    rotated += wave*scaledVol*30;
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    //////stars
    for(int i=0; i<= myStars.size(); i++){
        myStars[i].draw();
    }

    
    
    
    ofPushMatrix();
    
    cout << rotated << endl;
    
    position += (velocity * scaledVol);
    
    if (position.x > ofGetWindowWidth() || position.x < 0)
    {
        velocity.x *= -1;
    }
    if (position.y > ofGetWindowHeight() || position.y < 0)
    {
        velocity.y *= -1;
    }
    ofTranslate(position);
    
    ofRotate(rotated);
    ofTranslate(-spaceman.getWidth()/2, -spaceman.getHeight()/2);
    ofSetColor(ofColor::white);
    spaceman.draw(0, 0); // notice
    ofPopMatrix();
    
    ofDrawBitmapString(currentModeStr + "\nKeys 1-3 to change mode.", 10, 20);
    
}
//--------------------------------------------------------------
void testApp::audioIn(float * input, int bufferSize, int nChannels){
    
    
	float curVol = 0.0;
	int numCounted = 0;
	for (int i = 0; i < bufferSize; i++){
		left[i]		= input[i*2]*0.5;
		curVol += left[i] * left[i];
		numCounted+=2;
	}
	
	curVol /= (float)numCounted;
	curVol = sqrt( curVol );
	smoothedVol *= 0.93;
	smoothedVol += 0.07 * curVol;
	bufferCounter++;
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    if( key == '1' ){
		soundStream.start();
        currentModeStr = "1 - sound stream [on]"; 
	}
    
	if( key == '2' ){
		soundStream.stop();
        currentModeStr = "2 - sound stream [off]"; 
	}
    if (key == '3')
    {
        position.x = ofGetWindowWidth()/2;
        position.y = ofGetWindowHeight()/2;
        currentModeStr = "spaceman back to the center"; 
    }


}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
