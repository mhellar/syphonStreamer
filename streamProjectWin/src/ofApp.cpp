#include "ofApp.h"
//Listen to localhost
#define HOST "127.0.0.1"

//create osc message object
ofxOscMessage m;
string incomingAddr;
string incomingVal;


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("SyphonStreamer");
    ofSetWindowShape(11520,2160);
    ofSetFrameRate(60);
    panel.setup();
    receiver.setup(8000);
    shadertoy.load("shaders/tdm_Seascape.frag");
    shadertoy.setAdvanceTime(true);
	spoutReceiver.setup();

   
}


//--------------------------------------------------------------
void ofApp::update(){

	spoutReceiver.updateTexture();
	spoutReceiver.getTexture().draw(0, 0, 3840, 2160);

    while(receiver.getNextMessage(m)) {
        //just print out the address of the message
        //        cout << m.getAddress() + " " + ofToString(m.getArgAsFloat(0)) << endl;
        
        //create a string to hold the incoming arguments
        string msg_string;
        msg_string = m.getAddress();
        msg_string += ": ";
        
        while(receiver.getNextMessage(m)) {
            //just print out the address of the message
            //        cout << m.getAddress() + " " + ofToString(m.getArgAsFloat(0)) << endl;
            incomingAddr = m.getAddress();
            //create a string to hold the incoming arguments
            string msg_string;
            msg_string = m.getAddress();
            msg_string += ": ";
            
            //loop through the incoming arguments check their type and conver to string as needed
            for(int i = 0; i < m.getNumArgs(); i++){
                // get the argument type
                msg_string += m.getArgTypeName(i);
                msg_string += ":";
                // display the argument - make sure we get the right type
                if(m.getArgType(i) == OFXOSC_TYPE_INT32){
                    msg_string += ofToString(m.getArgAsInt32(i));
                    incomingVal = ofToString(m.getArgAsInt32(i));
                }
                else if(m.getArgType(i) == OFXOSC_TYPE_FLOAT){
                    msg_string += ofToString(m.getArgAsFloat(i));
                    incomingVal = ofToString(m.getArgAsFloat(i));
                }
                else if(m.getArgType(i) == OFXOSC_TYPE_STRING){
                    msg_string += m.getArgAsString(i);
                    incomingVal = m.getArgAsString(i);
                }
                else{
                    msg_string += "unknown";
                }
                ofLog(OF_LOG_NOTICE, msg_string);
                
            }
        }
        

    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 0, 0);
    ofColor(255, 255, 255, 255);
    ofEnableAlphaBlending();

        ofPushMatrix();
        glPushMatrix();
    glTranslatef(50,50,0);
    
    glPopMatrix();
    ofPopMatrix();
    ofDrawBitmapString("Press any key to cycle through all available Syphon servers.", ofPoint(10, 10));
    ofDrawBitmapString(incomingAddr, 0, 20);
    ofDrawBitmapString(incomingVal, 0, 30);
//    if(incomingAddr == "/1/fader1"){
//        int l = ofMap(ofToFloat(incomingVal),0.0,0.1,0,255);
//        ofPushStyle();
//        ofSetColor(255,l,0,l);
//
//        ofPopStyle();
//    }
    panel.drawBG(0, 0,11520,2160);
    shadertoy.draw(0, 0,11520,2160);
 //   client.draw(3840,0,3840,2160);
	spoutReceiver.updateTexture();
	spoutReceiver.getTexture().draw(3840, 2160, -3840, -2160);
    

}

void ofApp::exit() {
	spoutReceiver.exit();
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'f':
            ofToggleFullscreen();
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    //press any key to move through all available Syphon servers

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
