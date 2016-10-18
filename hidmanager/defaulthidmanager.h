#ifndef DEFAULTHIDMANAGER_H
#define DEFAULTHIDMANAGER_H

#include "standardhidmanager.h"


#include <queue>

// local
class GMlibWrapper;


class DefaultHidManager : public StandardHidManager {
  Q_OBJECT
public:
  explicit DefaultHidManager( QObject* parent = Q_NULLPTR );
  virtual ~DefaultHidManager();

  static const unsigned int   OGL_TRIGGER {8};

  void                        setupDefaultHidBindings();

  void                        init( GMlibWrapper& gmlib );

public slots:
  void                        triggerOGLActions();

protected:
  void                        triggerAction(const HidAction *action, const HidInputEvent::HidInputParams &params) override;

signals:
  void signToggleSimulation();
  void signOpenCloseHidHelp();

/***Quadcopter signals****/
  void signUp();
  void signDown();
  void signStart();
  void signStop();
  void signPitchForward();
  void signPitchBackward();
  void signRollLeft();
  void signRollRight();
  void signYawLeft();
  void signYawRight();

  void   signUpReleased();
  void   signDownReleased();
  void   signPitchForwardReleased();
  void   signPitchBackwardReleased();
  void   signRollLeftReleased();
  void   signRollRightReleased();
  void   signYawLeftReleased();
  void   signYawRightReleased();




private slots:
  virtual void                      heDeSelectAllObjects();
  virtual void                      heEdit();
  virtual void                      heLockTo( const HidInputEvent::HidInputParams& params );
  virtual void                      heMoveCamera( const HidInputEvent::HidInputParams& params );
  virtual void                      heMoveSelectedObjects( const HidInputEvent::HidInputParams& params );
  virtual void                      hePanHorizontal( const HidInputEvent::HidInputParams& params );
  virtual void                      hePanVertical( const HidInputEvent::HidInputParams& params );
  virtual void                      heReplotQuick( int factor );
  virtual void                      heReplotQuickHigh();
  virtual void                      heReplotQuickLow();
  virtual void                      heReplotQuickMedium();
  virtual void                      heRotateSelectedObjects( const HidInputEvent::HidInputParams& params );
  virtual void                      heScaleSelectedObjects( const HidInputEvent::HidInputParams& params );
  virtual void                      heSelectAllObjects();
  virtual void                      heSelectObject( const HidInputEvent::HidInputParams& params );
  virtual void                      heSelectObjects( const HidInputEvent::HidInputParams& params );
  virtual void                      heSelectObjectTree( GMlib::SceneObject* obj );
  virtual void                      heToggleObjectDisplayMode();
  virtual void                      heToggleSimulation();
  virtual void                      heToggleSelectAllObjects();

/***Quadcopter slots****/
  virtual void                      heUp();
  virtual void                      heDown();
  virtual void                      heStart();
  virtual void                      heStop();
  virtual void                      hePitchForward();
  virtual void                      hePitchBackward();
  virtual void                      heRollLeft();
  virtual void                      heRollRight();
  virtual void                      heYawLeft();
  virtual void                      heYawRight();

  virtual void                      heUpReleased();
  virtual void                      heDownReleased();
  virtual void                      hePitchForwardReleased();
  virtual void                      hePitchBackwardReleased();
  virtual void                      heRollLeftReleased();
  virtual void                      heRollRightReleased();
  virtual void                      heYawLeftReleased();
  virtual void                      heYawRightReleased();




//  virtual void                      heUnlockCamera();
  virtual void                      heZoom( const HidInputEvent::HidInputParams& params );

  virtual void                      heLeftMouseReleaseStuff();
  virtual void                      heOpenCloseHidHelp();

private:
  GMlib::Camera*                    findCamera( const QString& view_name ) const;
  float                             cameraSpeedScale( GMlib::Camera* cam ) const;
  GMlib::Scene*                     scene() const;
  GMlib::SceneObject*               findSceneObject(const QString& view_name, const GMlib::Point<int,2>& pos);

  GMlib::Point<int,2>               toGMlibViewPoint(const QString& view_name, const QPoint& pos);

  GMlibWrapper*                     _gmlib;

  std::queue<std::pair<const HidAction*,HidInputEvent::HidInputParams>>   _ogl_actions;


};

#endif // DEFAULTHIDMANAGER_H
