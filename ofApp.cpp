#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(0);
	ofSetCircleResolution(72);

}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	ofSeedRandom(39);
	for (int i = 0; i < 5; i++) {

		auto noise_seed = glm::vec2(ofRandom(1000), ofRandom(1000));
		for (int k = 0; k < 100; k++) {

			auto location = glm::vec2(
				ofMap(ofNoise(noise_seed.x, ofGetFrameNum() * 0.005 + k * 0.005), 0, 1, -340, 340),
				ofMap(ofNoise(noise_seed.y, ofGetFrameNum() * 0.005 + k * 0.005), 0, 1, -340, 340));

			ofSetColor(255);
			ofDrawCircle(location, ofMap(k, 0, 100, 1, 22));
		}
	}

	ofSeedRandom(39);
	for (int i = 0; i < 5; i++) {

		auto noise_seed = glm::vec2(ofRandom(1000), ofRandom(1000));
		for (int k = 0; k < 100; k++) {

			auto location = glm::vec2(
				ofMap(ofNoise(noise_seed.x, ofGetFrameNum() * 0.005 + k * 0.005), 0, 1, -340, 340),
				ofMap(ofNoise(noise_seed.y, ofGetFrameNum() * 0.005 + k * 0.005), 0, 1, -340, 340));

			ofSetColor(0);
			ofDrawCircle(location, ofMap(k, 0, 100, 0, 20));
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}