#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/Color.h>
#include <cinder/app/App.h>
#include <cinder/audio/Voice.h>
#include <mylibrary/bird.h>
#include <mylibrary/pipe.h>
#include <mylibrary/pipe_engine.h>

#include <random>

namespace flappybirdapp {

class FlappyBird : public cinder::app::App {
 public:
  /**
   * Default constructor.
   */
  FlappyBird();
  /**
   * Adds pipes at the beginning of game.
   */
  void setup() override;

  /**
   * Updates Position of pipes and Position of bird based on gravity.
   */
  void update() override;

  /**
   * Draws Main Menu Screen, Game Over Screen, or Playing State Screen
   */
  void draw() override;

  /**
   * Jumps if player presses space bar, closes main menu when player presses
   * p button, and resets game if user presses tab button
   */
  void keyDown(cinder::app::KeyEvent) override;

 private:
  /**
   * Draws game over screen with game over message, score, and instructions
   * on playing game again.
   */
  void DrawGameOver() const;

  /**
   * Draws main menu screen with moving pipes, game name, and instructions on
   * starting game.
   */
  void DrawMainMenu();

  /**
   * Draws moving pipes, bird, and score while player is playing game.
   */
  void DrawPlayingGameScreen();

  /**
   * Draws sky and ground.
   */
  void DrawBackground() const;

  /**
   * Stores score in json file.
   */
  void StoreScore() const;

  /**
   * Reads json file and prints Score each time score increments.
   */
  void PrintScore() const;

  /**
   * Checks if bird has collided with a pipe.
   * @return Returns true if bird has collided with a pipe, false otherwise.
   */
  bool DidBirdCollide();

  /** List of all pipes in game */
  std::list<flappybird::Pipe> pipes_;

  /** Holds bird functions */
  flappybird::Bird bird_;

  /** Holds pipe_engine_ functions */
  flappybird::Pipe_Engine pipe_engine_;

  /** Is true if the game is over, otherwise false */
  bool is_game_over_;

  /** Is true if user is at main menu screen, otherwise false */
  bool is_main_menu_state_;

  /** Number of frames user has played through during playing state of game */
  size_t playing_state_num_frames_;

  /** Keeps track of player score */
  size_t score_;

  /** Number of pipes added to game */
  const size_t kNumPipes_ = 5;

  /** Number of frames at the beginning of the game where player cannot die */
  const size_t kBeginningGameNumFrames_ = 150;

  /** Height of grass */
  const size_t kGrassHeight_ = 350;

  /** Font size of score */
  const size_t kScoreSize_ = 100;

  /** Font size of playing instructions */
  const size_t kPlayInstructionsSize_ = 80;

  /** Font Size of Game Name */
  const size_t kGameNameSize_ = 100;

  /** Font Size of Game Over Message */
  const size_t kGameOverSize = 200;

  /** Fonst Size of Play Again Message/Instructions */
  const size_t kPlayAgainSize = 70;

  /** Black Color */
  const cinder::Color kBlackColor = cinder::Color::black();

  /** White Color */
  const cinder::Color kColorWhite = cinder::Color::white();

  /** Name of game which is displayed on main menu screen */
  const std::string kGameName_ = "Flappy Bird";

  const std::string kScoreFileName_ = "score.json";

  /** Position of Score */
  const cinder::vec2 kScorePosition_ =
      cinder::vec2(cinder::app::getWindowWidth() - 170,
                   cinder::app::getWindowHeight() - 100);
};
}  // namespace flappybirdapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
