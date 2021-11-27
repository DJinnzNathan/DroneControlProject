# Drone Control Project
This is a project from the course "Interaktion" from TH Nuremberg. Our goal was to build a program that lets a dji Tello drone recognizes and follows an object.

## Requirements
- [openFrameworks](https://openframeworks.cc/download/)
- IDE (i.e. Visual Studio 2019)
- dependencies: ofxOpenCV, ofxNetwork, [ofxTello by kikpond15](https://github.com/kikpond15/ofxTello)
- [dji Tello Edu Drone](https://www.ryzerobotics.com/tello)
- [Tello SDK](https://terra-1-g.djicdn.com/2d4dce68897a46b19fc717f3576b7c6a/Tello%20%E7%BC%96%E7%A8%8B%E7%9B%B8%E5%85%B3/For%20Tello/Tello%20SDK%20Documentation%20EN_1.3_1122.pdf)

## Setup
To start developing, head over to the unzipped openFrameworks-folder. 
- First you need to add the third-party addon by @kikpond15. Head over to __*addons__ in the openFrameworks-folder and create a folder called __ofxTello__.
- Insert all the files of [his project (ofxTello)](https://github.com/kikpond15/ofxTello) in that folder.
- Next, go to __*apps / myApps*__. Create a folder inside __*myApps*__ with a project name of your choice.
- Copy all the files inside this project to the new folder. 
- Go back to the openFrameworks-root and go to __*projectGenerator*__. Start the application and go to __Import__ and select your created folder.
- Click on __Addons__ and select _ofxOpenCV_, _ofxTello_ and _ofxNetwork_.
- Click update and wait until finished.

Now you can open the project with your IDE and start developing.

## Goal