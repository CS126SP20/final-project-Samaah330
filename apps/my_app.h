// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include <cinder/audio/Voice.h>
#include <mylibrary/bird.h>
#include <mylibrary/enginepipe.h>
#include <mylibrary/pipe.h>

#include <random>

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
  mylibrary::EnginePipe engine_pipe_;
  void DrawGameOver();
  void DrawBackground();
  void StoreScore();
  void PrintScore();
  void PlayFlyingAudio();
  int score_ = 0;
  cinder::audio::VoiceRef flying_audio_;
  bool is_game_over_ = false;
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
