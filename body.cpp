#include "body.h"

Body::Body()
{
    this->setSurroundingSphere(GMlib::Sphere<float,3>(100.0f));


    float scaler = 100.0f;

       auto bodypart = std::make_shared<GMlib::PSphere<float>>(3.0f/scaler,3.0f/scaler,3.0f/scaler);
       bodypart->toggleDefaultVisualizer();
       bodypart->translate(GMlib::Vector<float,3>(0.0f, 0.0f, -0.01f));
       bodypart->replot(200,200,1,1);
       bodypart->setMaterial(GMlib::GMmaterial::BlackRubber);
       quadBody.push_back(bodypart);
       this->insert(bodypart.get());

       auto bodypart1 = std::make_shared<GMlib::PCylinder<float>>(3.0f/scaler,3.0f/scaler,3.2f/scaler);
       bodypart1->toggleDefaultVisualizer();
       bodypart1->translate(GMlib::Vector<float,3>(0.0f, 0.0f, -0.002f));
       bodypart1->replot(200,200,1,1);
       bodypart1->setMaterial(GMlib::GMmaterial::PolishedRed);
       quadBody1.push_back(bodypart1);
       this->insert(bodypart1.get());

       auto bodycap = std::make_shared<GMlib::PCircularSurface<float> >(3.0f/scaler);
       bodycap ->toggleDefaultVisualizer();
       bodycap ->translate(GMlib::Vector<float,3>(0.0f, 0.0f, 0.014f));
       bodycap ->replot(200,200,1,1);
       bodycap ->setMaterial(GMlib::GMmaterial::PolishedRed);
       cap.push_back(bodycap);
       this->insert(bodycap.get());

}

Body::~Body()
{

}
