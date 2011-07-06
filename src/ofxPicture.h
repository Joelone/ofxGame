/*
 *  ofxBanner.h
 *
 *  Created by Patricio González Vivo on 03/07/11.
 *  Copyright 2011 PatricioGonzalezVivo.com. All rights reserved.
 *
 */

#ifndef OFXPICTURE
#define OFXPICTURE

#include "ofxGameObj.h"

class ofxPicture : public ofxGameObj {
public:
	ofxPicture(string _objName = "background"){
		objectName = _objName; 
		loadXml();
		image.allocate(width, height, OF_IMAGE_COLOR_ALPHA);
		image.loadImage(file);
		width	= image.getWidth();
		height	= image.getHeight();
		saveXml();
	}

	void draw(){ draw(x,y); };
	void draw(int _x, int _y){
		ofPushMatrix();
		ofTranslate(_x-getScaledWidth()*0.5,_y-getScaledHeight()*0.5);
		ofScale(scale, scale);
		
		ofSetColor(255, 255);
		image.draw(0,0);
		
		if (*bDebug)
			drawBoundingBox();
		
		ofPopMatrix();
	};
	
protected:
	ofImage	image;
	
};
#endif