//
//  streamPanel.hpp
//  streamProject
//
//  Created by Mark Hellar on 4/1/18.
//

#include <stdio.h>
#include "ofMain.h"


class streamPanel{
public:
    //methods
    void setup();
    void drawBG(int x,int y,int h, int w);
    
    //properties
    ofImage imgRight;
    ofImage imgLeft;
    ofImage imgTop;
    ofImage imgBottom;
    ofImage imgBG;
    int imgBGA;
    
    
};
