#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	//Setup VideoGrabber
	camWidth = 640;  // try to grab at this size.
	camHeight = 480;

	setVidGrabber();
}

//--------------------------------------------------------------
void ofApp::update() {
	ofPixelsRef pixels = vidGrabber.getPixels();

	resetCounters();

	binarizeFrame(pixels);
	setObjectCenter();
	cout << "Absolutposition: " << addedPixelPosX << ", " << addedPixelPosY << endl;
	cout << "Anzahl: " << binPixelsCounter << endl;
	cout << "Zentrum: " << centerX << ", " << centerY << "\n" << endl;

	drawCrosshair(pixels);

	imgFrame.setFromPixels(pixels);

	ofBackground(100, 100, 100);
	vidGrabber.update();
	imgFrame.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetHexColor(0xffffff);
	vidGrabber.draw(20, 20);
	imgFrame.draw(vidGrabber.getWidth(), 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 's' || key == 'S') {
		vidGrabber.videoSettings();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

void ofApp::setVidGrabber()
{
	//get back a list of devices.
	vector<ofVideoDevice> devices = vidGrabber.listDevices();

	for (size_t i = 0; i < devices.size(); i++)
	{
		if (devices[i].bAvailable)
		{
			//log the device
			ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
		}
		else
		{
			//log the device and note it as unavailable
			ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
		}
	}

	vidGrabber.setDeviceID(0);
	vidGrabber.setDesiredFrameRate(30);
	vidGrabber.initGrabber(camWidth, camHeight);
}

void ofApp::resetCounters()
{
	addedPixelPosX = 0, addedPixelPosY = 0;
	binPixelsCounter = 0;
	centerX = 0, centerY = 0;
}

void ofApp::binarizeFrame(ofPixelsRef& pixels)
{
	for (int y = 0; y < vidGrabber.getHeight(); y++) {
		for (int x = 0; x < vidGrabber.getWidth(); x++)
		{
			//get Color from Frame and convert to HUE
			ofColor color = pixels.getColor(x, y);
			float hueAngle = color.getHueAngle();
			float hueSaturation = color.getSaturation();

			//delete everything but highly saturated red pixels

			if (((340 <= hueAngle) || (hueAngle <= 14)) && (hueSaturation >= 200))
			{
				pixels.setColor(x, y, ofColor::white);
				addPixelPositions(x, y);
				binPixelsCounter++;
			}
			else {
				pixels.setColor(x, y, ofColor::black);
			}
		}
	}
}

void ofApp::addPixelPositions(int x, int y)
{
	addedPixelPosX += x;
	addedPixelPosY += y;
}

void ofApp::setObjectCenter()
{
	//get center coordinates for greatest mass of red
	if (addedPixelPosX > 0 && binPixelsCounter != 0) {
		centerX = addedPixelPosX / binPixelsCounter;
	}
	else {
		centerX = camWidth / 2;
	}

	if (addedPixelPosY > 0 && binPixelsCounter != 0) {
		centerY = addedPixelPosY / binPixelsCounter;
	}
	else {
		centerY = camHeight / 2;
	}
}

void ofApp::drawCrosshair(ofPixelsRef& pixels)
{
	if (binPixelsCounter > 200) {
		for (int i = 0; i < 10; i++) {
			if (centerX + i < camWidth) pixels.setColor(centerX + i, centerY, ofColor::red);
			if (centerY + i < camHeight) pixels.setColor(centerX, centerY + i, ofColor::red);
			if (centerX - i > 0) pixels.setColor(centerX - i, centerY, ofColor::red);
			if (centerY - i > 0) pixels.setColor(centerX, centerY - i, ofColor::red);
		}
	}
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
