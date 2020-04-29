//
// Created by SamaahMachine on 4/25/2020.
//

#include "mylibrary/enginepipe.h"

namespace mylibrary {
void EnginePipe::DrawPipes() {
  for (list<Pipe>::iterator pipe = pipes.begin(); pipe != pipes.end(); ++pipe) {
    pipe->Draw();
  }
}

void EnginePipe::UpdatePipesPosition() {
  for(list<Pipe>::iterator pipe = pipes.begin(); pipe != pipes.end(); ++pipe){
    pipe->UpdatePosition();
  }
}

void EnginePipe::AddPipes(int num_pipes) {
  for (int i = 0; i < num_pipes; i ++) {
    pipes.push_back(Pipe(cinder::vec2(x_position_, y_position_)));
    x_position_ = x_position_ - 150;
    y_position_ = 0;
  }
}

}

