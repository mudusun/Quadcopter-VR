#ifndef QUADCOPTER_H
#define QUADCOPTER_H

#include "body.h"
#include "arms.h"
#include "propeller.h"


//class Scenario;


class Quadcopter : public GMlib::SceneObject
{
    GM_SCENEOBJECT(Quadcopter)

public:
    Quadcopter(/*Scenario* scenario*/);
    ~Quadcopter();

    double computeForce(double dt);
  //  std::vector<std::shared_ptr<Propel>> getPropellers();

    void goUp();
    void goDown();
    void onPropellers();
    void offPropellers();
    void pitchF();
    void pitchBack();
    void rollR();
    void rollL();
    void yawL();
    void yawR();

    void goUpReleased();
    void goDownReleased();
    void pitchFrontReleased();
    void pitchBackReleased();
    void rollRReleased();
    void rollLReleased();
    void yawLReleased();
    void yawRReleased();



protected:

    void localSimulate(double dt);

private:
    //Scenario* scenario_;
    std::shared_ptr<Body> bodypart;
    std::shared_ptr<Arms> armpart;
    std::vector<std::shared_ptr<Propeller>> blade;

    std::shared_ptr<GMlib::Camera> cam_;

        const double mass = 1.25, Ct = 8.6e-6, cq_ = 1.8e-7;
        const double p_ = 0.0, q_ = 0.0, r_ = 0.0;
        double f_ = 0.0;
        double sum = 0.0;


        const  GMlib::Vector<float,3> gravity = GMlib::Vector<float,3>(0,0,-9.81);
        GMlib::Vector<double,3> omega;
        GMlib::Vector<double,3> omegaDot;
        GMlib::Vector<double,3> torque;

        GMlib::SqMatrix<double,3> omegaX;
        GMlib::SqMatrix<double,3> rMatrix;
        GMlib::SqMatrix<double,3> rDotMatrix;
        GMlib::SqMatrix<double,3> inertiaMatrix;
        GMlib::SqMatrix<double,3> inverseInertiaMatrix;

        GMlib::Vector<double,3> torqueMatrix(double dt);


        void calculateRMatrix();

        void calculateOmegaXMatrix(double dt);

};

#endif // QUADCOPTER_H
