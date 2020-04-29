//
// Created by SamaahMachine on 4/19/2020.
//

#ifndef FINALPROJECT_FLAPPYBIRD_PIPE_H_
#define FINALPROJECT_FLAPPYBIRD_PIPE_H_
using namespace std;
#include <random>

#include "cinder/app/App.h"

namespace mylibrary {

class Pipe {
 public:
  void UpdatePosition();
  void Draw();
  Pipe ();
  Pipe (cinder::vec2 point);
 private:
  const size_t velocity_ = 2;
  size_t x_position_ = 200;
  size_t x2_position_ = 230;
  const size_t kMaxBottomPipeHeight_ = 350;
  const size_t kMinBottomPipeHeight_ = 235;
  const size_t kMaxTopPipeHeight_ = 300;
  const size_t kMinTopPipeHeight_ = 150;
  size_t rand_bottom_pipe_height = rand() % (kMaxBottomPipeHeight_
      - kMinBottomPipeHeight_ + 1) + kMinBottomPipeHeight_;

  size_t rand_top_pipe_height_ = rand() % (kMaxTopPipeHeight_
      - kMinTopPipeHeight_ + 1) + kMinTopPipeHeight_;
  const size_t green_value_ = 200;

};
}
#endif  // FINALPROJECT_PIPE_H
