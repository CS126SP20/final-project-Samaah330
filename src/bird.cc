// Copyright (c) 2020 [Your Name]. All rights reserved.

#include <mylibrary/bird.h>

#include "cinder/app/App.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/GlslProg.h"
#include "cinder/Rand.h"

#include <nlohmann/json.hpp>

namespace mylibrary {

void Bird::Jump() {
  nlohmann::json::parse("asdfasdf");
}

void Bird::draw() {

  cinder::gl::color(225, 200, 0);

  cinder::gl::drawSolidCircle(cinder::vec2((cinder::app::
  getWindowCenter().x / 4),cinder::app::getWindowCenter().y), kBirdSize);

}
}  // namespace mylibrary
