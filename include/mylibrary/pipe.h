#ifndef FINALPROJECT_FLAPPYBIRD_PIPE_H_
#define FINALPROJECT_FLAPPYBIRD_PIPE_H_

#include <random>
#include "bird.h"

namespace flappybird {

class Pipe {
 public:
  /**
   * Updates X Position of pipe based on velocity and moves pipe to the left.
   */
  void UpdatePosition();

  /**
   * Draws green pipe.
   */
  void Draw();

  /**
   * Default Constructor for pipe.
   */
  Pipe ();

  /**
   * Constructor for pipe which takes in a point and sets X and Y Positions of
   * pipe based on point.
   * @param point Hold X and Y position of pipes.
   */
  Pipe (cinder::vec2 point);

  /**
   * @return  Returns random height of top pipe.
   */
  int GetRandTopPipeHeight();

  /**
   * @return Returns random height of bottom pipe.
   */
  int GetRandBottomPipeHeight();

  /**
   * @return Returns X Position of both top and bottom Pipe.
   */
  int GetXPosition();

  /**
   * @return Returns second X Position of both top and bottom pipe, which
   * is the X position plus width of pipe.
   */
  int GetX2Position();

 private:
  /** Rate at which the top and bottom pipe are moving to the left at */
  const size_t velocity_ = 2;

  /** Starting X Position of top and bottom pipe */
  size_t x_position_ = 200;

  /** Starting second X position of both top and bottom pipe, which is the X
   * position plus width of pipe */
  size_t x2_position_ = 230;

  /** Max random height for bottom pipe */
  const size_t kMaxBottomPipeHeight_ = 950;

  /** Min random height for bottom pipe */
  const size_t kMinBottomPipeHeight_ = 650;

  /**  Max random height for top pipe */
  const size_t kMaxTopPipeHeight_ = 700;

  /** Min random height for top pipe */
  const size_t kMinTopPipeHeight_ = 150;

  /** Random height for bottom pipe */
  size_t rand_bottom_pipe_height;

  /** Random height for top pipe */
  size_t rand_top_pipe_height_;
};
}
#endif  // FINALPROJECT_PIPE_H
