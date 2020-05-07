// Copyright (c) 2020 [Your Name]. All rights reserved.
#ifndef FINALPROJECT_BIRD_H_
#define FINALPROJECT_BIRD_H_

#include "cinder/Rand.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/Batch.h"
#include "cinder/gl/Fbo.h"
#include "cinder/gl/GlslProg.h"
#include "cinder/gl/VboMesh.h"
#include "cinder/gl/gl.h"

namespace mylibrary { // --> rename

class Bird {
 public:
  void Draw() const;
  void Jump();
  void UpdatePositionGravity();
  int GetXPosition();
  int GetYPosition();
  void ResetPosition();
 private:
  const float kBirdSize_ = 30;
  size_t x_position_ = cinder::app::getWindowCenter().x / 4;
  size_t y_position_ = cinder::app::getWindowCenter().y;
  double velocity_ = 0;
  double acceleration_ = 9.8;
  double time_ = 0;
  double elapsed_time_per_frame_ = 0.02;

  double jump_velocity = 80;

};
}
#endif // FINALPROJECT_BIRD_H_
