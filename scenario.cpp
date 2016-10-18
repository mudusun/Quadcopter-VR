#include "scenario.h"

#include "testtorus.h"
#include "body.h"
#include "quadcopter.h"
#include "controller.h"


//// hidmanager
//#include "hidmanager/defaulthidmanager.h"

// gmlib
#include <gmOpenglModule>
#include <gmSceneModule>
#include <gmParametricsModule>
#include <parametrics/gmpsphere>

// qt
#include <QQuickItem>



void Scenario::initializeScenario() {

  // Insert a light
  GMlib::Point<GLfloat,3> init_light_pos( 2.0, 4.0, 10 );
  GMlib::PointLight *light = new GMlib::PointLight(  GMlib::GMcolor::White, GMlib::GMcolor::White,
                                                     GMlib::GMcolor::White, init_light_pos );
  light->setAttenuation(0.8, 0.002, 0.0008);
  scene()->insertLight( light, false );

  // Insert Sun
  scene()->insertSun();

  // Default camera parameters
  int init_viewport_size = 600;
  GMlib::Point<float,3> init_cam_pos(  0.0f, 0.0f, 0.0f );
  GMlib::Vector<float,3> init_cam_dir( 0.0f, 1.0f, 0.0f );
  GMlib::Vector<float,3> init_cam_up(  0.0f, 0.0f, 1.0f );

  // Projection cam
  auto proj_rcpair = createRCPair("Projection");
  proj_rcpair.camera->set(init_cam_pos/*+GMlib::Point<float,3>(0.0f,0.1f,-0.1f)*/,init_cam_dir,init_cam_up+GMlib::Point<float,3>(0.0f,0.0f,1.1f));
  proj_rcpair.camera->setCuttingPlanes( 0.5f, 20000.0f );
  proj_rcpair.camera->rotateGlobal( GMlib::Angle(-45), GMlib::Vector<float,3>( 1.0f, 0.0f, 0.0f ) );
  proj_rcpair.camera->translateGlobal( GMlib::Vector<float,3>( 0.0f, -3.0f, 3.0f ) );
  proj_rcpair.camera->enableCulling(false);
  scene()->insertCamera( proj_rcpair.camera.get() );
  proj_rcpair.renderer->reshape( GMlib::Vector<int,2>(init_viewport_size, init_viewport_size) );

  // Front cam
  auto front_rcpair = createRCPair("Front");
  front_rcpair.camera->set( init_cam_pos + GMlib::Vector<float,3>( 0.0f, -50.0f, 0.0f ), init_cam_dir, init_cam_up );
  front_rcpair.camera->setCuttingPlanes( 0.5f, 20000.0f );
  scene()->insertCamera( front_rcpair.camera.get() );
  front_rcpair.renderer->reshape( GMlib::Vector<int,2>(init_viewport_size, init_viewport_size) );

  // Side cam
  auto side_rcpair = createRCPair("Side");
  side_rcpair.camera->set( init_cam_pos + GMlib::Vector<float,3>( -50.0f, 0.0f, 0.0f ), GMlib::Vector<float,3>( 1.0f, 0.0f, 0.0f ), init_cam_up );
  side_rcpair.camera->setCuttingPlanes( 0.5f, 20000.0f );
  scene()->insertCamera( side_rcpair.camera.get() );
  side_rcpair.renderer->reshape( GMlib::Vector<int,2>(init_viewport_size, init_viewport_size) );

  // Top cam
  auto top_rcpair = createRCPair("Top");
  top_rcpair.camera->set( init_cam_pos + GMlib::Vector<float,3>( 0.0f, 0.0f, 50.0f ), -init_cam_up, init_cam_dir );
  top_rcpair.camera->setCuttingPlanes( 0.5f, 20000.0f );
  scene()->insertCamera( top_rcpair.camera.get() );
  top_rcpair.renderer->reshape( GMlib::Vector<int,2>(init_viewport_size, init_viewport_size) );

  // Quadcopter cam
    auto quad_rcpair = createRCPair("Quadcopter");
    quad_rcpair.camera->set(init_cam_pos,init_cam_dir,init_cam_up);
    quad_rcpair.camera->setCuttingPlanes( 0.5f, 600.0f );
    scene()->insertCamera( quad_rcpair.camera.get(), false);
    quad_rcpair.renderer->reshape( GMlib::Vector<int,2>(init_viewport_size, init_viewport_size) );





  // Surface visualizers
//  auto surface_visualizer = new GMlib::PSurfNormalsVisualizer<float,3>;

  // Surface
  //auto surface = new TestTorus;
  //surface->toggleDefaultVisualizer();
 // surface->insertVisualizer(surface_visualizer);
 // surface->replot(200,200,1,1);
  //scene()->insert(surface);

//  surface->test01();

// Add the controller in the scene
    contrl = new Controller(quad_rcpair.camera);
    scene()->insert(contrl);

}


void Scenario::cleanupScenario()
{

}

void Scenario::quadUp()
{
    contrl->moveUp();

}

void Scenario::quadDown()
{
    contrl->moveDown();

}

void Scenario::quadStart()
{
    contrl->startPropellers();
}

void Scenario::quadStop()
{
    contrl->stopPropellers();
}

void Scenario::quadPitchForward()
{
    contrl->pitchForward();
}

void Scenario::quadPitchBackward()
{
    contrl->pitchBackward();
}

void Scenario::quadRollLeft()
{
    contrl->rollLeft();
}

void Scenario::quadRollRight()
{
    contrl->rollRight();
}

void Scenario::quadYawLeft()
{
    contrl->yawLeft();
}

void Scenario::quadYawRight()
{
    contrl->yawRight();
}

void Scenario::quadUpReleased()
{
    contrl->moveUpReleased();
}

void Scenario::quadDownReleased()
{
    contrl->moveDownReleased();
}

void Scenario::quadPitchForwardReleased()
{
    contrl->pitchForwardReleased();
}

void Scenario::quadPitchBackwardReleased()
{
    contrl->pitchBackwardReleased();
}

void Scenario::quadRollLeftReleased()
{
    contrl->rollLeftReleased();
}

void Scenario::quadRollRightReleased()
{
    contrl->rollRightReleased();
}

void Scenario::quadYawLeftReleased()
{
    contrl->yawRightReleased();
}

void Scenario::quadYawRightReleased()
{
    contrl->yawLeftReleased();
}

