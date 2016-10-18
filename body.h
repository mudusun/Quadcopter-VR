#ifndef BODY_H
#define BODY_H

// GMlib
#include <scene/gmsceneobject>
#include <parametrics/gmpsphere>
#include <parametrics/gmpcylinder>
#include <parametrics/gmpcircularsurface>

// STL
#include <memory>
#include <vector>

class Body:public GMlib::SceneObject
{
    GM_SCENEOBJECT(Body)
public:
    Body();
    ~Body();

private:
   std::vector< std::shared_ptr<GMlib::PSphere<float>>> quadBody;   //inside ball
   std::vector< std::shared_ptr<GMlib::PCylinder<float>>> quadBody1;    //cylinder around
   std::vector<std::shared_ptr<GMlib::PCircularSurface<float> >>  cap;   //up circular surface
};

#endif // BODY_H
