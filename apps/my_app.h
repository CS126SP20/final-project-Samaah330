// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include <mylibrary/bird.h>
#include <mylibrary/pipe.h>
#include <cinder/audio/Voice.h>

namespace myapp {

class MyApp : public cinder::app::App {
 public:
  MyApp();
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;

 private:
  mylibrary::Bird bird_;
  mylibrary::Pipe pipe_;
  void DrawGameOver();
  void DrawBackground();
  void DrawPipes();
  void DrawMainMenu(); // do at the end
  void DrawBird();
  void PauseGame(); // end
  void ResumeGame(); // end
  void SetUpFlyingAudio();
  const float bird_size = 30;
  int score_ = 0;
  cinder::audio::VoiceRef flying_audio;
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
