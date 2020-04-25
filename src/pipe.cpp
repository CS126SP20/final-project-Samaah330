//
// Created by SamaahMachine on 4/19/2020.
//

#include <cinder/Vector.h>
#include <cinder/gl/draw.h>
#include <cinder/gl/gl.h>

#include "mylibrary/pipe.h"
#include "cinder/app/App.h"

namespace mylibrary {

void Pipe::DrawPipes() {

  // find random number for y length
  cinder::gl::color(0,200,0);
//  int max = 300; // rename to make it more specific max_y_position , make const
//  int min = 0;
//  int rand_num = rand()%(max-min + 1) + min;
  //int SecondrandNum = rand()%(max-min + 1) + min;
  // ( , y position , , size of y length)

  cinder::gl::drawSolidRect(cinder::Rectf(x_position_,0, x2_position_, 250));
  cinder::gl::drawSolidRect(cinder::Rectf(x_position_,cinder::app::getWindowHeight()
      , x2_position_, cinder::app::getWindowHeight() - 250));

  x_position_ += 100;
  x2_position_ += 100;

  cinder::gl::drawSolidRect(cinder::Rectf(x_position_,0, x2_position_, 250));
  cinder::gl::drawSolidRect(cinder::Rectf(x_position_,cinder::app::getWindowHeight()
      , x2_position_, cinder::app::getWindowHeight() - 250));
}
}