// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <cinder/app/App.h>


#include <cinder/Font.h>
#include <cinder/Text.h>
#include <cinder/Vector.h>
#include <cinder/gl/draw.h>
#include <cinder/gl/gl.h>
#include <string>


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

void MyApp::setup() {
}

void MyApp::update() { }

void MyApp::draw() {
  bird_.DrawBird();
  pipe_.DrawPipes();
}

void MyApp::SetUpFlyingAudio() {
  cinder::audio::SourceFileRef audioFile = cinder::audio::load(
      cinder::app::loadAsset( "sound93.wav" ));
  flying_audio = cinder::audio::Voice::create( audioFile );
  flying_audio->start();
}

template <typename C>
void PrintScore(const std::string& text, const C& color, const cinder::ivec2& size,
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

void MyApp::keyDown(KeyEvent event) {
  const cinder::vec2 center = getWindowCenter();
  const cinder::ivec2 size = {500, 50};
  const Color color = Color::white();

  if (event.getCode() == KeyEvent::KEY_j){
    score_++;
    std::string s = std::to_string(score_); // rename s to string_score
    PrintScore(s, color, size, center);
    bird_.Jump();
    SetUpFlyingAudio();
  }
}

}  // namespace myapp
