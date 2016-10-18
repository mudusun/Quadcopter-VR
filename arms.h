#ifndef ARMS_H
#define ARMS_H

// GMlib
#include <scene/gmsceneobject>
#include <parametrics/gmpcylinder>
#include <parametrics/gmpplane>
#include <parametrics/gmptorus>
//#include <parametrics/gmpcone>
#include <parametrics/gmpsphere>

// STL
#include <memory>
#include <vector>

class Arms : public GMlib::SceneObject
{
    GM_SCENEOBJECT(Arms)
public:
    Arms();
    ~Arms();


protected:


private:
    std::vector<std::shared_ptr<GMlib::PCylinder<float> >> quadArmsParts;
    std::vector<std::shared_ptr<GMlib::PCylinder<float> >> topOnArm;
    //std::vector<std::shared_ptr<GMlib::PSurf<float,3> >> armParts;
    std::vector<std::shared_ptr<GMlib::PTorus<float> >> torus;
    std::vector<std::shared_ptr<GMlib::PSphere<float> >> motorTop;

};

#endif // ARMS_H
