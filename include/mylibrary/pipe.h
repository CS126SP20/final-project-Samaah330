//
// Created by SamaahMachine on 4/19/2020.
//

#ifndef FINALPROJECT_FLAPPYBIRD_PIPE_H_
#define FINALPROJECT_FLAPPYBIRD_PIPE_H_
using namespace std;
#include "cinder/app/App.h"

namespace mylibrary {

class Pipe {
 public:
  void DrawPipes();
  void MovePipes();
 private:
  int x_position_ = - 100;
  int x2_position_ = -70;

};
}
#endif  // FINALPROJECT_PIPE_H
