#include <cinder/Vector.h>
#include <cinder/gl/draw.h>
#include <cinder/gl/gl.h>
#include <cmath>

#include "mylibrary/pipe.h"
#include "cinder/app/App.h"

namespace flappybird {

using namespace ci;
using namespace ci::app;

Pipe::Pipe() {}

Pipe::Pipe(cinder::vec2 point) {
  x_position_ = point.x;
  x2_position_ = point.x + 100;

 rand_bottom_pipe_height =  rand() % (kMaxBottomPipeHeight_
            - kMinBottomPipeHeight_ + 1) + kMinBottomPipeHeight_;

  rand_top_pipe_height_ = rand() % (kMaxTopPipeHeight_ -
      kMinTopPipeHeight_ + 1)+ kMinTopPipeHeight_;
}

void Pipe::Draw(){
  cinder::gl::color(0.30196, 0.90196, 0.443137); // light green

  cinder::gl::drawSolidRect(cinder::Rectf(x_position_,0,
      x2_position_, rand_top_pipe_height_));

  cinder::gl::drawSolidRect(cinder::Rectf(x_position_,
      cinder::app::getWindowHeight() - 350, x2_position_,
      cinder::app::getWindowHeight() - rand_bottom_pipe_height));
}

void Pipe::UpdatePosition(){
  if (x_position_ <= 0) {
    x_position_ = cinder::app::getWindowWidth() + 100;
    x2_position_ = cinder::app::getWindowWidth() + 200;
  } else {
    x_position_ -= velocity_;
    x2_position_ -= velocity_;
  }
}

int Pipe::GetRandTopPipeHeight() {
  return rand_top_pipe_height_;
}

int Pipe::GetRandBottomPipeHeight() {
  return cinder::app::getWindowHeight() - rand_bottom_pipe_height;
}

int Pipe::GetXPosition() {
  return x_position_;
}

int Pipe::GetX2Position() {
  return x2_position_;
}
}