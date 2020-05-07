// Copyright (c) 2020 [Your Name]. All rights reserved.

#include <mylibrary/bird.h>

#include "cinder/gl/gl.h"
#include "cinder/gl/GlslProg.h"
#include "cinder/Rand.h"


namespace mylibrary {

void Bird::Jump() {
  time_ = 0;

  y_position_ -= jump_velocity;
  x_position_ += 2;
}

void Bird::UpdatePositionGravity() {
  time_ += elapsed_time_per_frame_;
  velocity_ = acceleration_ * time_;
  y_position_ += velocity_;
}

void Bird::Draw() const {

  cinder::gl::color(1, .8, 0);

  cinder::gl::drawSolidCircle(cinder::vec2(x_position_, y_position_),
      kBirdSize_);

}

int Bird::GetYPosition() {
  std::cout << y_position_ << std::endl;
  return y_position_;
}

int Bird::GetXPosition() {
  return x_position_;
}

void Bird::ResetPosition() {
  x_position_ = cinder::app::getWindowCenter().x / 4;
  y_position_ = cinder::app::getWindowCenter().y;
  time_ = 0;
  velocity_ = 0;
}
}  // namespace mylibrary
