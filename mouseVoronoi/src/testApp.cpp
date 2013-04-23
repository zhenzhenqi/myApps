#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    needRedraw=false;
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    if(!needRedraw)return;
    
    ofBackground(255, 255, 255);
    float w = ofGetWidth();
    float h = ofGetHeight();
    
    for(int x=0; x<w && (xs.size()>0); x+=4){
        for(int y=0; y<h; y+=4){
            int idx = 0;
            float dd;
            dd = ofDist(xs[0],ys[0],x,y);
            for(int i=0; i<xs.size(); i++){
                float d0 = ofDist(xs[i], ys[i],x,y);
                if(dd>d0){
                    dd=d0;
                    idx=i;
                }
            }
            ofSetColor(c[idx]);
            ofRect(x,y,4,4);
        }
    }
    ofSetColor(255);
    for(int i=0; i<xs.size(); i++){
        ofEllipse(xs[i], ys[i], 10, 10);
    }
    needRedraw = false;
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    xs.push_back(mouseX);
    ys.push_back(mouseY);
    d.push_back(0);
    ofColor cl(ofRandom(255), ofRandom(255), ofRandom(255));
    c.push_back(cl);
    
    needRedraw = true;
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