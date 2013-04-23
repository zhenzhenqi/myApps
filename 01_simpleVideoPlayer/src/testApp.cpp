#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    //this let's us draw the movie with transparent tinting
    ofEnableAlphaBlending();
    
    player.loadMovie("cat.mov");
    player.play();
    
    //you can change the loop settings this way
    player.setLoopState(OF_LOOP_NONE);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    player.update();
    int sampleX = ofClamp(mouseX,0,player.getWidth()-1);
    int sampleY = ofClamp(mouseY,0,player.getHeight()-1);
    ofColor sample = player.getPixelsRef().getColor(sampleX, sampleY);
    
    ofBackground(sample);
    
    //we can tint the video here, the different colors stand for red, green, blue, alpha (transparency)
    ofSetColor(255,255,255,128);
    
    player.draw(0,0);
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    if(key == ' '){
        if(player.isPlaying()){
            player.stop();
        }
        else {
            player.play();
        }
    }
    
    if(key == 'f'){
        ofToggleFullscreen();
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