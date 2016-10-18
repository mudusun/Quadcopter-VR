#ifndef SCENARIO_H
#define SCENARIO_H


#include "application/gmlibwrapper.h"

// qt
#include <QObject>

//class Quadcopter;

class Controller;
class Terrain;

namespace GMlib
{
template <typename T>
class PSphere;
template <typename T, int n>
class PSurfTexVisualizer;
}




class Scenario : public GMlibWrapper
{
  Q_OBJECT
public:
  using GMlibWrapper::GMlibWrapper;

  void    initializeScenario() override;
  void    cleanupScenario() override;

  void   drawTerrain();

  void   quadUp();
  void   quadDown();
  void   quadStart();
  void   quadStop();
  void   quadPitchForward();
  void   quadPitchBackward();
  void   quadRollLeft();
  void   quadRollRight();
  void   quadYawLeft();
  void   quadYawRight();

  void   quadUpReleased();
  void   quadDownReleased();
  void   quadPitchForwardReleased();
  void   quadPitchBackwardReleased();
  void   quadRollLeftReleased();
  void   quadRollRightReleased();
  void   quadYawLeftReleased();
  void   quadYawRightReleased();



private:
  Controller* contrl;
  Terrain* floor_;
  std::shared_ptr<GMlib::Scene>   _scene;


};

#endif // SCENARIO_H
