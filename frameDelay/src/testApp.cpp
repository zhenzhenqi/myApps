#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    player.loadMovie("heads.mov");
    player.play(); 
    player.setLoopState(OF_LOOP_NONE);
    
    framePointer = 0;
    allFrames.resize(player.getTotalNumFrames());
    
    myFbo.allocate(player.width, player.height);
}

//--------------------------------------------------------------
void testApp::update(){
    player.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    player.draw(0, 0, player.getWidth(), player.getHeight());
    
    if(player.isFrameNew()){
        allFrames[framePointer].setFromPixels(player.getPixelsRef());
        framePointer++;
    }
    
    if(framePointer>20){
        myFbo.begin();
            
        ofPushStyle();
        ofEnableAlphaBlending();
        ofSetColor(255, 255, 255, 100);
        allFrames[framePointer-10].draw(0,0);
        allFrames[framePointer-15].draw(0,0);
        allFrames[framePointer-20].draw(0,0);
        ofPopStyle();
        myFbo.end();
        myFbo.draw(0, 0);
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

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