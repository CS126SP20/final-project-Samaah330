//
// Created by SamaahMachine on 4/25/2020.
//

#ifndef FINALPROJECT_PIPE_ENGINE_H
#define FINALPROJECT_PIPE_ENGINE_H

#include <vector>

#include "pipe.h"

//using namespace std;

namespace mylibrary {

class Pipe_Engine {
 public:
  void UpdatePipesPosition();
  void DrawPipes();
  void AddPipes(int num_pipes);
  list<mylibrary::Pipe> GetPipes();
 private:
  list<mylibrary::Pipe> pipes_;
  size_t x_position_ = cinder::app::getWindowWidth();
  size_t y_position_ = 0;
};
}
#endif  // FINALPROJECT_PIPE_ENGINE_H
