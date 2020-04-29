//
// Created by SamaahMachine on 4/19/2020.
//

#include "mylibrary/pipe.h"

#include <cinder/Vector.h>
#include <cinder/gl/draw.h>
#include <cinder/gl/gl.h>

#include <algorithm>
#include <chrono>
#include <cmath>
#include <random>
#include <string>

#include "cinder/app/App.h"
#include "mylibrary/enginepipe.h"

using namespace ci;
using namespace ci::app;
namespace mylibrary {

Pipe::Pipe() {}

Pipe::Pipe(cinder::vec2 point) {
  x_position_ = point.x;
  x2_position_ = point.x + 50;
}

void Pipe::Draw(){
  cinder::gl::color(0.30196, 0.90196, 0.443137);
  cinder::gl::drawSolidRect(cinder::Rectf(x_position_,0, x2_position_, rand_top_pipe_height_));

  cinder::gl::drawSolidRect(cinder::Rectf(x_position_,
      cinder::app::getWindowHeight() - 150, x2_position_,
      cinder::app::getWindowHeight() - rand_bottom_pipe_height));
}

void Pipe::UpdatePosition(){
  if (x_position_ <= 0) {
    x_position_ = cinder::app::getWindowWidth();
    x2_position_ = cinder::app::getWindowWidth() + 50;
  } else {
    x_position_ -= velocity_;
    x2_position_ -= velocity_;
  }
}
}