#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    bDrawingFirst = true;
    ofBackground(255, 255, 255);
    bDrawing = false;
    mytimer.start();
    //ofSetFrameRate(1);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(0, 0, 0);
    ofFill();
    
    
    if(bDrawing){
        if(bDrawingFirst) lineA.draw();
        else lineB.draw();
    }
    
    
    
    if (lineA.getVertices().size()>0 && lineA.getVertices().size()==lineB.getVertices().size()){
        cout << "mixing is starting" << endl;
        ofPolyline mix;
        mix.resize(lineA.getVertices().size());
        cout << "timer is starting" << endl;
        ofLog(OF_LOG_WARNING, "saved time = %d",mytimer.savedTime);
        ofLog(OF_LOG_WARNING, "passed time = %d",mytimer.passedTime);
        
        if (mytimer.isFinished()){
        cout << "timer is finished" << endl;
            for(int mixRatio=0; mixRatio<101; mixRatio++){
            for (int i = 0; i < lineA.getVertices().size(); i++){
                mix.getVertices()[i] = (1-mixRatio/100)*lineA.getVertices()[i] +
                (mixRatio/100)*lineB.getVertices()[i];
            }
            mix.draw();
            mytimer.start();
            }
        }
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
    if(bDrawingFirst==true){
    lineA.addVertex(ofPoint(x,y));
    }else{
        lineB.addVertex(ofPoint(x,y));
    }
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    if(bDrawingFirst==true){
        lineA.clear();
        lineA.addVertex(ofPoint(x,y));
    }else{
        lineB.clear();
        lineB.addVertex(ofPoint(x,y));
    }
    bDrawing = true;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    if(lineA.getVertices().size()>0){
        lineA = lineA.getResampledByCount(250);
    }
    if(lineB.getVertices().size()>0){
        lineB = lineB.getResampledByCount(250);
    }
    bDrawingFirst = !bDrawingFirst;
    bDrawing = false;
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