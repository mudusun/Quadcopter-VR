#include "propeller.h"

Propeller::Propeller(int direction)
{

    dir = direction;
    this->setSurroundingSphere(GMlib::Sphere<float,3>(100.0f));
    float scaler = 100.0f;

    auto blade_ = std::make_shared<GMlib::PPlane<float>>(GMlib::Point<float,3>(-5.5f/scaler,-0.1f/scaler,0.5f/scaler),
                                                        GMlib::Vector<float,3>(11.0f/scaler,0.0f/scaler,0.0f/scaler),
                                                        GMlib::Vector<float,3>(0.0f/scaler,0.3f/scaler,0.0f/scaler));

    blade_->toggleDefaultVisualizer();
    blade_->replot(2,2,1,1);
    blade_->setMaterial(GMlib::GMmaterial::PolishedBronze);
    propellerParts.push_back(blade_);
    this->insert(blade_.get());




}


Propeller::~Propeller()
{

}



void Propeller::speedUpPitch()
{
    pitch = 0.1f;
}

void Propeller::speedDownPitch()
{
    pitch = -0.1f;
}

void Propeller::speedUpYaw()
{
    yaw = 0.1f;
}

void Propeller::speedDownYaw()
{
    yaw = -0.1f;
}

void Propeller::speedUpRoll()
{
    roll = 0.1f;
}

void Propeller::speedDownRoll()
{
    roll = -0.1f;
}

void Propeller::resetPitch()
{
    pitch = 0.0f;
}

void Propeller::resetRoll()
{
    roll = 0.0f;
}

void  Propeller::resetSpeed()
{
    velocity = 0.0f;
}

void Propeller::resetYaw()
{
    yaw = 0.0f;
}

void Propeller::setVelocity(float newVelocity)
{
    velocity += newVelocity;
}

void Propeller::startVelocity(float newVel)
{
    velocity = newVel;
}


void Propeller::setSlowVelocity(float newVelocity)
{
    if((velocity - newVelocity) >= 0)
    {
        velocity -= newVelocity;
    }
    else
        velocity = 0;
}


float Propeller::getAngularVelocity(double dt)
{
    return (velocity+ pitch + roll + yaw)/dt;
}

void Propeller::localSimulate(double dt)
{

    this->rotateGlobal(GMlib::Angle(velocity*dt*dir),GMlib::Vector<float,3>(0.0f,0.0f,1.0f));
}
