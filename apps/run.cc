// Copyright (c) 2020 [Your Name]. All rights reserved.

#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>

#include "my_app.h"


using cinder::app::App;
using cinder::app::RendererGl;


namespace flappybirdapp {

const int kSamples = 8;
const int kWidth = 1600;
const int kHeight = 1600;

void SetUp(App::Settings* settings) {
  settings->setWindowSize(kWidth, kHeight);
  settings->setTitle("Flappy Bird");
}

}  // namespace flappybirdapp


// This is a macro that runs the application.
CINDER_APP(flappybirdapp::FlappyBird,
           RendererGl(RendererGl::Options().msaa(flappybirdapp::kSamples)),
           flappybirdapp::SetUp)
