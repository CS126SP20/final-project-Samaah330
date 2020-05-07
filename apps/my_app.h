// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/Color.h>
#include <cinder/app/App.h>
#include <cinder/audio/Voice.h>
#include <mylibrary/bird.h>
#include <mylibrary/pipe.h>
#include <mylibrary/pipe_engine.h>

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
  void DrawGameOver() const;
  void DrawMainMenu();
  void DrawBackground() const;
  void StoreScore() const;
  void PrintScore() const;
  void PlayJumpAudio();
  bool DidBirdCollide();

  list<mylibrary::Pipe> pipes_;
  mylibrary::Bird bird_;
  mylibrary::Pipe_Engine pipe_engine_;
  cinder::audio::VoiceRef jump_audio_;
  bool is_game_over_ = false;
  bool is_main_menu_state_ = true;
  size_t playing_state_num_frames_ = 0;
  size_t score_ = 0;
  const size_t kNumPipes_ = 5;
  const size_t kBeginningGameNumFrames_ = 150;
  const size_t kGrassHeight_ = 350;
  const size_t kScoreSize_ = 100;
  const size_t kPlayInstructionsSize_ = 80;
  const size_t kGameNameSize_ = 100;
  const size_t kGameOverSize = 200;
  const size_t kPlayAgainSize = 70;
  const cinder::Color kBlackColor = cinder::Color::black();
  const cinder::Color kColorWhite = cinder::Color::white();
  const cinder::vec2 kScorePosition_ =
      cinder::vec2(cinder::app::getWindowWidth() - 170,
                   cinder::app::getWindowHeight() - 100);
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
