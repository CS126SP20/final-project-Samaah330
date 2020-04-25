//
// Created by SamaahMachine on 4/19/2020.
//

#ifndef FINALPROJECT_FLAPPYBIRD_PIPE_H_
#define FINALPROJECT_FLAPPYBIRD_PIPE_H_
using namespace std;
#include "cinder/app/App.h"
#include <random>

namespace mylibrary {

class Pipe {
 public:
  void DrawPipes();
  void MovePipes();
 private:
  size_t x_position_ = - 100;
  size_t x2_position_ = -70;
  size_t kMaxYPos_ = 300;
  size_t kMinYPos_ = 50;
  size_t rand_num_ = rand() % (kMaxYPos_ - kMinYPos_ + 1) + kMinYPos_;
  size_t space_between_pipes = 200;
  size_t green_value_ = 200;

};
}
#endif  // FINALPROJECT_PIPE_H
