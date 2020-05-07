//
// Created by SamaahMachine on 4/25/2020.
//

#include <mylibrary/pipe_engine.h>

namespace mylibrary {
void Pipe_Engine::DrawPipes() {
  for (Pipe& pipe_itr : pipes_) {
    pipe_itr.Draw();
  }
}

void Pipe_Engine::UpdatePipesPosition() {
  for (Pipe& pipe_itr : pipes_) {
    pipe_itr.UpdatePosition();
  }
}

void Pipe_Engine::AddPipes(int num_pipes) {
  for (int i = 0; i < num_pipes; i ++) {
    pipes_.push_back(Pipe(cinder::vec2(x_position_, y_position_)));
    x_position_ = x_position_ - 350;
    y_position_ = 0;
  }
}

list<mylibrary::Pipe> Pipe_Engine::GetPipes() {
  return pipes_;
}

}

