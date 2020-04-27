// Copyright (c) 2020 [Your Name]. All rights reserved.
#ifndef FINALPROJECT_FLAPPYBIRD_BIRD_H_
#define FINALPROJECT_FLAPPYBIRD_BIRD_H_

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Fbo.h"
#include "cinder/gl/GlslProg.h"
#include "cinder/gl/Batch.h"
#include "cinder/Rand.h"
#include "cinder/gl/VboMesh.h"

namespace mylibrary { // --> rename

class Bird {
 public:
  void DrawBird();
  void Jump();
 private:
  const float kBirdSize_ = 30;

};


}  // namespace mylibrary


#endif // FINALPROJECT_MYLIBRARY_EXAMPLE_H_
