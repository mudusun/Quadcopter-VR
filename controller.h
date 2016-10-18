#ifndef CONTROLLER_H
#define CONTROLLER_H


#include "quadcopter.h"




// GMlib
#include <parametrics/visualizers/gmpsurftexvisualizer.h>
#include <scene/gmsceneobject>

// STL
#include <memory>

// Qt
#include <QImage>
#include <QImageReader>
#include <QOpenGLTexture>
#include <QDirIterator>

class PSurfTexVisualizer;
class Scenario;

class Controller : public GMlib::SceneObject
{
    GM_SCENEOBJECT(Controller)

public:
    Controller(std::shared_ptr<GMlib::Camera> cam);
    ~Controller();

    void drawTerrain();
    void skybox();

    GMlib::PSurfTexVisualizer<float, 3> *northSkyboxTexture();
    GMlib::PSurfTexVisualizer<float, 3> *topSkyboxTexture();
    GMlib::PSurfTexVisualizer<float, 3> *southSkyboxTexture();
    GMlib::PSurfTexVisualizer<float, 3> *eastSkyboxTexture();
    GMlib::PSurfTexVisualizer<float, 3> *westSkyboxTexture();


    void moveUp();
    void moveDown();
    void pitchForward();
    void pitchBackward();
    void startPropellers();
    void stopPropellers();
    void rollLeft();
    void rollRight();
    void yawRight();
    void yawLeft();

    void moveUpReleased();
    void moveDownReleased();
    void pitchForwardReleased();
    void pitchBackwardReleased();
    void rollLeftReleased();
    void rollRightReleased();
    void yawRightReleased();
    void yawLeftReleased();



private:
    std::shared_ptr<Quadcopter> quadcopter;

    std::vector<std::shared_ptr<GMlib::PPlane<float>>> plane_;

    std::vector<std::shared_ptr<GMlib::PPlane <float>>> skybox_;
};

#endif // CONTROLLER_H
