// Copyright (c) 2020 [Your Name]. All rights reserved.

#include <mylibrary/bird.h>

#include "cinder/app/App.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/GlslProg.h"
#include "cinder/Rand.h"


namespace mylibrary {

void Bird::Jump() {
  time_ = 0;

  y_position -= jump_velocity;
  x_position += 2;
}

void Bird::UpdatePositionGravity() {
  time_ += elapsed_time_per_frame_;
  velocity_ = acceleration_ * time_;
  y_position += velocity_;
}

void Bird::DrawBird() {

  cinder::gl::color(225, 200, 0);

  cinder::gl::drawSolidCircle(cinder::vec2( x_position, y_position),
      kBirdSize_);

}
}  // namespace mylibrary
