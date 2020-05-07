// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <cinder/app/App.h>


#include <cinder/Font.h>
#include <cinder/Text.h>
#include <cinder/Vector.h>
#include <cinder/gl/draw.h>
#include <cinder/gl/gl.h>
#include <string>
#include <nlohmann/json.hpp>


namespace myapp { // --> rename myapp
using cinder::Color;
using cinder::ColorA;
using cinder::Rectf;
using cinder::TextBox;
using cinder::app::KeyEvent;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::system_clock;
using std::string;

#if defined(CINDER_COCOA_TOUCH)
const char kNormalFont[] = "Arial";
const char kBoldFont[] = "Arial-BoldMT";
const char kDifferentFont[] = "AmericanTypewriter";
#elif defined(CINDER_LINUX)
const char kNormalFont[] = "Arial Unicode MS";
const char kBoldFont[] = "Arial Unicode MS";
const char kDifferentFont[] = "Purisa";
#else
const string kNormalFont = "Arial";
const string kBoldFont = "Arial Bold";
const string kDifferentFont = "Papyrus";
#endif

using cinder::app::KeyEvent;

MyApp::MyApp() { }

template <typename C>
void PrintText(const std::string& text, const C& color,
    const cinder::ivec2& size, const cinder::vec2& loc, const int font_size) {

  cinder::gl::color(color);

  auto box = cinder::TextBox()
      .alignment(cinder::TextBox::LEFT)
      .font(cinder::Font(kNormalFont, font_size))
      .size(size)
      .color(color)
      .backgroundColor(ColorA
                           (0, 0, 0, 0))
      .text(text);

  const auto box_size = box.getSize();
  const cinder::vec2 locp =
      {loc.x - box_size.x / 2, loc.y - box_size.y / 2};
  const auto surface = box.render();
  const auto texture = cinder::gl::Texture::create(surface);

  cinder::gl::draw(texture, locp);
}

void MyApp::setup() {
  pipe_engine_.AddPipes(kNumPipes_);
}

void MyApp::update() {
  pipe_engine_.UpdatePipesPosition();
  if (!is_main_menu_state_ &&
      playing_state_num_frames_ >= kBeginningGameNumFrames_) {
    bird_.UpdatePositionGravity();
  }
}

bool MyApp::DidBirdCollide() {
  pipes_ = pipe_engine_.GetPipes();

  /*
   * bird_.GetYPosition() <= cinder::app::getWindowHeight() - kGrassHeight_
   */
  if (is_game_over_) {
    return true;
  }

  for (mylibrary::Pipe& pipe_itr : pipes_) {
    if ((bird_.GetXPosition() >= pipe_itr.GetXPosition() &&
         bird_.GetXPosition() <= pipe_itr.GetX2Position()) &&
        (bird_.GetYPosition() <= pipe_itr.GetRandTopPipeHeight() ||
         bird_.GetYPosition() >= pipe_itr.GetRandBottomPipeHeight())) {
      return true;
    }
  }

  return false;
}

void MyApp::draw() {
  cinder::gl::clear(Color(0,0,0), true);

  if (is_main_menu_state_) {
    DrawMainMenu();
  }else if (DidBirdCollide() &&
            playing_state_num_frames_>= kBeginningGameNumFrames_) {
    is_game_over_ = true;
    DrawGameOver();
  } else {
    playing_state_num_frames_++;
    DrawBackground();
    bird_.Draw();
    pipe_engine_.DrawPipes();
    StoreScore();
    PrintScore();
  }
}

void MyApp::DrawGameOver() const {
  cinder::gl::clear(Color(1, 0, 0),
      true); // red

  const cinder::vec2 center = cinder::vec2(cinder::app::getWindowCenter().x,
      cinder::app::getWindowCenter().y );
  const cinder::ivec2 size = {1000, 300};;

  PrintText("Game Over :(", kBlackColor, size, center, kGameOverSize);

  const cinder::vec2 play_again_text_position =
      cinder::vec2(cinder::app::getWindowCenter().x + 50,
          cinder::app::getWindowHeight() - 200);

  StoreScore();
  PrintScore();

  PrintText("Press Tab Button to Play Again", kColorWhite, size,
      play_again_text_position, kPlayAgainSize);
}

void MyApp::DrawMainMenu() {
  DrawBackground();
  pipe_engine_.DrawPipes();

  const cinder::ivec2 size = {1000, 400};

  const Color game_name_color = Color(1, .8, 0); // orange

  const cinder::vec2 game_name_white_shadow_position =
      cinder::app::getWindowCenter();
  const cinder::vec2 game_name_position = cinder::vec2
      (cinder::app::getWindowCenter().x + 5,
          cinder::app::getWindowCenter().y);


  const cinder::vec2 play_instructions =
      cinder::vec2 (cinder::app::getWindowCenter().x,
          cinder::app::getWindowCenter().y + 750);

  PrintText("Flappy Bird", kColorWhite, size,
      game_name_white_shadow_position, kGameNameSize_);
  PrintText("Flappy Bird", game_name_color, size,
      game_name_position, kGameNameSize_);

  PrintText("Click 'P' Button to Play Game", kColorWhite, size,
            play_instructions, kPlayInstructionsSize_);
}

void MyApp::StoreScore() const {
  nlohmann::json score_json;

  std::string string_score = std::to_string(score_);
  score_json["Score"] = string_score;

  std::ofstream o("C:\\Users\\SamaahMachine\\Documents\\"
                  "cinder_0.9.2_vc2015\\myProjects\\final-project-Samaah330\\"
                  "assets\\score.json");
  o << std::setw(4) << score_json << std::endl;
  o.close();
}

void MyApp::PrintScore() const {

  std::ifstream in("C:\\Users\\SamaahMachine\\Documents\\"
                  "cinder_0.9.2_vc2015\\myProjects\\final-project-Samaah330\\"
                  "assets\\score.json");

  nlohmann::json score_file = nlohmann::json::parse(in);

  string score = score_file.at("Score");

  const cinder::ivec2 size = {500, 150};

  PrintText("Score: " + score, kBlackColor, size, kScorePosition_, kScoreSize_);
}

void MyApp::DrawBackground() const {
  cinder::gl::clear(Color(0.4, 0.69804, 1)); // blue

  cinder::gl::color(0.125, 0.3176, 0.1843); // dark green

  cinder::gl::drawSolidRect(Rectf(0,
      cinder::app::getWindowHeight() - kGrassHeight_,
      cinder::app::getWindowWidth(), cinder::app::getWindowHeight()));
}

void MyApp::PlayJumpAudio() {
  cinder::audio::SourceFileRef audio_file = cinder::audio::load(
      cinder::app::loadAsset( "sound93.wav" ));

  jump_audio_ = cinder::audio::Voice::create(audio_file);
  jump_audio_->start();
}

void MyApp::keyDown(KeyEvent event) {
  if (event.getCode() == KeyEvent::KEY_SPACE){
    if (!is_game_over_ && !is_main_menu_state_) {
      score_++;
      bird_.Jump();
      PlayJumpAudio();
    }
  } else if (event.getCode() == KeyEvent::KEY_j) {
    is_game_over_ = true;
  } else if (event.getCode() == KeyEvent::KEY_p) {
    is_main_menu_state_ = false;
  } else if (event.getCode() == KeyEvent::KEY_TAB) {
    playing_state_num_frames_ = 0;
    score_ = 0;
    is_main_menu_state_ = true;
    is_game_over_ = false;
    bird_.ResetPosition();
  }
}


}  // namespace myapp
