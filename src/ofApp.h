#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxTello.h"

class ofApp : public ofBaseApp {

public:
	int camWidth, camHeight;
	long addedPixelPosX, addedPixelPosY;
	int centerX, centerY;
	int binPixelsCounter;
	int distance, angle, speed;

	ofVideoGrabber vidGrabber;
	ofImage imgFrame;
	ofxTello tello;

	void setup();
	void update();
	void draw();

	void setVidGrabber();
	void resetCounters();
	void binarizeFrame(ofPixelsRef& pixels);
	void addPixelPositions(int x, int y);
	void setObjectCenter();
	void drawCrosshair(ofPixelsRef& pixels, ofColor color);
	void drawFlanks(ofPixelsRef& pixels);
	void drawVerticalLine(ofPixelsRef& pixels, int x);
	void printPixelData();
	int isHorizontalAligned(int x);

	// TELLO METHODS
	void setupDrone();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
};
