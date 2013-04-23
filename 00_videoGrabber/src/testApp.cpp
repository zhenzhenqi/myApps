#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    grabber.setVerbose(true);
    grabber.initGrabber(640, 480);
}

//--------------------------------------------------------------
void testApp::update(){
    grabber.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    grabber.draw(grabber.getWidth(), 0, -grabber.getWidth(), grabber.getHeight());
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