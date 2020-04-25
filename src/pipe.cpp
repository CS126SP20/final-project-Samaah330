//
// Created by SamaahMachine on 4/19/2020.
//

#include <cinder/Vector.h>
#include <cinder/gl/draw.h>
#include <cinder/gl/gl.h>

#include "mylibrary/pipe.h"
#include "cinder/app/App.h"
#include <random>
#include <algorithm>
#include <chrono>
#include <cmath>
#include <string>


namespace mylibrary {

void Pipe::DrawPipes() {

  cinder::gl::color(0,green_value_,0);

  cinder::gl::drawSolidRect(cinder::Rectf(x_position_,0, x2_position_, rand_num_));
  cinder::gl::drawSolidRect(cinder::Rectf(x_position_,cinder::app::getWindowHeight()
      , x2_position_, cinder::app::getWindowHeight() - rand_num_));

  x_position_ += space_between_pipes;
  x2_position_ += space_between_pipes;
  rand_num_ = rand() % (kMaxYPos_ - kMinYPos_ + 1) + kMinYPos_;

  cinder::gl::drawSolidRect(cinder::Rectf(x_position_,0, x2_position_,rand_num_));
  cinder::gl::drawSolidRect(cinder::Rectf(x_position_,cinder::app::getWindowHeight()
      , x2_position_, cinder::app::getWindowHeight() - rand_num_));
}
}