#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    player.loadMovie("cat.mov");
    if(!player.isLoaded()){
        ofLog(OF_LOG_NOTICE, "movie not loaded");
    }else{
    player.play();
        ofLog(OF_LOG_WARNING, "player is playing+%d", player.getCurrentFrame());
    }
    
    allFrames.resize(10);
    framePointer = 0;
    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::update(){
    ofLog(OF_LOG_WARNING, "update begin, frame pointer is+%d",framePointer);
    player.update();
    if(player.isFrameNew()){
        
        allFrames[framePointer].setFromPixels(player.getPixelsRef());
                ofLog(OF_LOG_WARNING, "update saved frame inside if+%d",framePointer);
        framePointer++;

        if(framePointer >= allFrames.size()){
            framePointer = 0;
        }
        
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    //ofColor(255,255);
    player.draw(0, 0);
    ofLog(OF_LOG_WARNING, "player is playing frame+%d",player.getCurrentFrame());
    
    ofColor(255,255,255,100);
    allFrames[framePointer].draw(0, player.getHeight());
    
    
    ofLog(OF_LOG_WARNING, "drawer is drawing+%d",framePointer);
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
    //allFrames.push_back(tempImage.setFromPixels(Player.getPixelsRef()));
    

    for (int y=0; y<player.getHeight(); y++){
        for (int x=0; x<player.getWidth(); x++){
            ofColor newPixel = player.getPixelsRef().getColor(x, y);
            accumulation.setColor(x,y,newPixel); 
        }
    }
    accumulation.reloadTexture();
    allFrames.push_back(accumulation);
    
    
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