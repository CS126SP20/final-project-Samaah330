#include <cinder/audio/Source.h>
#include <mylibrary/bird.h>

#include "cinder/Rand.h"
#include "cinder/gl/GlslProg.h"
#include "cinder/gl/gl.h"

namespace flappybird {

void Bird::Jump() {
  time_ = 0;

  y_position_ -= kJumpVelocity_;
  x_position_ += 2;
}

void Bird::UpdatePositionGravity() {
  time_ += kElapsedTimePerFrame_;
  velocity_ = kGravity_ * time_;
  y_position_ += velocity_;
}

void Bird::Draw() const {
  cinder::gl::color(1, .8, 0); // orange

  cinder::gl::drawSolidCircle(cinder::vec2(x_position_, y_position_),
      kBirdSize_);
}

void Bird::PlayJumpAudio() {
  cinder::audio::SourceFileRef audio_file = cinder::audio::load(
      cinder::app::loadAsset( "sound93.wav" ));

  jump_audio_ = cinder::audio::Voice::create(audio_file);
  jump_audio_->start();
}

int Bird::GetYPosition() const {
  return y_position_;
}

int Bird::GetXPosition() const{
  return x_position_;
}

void Bird::ResetPosition() {
  x_position_ = cinder::app::getWindowCenter().x / 4;
  y_position_ = cinder::app::getWindowCenter().y;
  time_ = 0;
  velocity_ = 0;
}
}  // namespace flappybird
