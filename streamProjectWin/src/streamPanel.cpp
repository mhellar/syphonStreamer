//
//  streamPanel.cpp
//  streamProject
//
//  Created by Mark Hellar on 4/1/18.
//

#include "ofMain.h"
#include "streamPanel.h"


void streamPanel::setup(){
    imgBG.load("background.jpg");
}


//you can define arguments to pass to a function here int x and y also declare in the header file for your class
void streamPanel::drawBG(int x, int y,int h,int w){
    ofColor(255,255,255);
    imgBG.draw(x,y,h,w);
}



