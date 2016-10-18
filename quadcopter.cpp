#include "quadcopter.h"
#include "scenario.h"

/* http://dronebly.com/5-best-quadcopters-with-camera-you-have-to-see  UDI U818A RC Quadcopter */

Quadcopter::Quadcopter(/*Scenario* scenario*/)
{
    this->setSurroundingSphere(GMlib::Sphere<float,3>(100.0f));


    float scaler = 100.0f;


    bodypart = std::make_shared<Body>();
    armpart = std::make_shared<Arms>();


    auto blade1 = std::make_shared<Propeller>(1);
    blade1->translate(GMlib::Vector<float,3>(10.0f/scaler, 0.0f/scaler, 0.0f/scaler));
    blade.push_back(blade1);
    this->insert(blade1.get());

    auto blade2 = std::make_shared<Propeller>(-1);
    blade2->translate(GMlib::Vector<float,3>(0.0f/scaler, 10.0f/scaler, 0.0f/scaler));
    blade.push_back(blade2);
    this->insert(blade2.get());

    auto blade3 = std::make_shared<Propeller>(1);
    blade3->translate(GMlib::Vector<float,3>(-10.0f/scaler, 0.0f/scaler, 0.0f/scaler));
    blade.push_back(blade3);
    this->insert(blade3.get());

    auto blade4 = std::make_shared<Propeller>(-1);
    blade4->translate(GMlib::Vector<float,3>(0.0f/scaler, -10.0f/scaler, 0.0f/scaler));
    blade.push_back(blade4);
    this->insert(blade4.get());

    this->insert(armpart.get());
    this->insert(bodypart.get());

    //Physics
    //rotation matrix initialization
       rMatrix = GMlib::SqMatrix<double,3> ();
       rMatrix[0][0] = 1;
       rMatrix[0][1] = 0;
       rMatrix[0][2] = 0;

       rMatrix[1][0] = 0;
       rMatrix[1][1] = 1;
       rMatrix[1][2] = 0;

       rMatrix[2][0] = 0;
       rMatrix[2][1] = 0;
       rMatrix[2][2] = 1;

       //rotation dot matrix initialization
       rDotMatrix = GMlib::SqMatrix<double,3> ();
       rDotMatrix[0][0] = 0;
       rDotMatrix[0][1] = 0;
       rDotMatrix[0][2] = 0;

       rDotMatrix[1][0] = 0;
       rDotMatrix[1][1] = 0;
       rDotMatrix[1][2] = 0;

       rDotMatrix[2][0] = 0;
       rDotMatrix[2][1] = 0;
       rDotMatrix[2][2] = 0;

       //inertia matrix and inverse inertia matrix initialization
       inertiaMatrix = GMlib::SqMatrix<double,3> ();
       inertiaMatrix[0][0] = 0.047316;
       inertiaMatrix[0][1] = 0;
       inertiaMatrix[0][2] = 0;

       inertiaMatrix[1][0] = 0;
       inertiaMatrix[1][1] = 0.047316;
       inertiaMatrix[1][2] = 0;

       inertiaMatrix[2][0] = 0;
       inertiaMatrix[2][1] = 0;
       inertiaMatrix[2][2] = 0.0539632;

       inverseInertiaMatrix = inertiaMatrix;
       inverseInertiaMatrix.invert();


       //omega vector initialization
       omega = GMlib::Vector<double,3> ();
       omega[0] = p_;
       omega[1] = q_;
       omega[2] = r_;

       //omegaX matrix initialization
       omegaX = GMlib::SqMatrix<double,3> ();

       omegaX [0][0] = 0;
       omegaX [0][1] = 0;
       omegaX [0][2] = 0;

       omegaX [1][0] = 0;
       omegaX [1][1] = 0;
       omegaX [1][2] = 0;

       omegaX [2][0] = 0;
       omegaX [2][1] = 0;
       omegaX [2][2] = 0;

    }

Quadcopter::~Quadcopter()
{



}

double Quadcopter::computeForce(double dt)
{
    sum = 0;

    for(int i = 0; i < 4; i++)
    {
        sum += Ct*std::pow(blade[i]->getAngularVelocity(dt),2); // Calculate sum of the thrust
    }
    return sum;
}

void Quadcopter::goUp()
{
    for(unsigned int i=0; i< blade.size(); i++)
    {
        blade[i]-> setVelocity(0.1);
    }
}

void Quadcopter::goDown()
{
    for(unsigned int i=0; i< blade.size(); i++)
    {
        blade[i]-> setSlowVelocity(0.5);
    }
}

void Quadcopter::onPropellers()
{
    for(unsigned int i=0; i< blade.size(); i++)
    {
        blade[i]-> startVelocity(9);
    }
}

void Quadcopter::offPropellers()
{
    for(unsigned int i=0; i< blade.size(); i++)
    {
        blade[i]->startVelocity(0);
    }
}

void Quadcopter::pitchF()
{
    blade[0]-> speedDownPitch();
    blade[2]-> speedUpPitch();
}

void Quadcopter::pitchBack()
{
    blade[0]-> speedUpPitch();
    blade[2]-> speedDownPitch();
}

void Quadcopter::rollR()
{
    blade[1]->speedDownRoll();
    blade[3]->speedUpRoll();
}

void Quadcopter::rollL()
{
    blade[1]->speedUpRoll();
    blade[3]->speedDownRoll();
}

void Quadcopter::yawL()
{
    blade[0]->speedUpYaw();
    blade[1]->speedDownYaw();
    blade[2]->speedUpYaw();
    blade[3]->speedDownYaw();
}

void Quadcopter::yawR()
{
    blade[0]->speedDownYaw();
    blade[1]->speedUpYaw();
    blade[2]->speedDownYaw();
    blade[3]->speedUpYaw();
}



void Quadcopter::goUpReleased()
{
    for(unsigned int i=0; i< blade.size(); i++)
    {
        blade[i]-> setVelocity(0);
    }
}

void Quadcopter::goDownReleased()
{
    for(unsigned int i=0; i< blade.size(); i++)
    {
        blade[i]-> setSlowVelocity(0);
    }
}

void Quadcopter::pitchFrontReleased()
{
    blade[0]->resetPitch();
    blade[2]->resetPitch();
}

void Quadcopter::pitchBackReleased()
{
    blade[0]->resetPitch();
    blade[2]->resetPitch();
}

void Quadcopter::rollRReleased()
{
    blade[1]->resetRoll();
    blade[3]->resetRoll();
}

void Quadcopter::rollLReleased()
{
    blade[1]->resetRoll();
    blade[3]->resetRoll();
}

void Quadcopter::yawLReleased()
{
    blade[0]->resetYaw();
    blade[1]->resetYaw();
    blade[2]->resetYaw();
    blade[3]->resetYaw();
}

void Quadcopter::yawRReleased()
{
    blade[0]->resetYaw();
    blade[1]->resetYaw();
    blade[2]->resetYaw();
    blade[3]->resetYaw();
}



GMlib::Vector<double,3> Quadcopter::torqueMatrix(double dt)
{
float rotate1 = std::pow(blade[0]->getAngularVelocity(dt),2);
float rotate2 = std::pow(blade[1]->getAngularVelocity(dt),2);
float rotate3 = std::pow(blade[2]->getAngularVelocity(dt),2);
float rotate4= std::pow(blade[3]->getAngularVelocity(dt),2);

float torque1 = 0.2 * Ct * (rotate1-rotate3);
float torque2 = 0.2 * Ct * (rotate2 - rotate4);
float torque3 = cq_ * (-rotate1+rotate2-rotate3+rotate4);

torque = GMlib::Vector<double,3>(torque1,torque2,torque3);  //derived from Equation 8 in paper

return torque;
}

void Quadcopter::calculateOmegaXMatrix(double dt)
{
    omega  += omegaDot * dt;
    GMlib::Vector<double,3> iOmega = inertiaMatrix * omega;
    GMlib::Vector<double,3> crossProduct = omega^iOmega;
    omegaDot = inverseInertiaMatrix*(torqueMatrix(dt) - crossProduct);

    // OmegaX is a skew sematic matrix
    omegaX[0][0] = 0;
    omegaX[0][1] = -omega[2];
    omegaX[0][2] = omega[1];

    omegaX[1][0] = omega[2];
    omegaX[1][1] = 0;
    omegaX[1][2] = -omega[0];

    omegaX[2][0] = -omega[1];
    omegaX[2][1] = omega[0];
    omegaX[2][2] = 0;

    rDotMatrix = rMatrix * omegaX;
    rMatrix += rDotMatrix* dt;


}

void Quadcopter::localSimulate(double dt)
{
    // Global coordinates
    auto globalMatrix = getMatrixGlobal();
    globalMatrix.invert();
    double  resultantForce =  computeForce(dt);

    GMlib::Vector<float,3> acceleratedVelocity = globalMatrix * gravity +  (1/mass) * GMlib::Vector<float,3>(0,0,resultantForce);

    calculateOmegaXMatrix(dt);


    // Convert rMatrix from double to float
        GMlib::SqMatrix<float,3> convertR;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
               convertR[i][j] = rMatrix[i][j];
            }
        }

    set(getPos(),convertR[0],convertR[2]);

    auto pos = this->getPos();
    // Collision detection on the terrain
        if((getPos() + acceleratedVelocity * dt)[2] > 0 && (getPos() + acceleratedVelocity * dt)[2] < 3000)
        {
            translate(acceleratedVelocity * dt);
        }
        else
            set(GMlib::Point<float,3>(pos[0],pos[1],0), convertR[0], convertR[2]);
//        if((getPos() + acceleratedVelocity * dt)[1] > 0.5 && (getPos() + acceleratedVelocity * dt)[1] < 3000)
//        {
//            translate(acceleratedVelocity * dt);
//        }
//        if((getPos() + acceleratedVelocity * dt)[0] > 0.5 && (getPos() + acceleratedVelocity * dt)[0] < 3000)
//        {
//            translate(acceleratedVelocity * dt);
//        }
}
