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
const char kNormalFont[] = "Arial";
const char kBoldFont[] = "Arial Bold";
const char kDifferentFont[] = "Papyrus";
#endif

using cinder::app::KeyEvent;

MyApp::MyApp() { }

template <typename C>
void PrintText(const std::string& text, const C& color, const cinder::ivec2& size,
               const cinder::vec2& loc) {
  cinder::gl::color(color);

  auto box = cinder::TextBox()
      .alignment(cinder::TextBox::LEFT)
      .font(cinder::Font(kNormalFont, 60))
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
  engine_pipe_.AddPipes(5);
}

void MyApp::update() {
  engine_pipe_.UpdatePipesPosition();
  bird_.UpdatePositionGravity();
}

void MyApp::draw() {
  cinder::gl::clear(Color(0,0,0), true);
  if (is_game_over_) {
    DrawGameOver();
  } else {
    DrawBackground();
    bird_.DrawBird();
    engine_pipe_.DrawPipes();
  }
}

void MyApp::DrawGameOver() {
  cinder::gl::clear(Color(255, 0, 0), true);

  const cinder::vec2 center = getWindowCenter();
  const cinder::ivec2 size = {500, 50};
  const Color color = Color::black();

  PrintText("Game Over", color, size, center);

  StoreScore();
  PrintScore();
}

void MyApp::StoreScore() {
  nlohmann::json score_json;

  std::string string_score = std::to_string(score_);
  score_json["Score"] = string_score;

  std::ofstream o("C:\\Users\\SamaahMachine\\Documents\\"
                  "cinder_0.9.2_vc2015\\myProjects\\final-project-Samaah330\\"
                  "assets\\score.json");
  o << std::setw(4) << score_json << std::endl;
  o.close();
}

void MyApp::PrintScore() {

  std::ifstream in("C:\\Users\\SamaahMachine\\Documents\\"
                  "cinder_0.9.2_vc2015\\myProjects\\final-project-Samaah330\\"
                  "assets\\score.json");

  nlohmann::json file = nlohmann::json::parse(in);

  string score = file.at("Score");

  const cinder::vec2 center = cinder::vec2(getWindowCenter().x,
      getWindowCenter().y + 50);
  const cinder::ivec2 size = {500, 50};
  const Color color = Color::black();

  PrintText("Score: " + score, color, size, center);
}

void MyApp::DrawBackground() {
  cinder::gl::clear(Color(0.4, 0.69804, 1));

  cinder::gl::color(0.125, 0.3176, 0.1843);
  cinder::gl::drawSolidRect(Rectf(0, cinder::app::getWindowHeight()
  - 150, cinder::app::getWindowWidth(), cinder::app::getWindowHeight()));
}

void MyApp::PlayFlyingAudio() {
  cinder::audio::SourceFileRef audioFile = cinder::audio::load(
      cinder::app::loadAsset( "sound93.wav" ));
  flying_audio_ = cinder::audio::Voice::create( audioFile );
  flying_audio_->start();
}


void MyApp::keyDown(KeyEvent event) {
  if (event.getCode() == KeyEvent::KEY_SPACE){
    if (!is_game_over_) {
      score_++;
      bird_.Jump();
      PlayFlyingAudio();
    }
  } else if (event.getCode() == KeyEvent::KEY_j) {
    is_game_over_ = true;
  }
}


}  // namespace myapp
