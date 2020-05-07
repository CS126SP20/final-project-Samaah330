#ifndef FINALPROJECT_BIRD_H_
#define FINALPROJECT_BIRD_H_

#include <cinder/audio/Voice.h>

#include "cinder/Rand.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/Batch.h"
#include "cinder/gl/Fbo.h"
#include "cinder/gl/GlslProg.h"
#include "cinder/gl/VboMesh.h"
#include "cinder/gl/gl.h"

namespace flappybird {

class Bird {
 public:
  /**
   * Draws an orange circular bird.
   */
  void Draw() const;

  /**
   * Changes X and Y position of bird based on jump velocity to make bird jump.
   */
  void Jump();

  /**
   * Changes Y Position of bird based off acceleration of gravity.
   */
  void UpdatePositionGravity();

  /**
   * @return Returns current X position of bird.
   */
  int GetXPosition() const;

  /**
   * @return Returns current Y position of bird.
   */
  int GetYPosition() const;

  /**
   * Resets X and Y position of bird back to original positions.
   */
  void ResetPosition();

  /**
   * Plays Audio when bird jumps
   */
  void PlayJumpAudio();

 private:

  /** Radius of bird. */
  const float kBirdSize_ = 30;

  /** Starting X position of bird */
  size_t x_position_ = cinder::app::getWindowCenter().x / 4;

  /** Starting Y position of bird */
  size_t y_position_ = cinder::app::getWindowCenter().y;

  /* Velocity that changes Y Position of bird based off of gravity */
  double velocity_ = 0;

  /** Rate that the bird is falling at */
  const double kGravity_ = 9.8;

  /** Time that is used to calculate velocity using acceleration as well */
  double time_ = 0;

  /** Amount time is changed by per frame */
  const double kElapsedTimePerFrame_ = 0.02;

  /** Velocity that changes the Y position of bird when bird jumps */
  const double kJumpVelocity_ = 80;

  /** Holds audio which is played when bird jumps */
  cinder::audio::VoiceRef jump_audio_;
};
}
#endif // FINALPROJECT_BIRD_H_
