#ifndef PROPELLER_H
#define PROPELLER_H
#include <scene/gmsceneobject>
#include <parametrics/gmpplane>
#include <memory>
#include <vector>


class Propeller : public GMlib::SceneObject
{
    GM_SCENEOBJECT(Propeller)
public:
    Propeller(int direction);
    Propeller();

    ~Propeller();



    void setVelocity(float newVelocity);
    void setSlowVelocity(float newVelocity);
    void startVelocity(float newVel);

    void speedUpPitch();
    void speedDownPitch();
    void resetPitch();

    void speedUpYaw();
    void speedDownYaw();
    void resetYaw();

    void speedUpRoll();
    void speedDownRoll();
    void resetRoll();

    void resetSpeed();

    float getAngularVelocity(double dt);

protected:
    void localSimulate(double dt);

private:
    std::vector<std::shared_ptr<GMlib::PPlane<float>>> propellerParts;

    int dir;
    float pitch = 0.0;
    float roll = 0.0;
    float yaw = 0.0;

    float velocity = 0.0f;
    float newVel = 0.0f;


};

#endif // PROPELLER_H
