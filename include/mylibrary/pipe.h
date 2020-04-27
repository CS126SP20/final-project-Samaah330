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
  void Update();
  void Draw();
  Pipe ();
  Pipe (cinder::vec2 point);
 private:
  const size_t velocity_ = 1;
  size_t x_position_ = 200;
  size_t x2_position_ = 230;
  const size_t kMaxYPos_ = 300;
  const size_t kMinYPos_ = 50;
  size_t rand_pipe_height = rand() % (kMaxYPos_ - kMinYPos_ + 1) + kMinYPos_;
  const size_t green_value_ = 200;

};
}
#endif  // FINALPROJECT_PIPE_H
