#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
//    ofSetupOpenGL(11520,2160,OF_WINDOW);            // <-------- setup the GL context
    
    ofGLWindowSettings settings;
    settings.setGLVersion(3, 2);    // <--- ofxShadertoy NEEDS the GL Programmable Renderer
    settings.width = 11520;
    settings.height = 2160;
    ofCreateWindow(settings);       // <-------- setup the GL context
    

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
