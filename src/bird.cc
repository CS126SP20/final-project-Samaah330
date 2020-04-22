// Copyright (c) 2020 [Your Name]. All rights reserved.

#include <mylibrary/bird.h>
//#include <Cinder-Bullet3D/BulletContext.h>

//#include "Cinder-Bullet3D/RigidBody.h"
//#include "C:\Users\SamaahMachine\Documents\cinder_0.9.2_vc2015\blocks\Cinder-Bullet3D\src\Cinder-Bullet3D\BulletContext.h"
//#include "C:\Users\SamaahMachine\Documents\cinder_0.9.2_vc2015\blocks\Cinder-Bullet3D\src\Cinder-Bullet3D\RigidBody.h"
#include "cinder/gl/Batch.h"

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Fbo.h"
#include "cinder/gl/GlslProg.h"
#include "cinder/gl/Batch.h"
#include "cinder/Rand.h"
#include "cinder/gl/VboMesh.h"


//#include "C:\Users\SamaahMachine\Documents\cinder_0.9.2_vc2015\blocks\Cinder-Bullet3D\src\Cinder-Bullet3D\MotionState.h"
//#include "Cinder-Bullet3D/MotionState.h"
//#include "Cinder-Bullet3D/RigidBody.h"
#include <Cinder-Bullet3D/BulletContext.h>
#include <Cinder-Bullet3D/Common.h>

#include <BulletPhysics/btBulletDynamicsCommon.h>
#include <BulletPhysics/btBulletCollisionCommon.h>
//#include "BulletPhysics"
//#include "Cinder-Bullet3D"
//#include <Cinder-Bullet3D>


//#include "C:\Users\SamaahMachine\Documents\cinder_0.9.2_vc2015\blocks\Cinder-Bullet3D\samples\SphereGravity\include\Body.h"
using namespace bullet;

namespace mylibrary {

void Bird::Jump() {

  // move location of bird up
}

void Bird::draw() {

  bullet::ContextRef mContext;
  bullet::RigidBodyRef mSphere;
 // mContext = Context::create( Context::Format().drawDebug( true ).createDebugRenderer( true ) );
 // mSphere = RigidBody::create( RigidBody::Format().collisionShape( createSphereShape( 1 ) ).initialPosition( cinder::vec3( 0.5, 20, 0 ) ).mass( 1 ) );
   bullet::RigidBodyRef mPlane, mMultiSphere;
//  mPlane = RigidBody::create( RigidBody::Format().collisionShape( createStaticPlaneShape( cinder::vec3( 0, 1, 0 ), 0 ) ) );


  btBroadphaseInterface* broadphase = new btDbvtBroadphase();
  btDefaultCollisionConfiguration* collisionConfiguration = new btDefaultCollisionConfiguration();
  btCollisionDispatcher* dispatcher = new btCollisionDispatcher(collisionConfiguration);

  btSequentialImpulseConstraintSolver* solver = new btSequentialImpulseConstraintSolver;

  btDiscreteDynamicsWorld* dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher,broadphase,solver,collisionConfiguration);
dynamicsWorld->setGravity(btVector3(0,-10,0));

//  std::vector<ci::vec3> positions = {
//     cinder:: vec3( 1, 0, 0 ),
//     cinder::vec3( 0, 0, 0 ),
//     cinder:: vec3( -1, 0, 0 )
//  };
//  std::vector<btScalar> radii = {
//      1,
//      1,
//      1
//  };
//  mMultiSphere = RigidBody::create( RigidBody::Format().collisionShape( createMultiSphereShape( positions, radii ) ).initialPosition( cinder::vec3( -1.5, 15, 0 ) ).mass( 1 ) );
//  mContext->addRigidBody( mSphere );
  cinder::gl::color(225, 200, 0);

  cinder::gl::drawSolidCircle(cinder::vec2((cinder::app::getWindowCenter().x / 4),
                                           cinder::app::getWindowCenter().y), kBirdSize);

}
}  // namespace mylibrary
