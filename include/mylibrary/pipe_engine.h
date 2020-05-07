#ifndef FINALPROJECT_PIPE_ENGINE_H
#define FINALPROJECT_PIPE_ENGINE_H

#include <vector>
#include "pipe.h"

namespace flappybird {

class Pipe_Engine {
 public:
  /**
   * Calls each pipe and updates each of their positions and makes them move
   * left
   */
  void UpdatePipesPosition();

  /**
   * Calls each pipe and draws them
   */
  void DrawPipes();

  /**
   * Adds pipes to list of pipes that are in game
   * @param num_pipes Number of pipes that are added
   */
  void AddPipes(int num_pipes);

  /**
   * @return Returns list of pipes
   */
  std::list<flappybird::Pipe> GetPipes();
 private:
  /** List of pipes which represent all pipes in game */
  std::list<flappybird::Pipe> pipes_;

  /** Starting X position of each pipe */
  size_t x_position_ = cinder::app::getWindowWidth();

  /** Starting Y position of each pipe */
  size_t y_position_ = 0;

  /** Distance between each pipe */
  const size_t kDistanceBetweenPipes_ = 350;
};
}
#endif  // FINALPROJECT_PIPE_ENGINE_H
