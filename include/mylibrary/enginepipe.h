//
// Created by SamaahMachine on 4/25/2020.
//

#ifndef FINALPROJECT_ENGINEPIPE_H
#define FINALPROJECT_ENGINEPIPE_H

#include <vector>

#include "pipe.h"
using namespace std;

namespace mylibrary {

class EnginePipe {
 public:
  void UpdatePipes();
  void DrawPipes();
  void AddPipes(int num_pipes);
 private:
  list<mylibrary::Pipe> pipes;
  size_t x_position_ = cinder::app::getWindowWidth();
  size_t y_position_ = 0;

};
}
#endif  // FINALPROJECT_ENGINEPIPE_H
