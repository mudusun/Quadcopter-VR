#include "arms.h"

Arms::Arms()
{
    this->setSurroundingSphere(GMlib::Sphere<float,3>(100.0f));

    float scaler = 100.0f;


    auto motor1_ = std::make_shared<GMlib::PCylinder<float> > (0.4f/scaler,0.4f/scaler,0.5f/scaler);
    motor1_->toggleDefaultVisualizer();
    motor1_->translate(GMlib::Vector<float,3>(10.0f/scaler, 0.0f/scaler, 0.1f/scaler));
    motor1_->replot(200,200,1,1);
    motor1_->setMaterial(GMlib::GMmaterial::BlackRubber);
    topOnArm.push_back(motor1_);
    this->insert(motor1_.get());

    auto motor2_ = std::make_shared<GMlib::PCylinder<float> > (0.4f/scaler,0.4f/scaler,0.5f/scaler);
    motor2_->toggleDefaultVisualizer();
    motor2_->translate(GMlib::Vector<float,3>(0.0f/scaler, 10.0f/scaler, 0.1f/scaler));
    motor2_->replot(200,200,1,1);
    motor2_->setMaterial(GMlib::GMmaterial::BlackRubber);
    topOnArm.push_back(motor2_);
    this->insert(motor2_.get());

    auto motor3_ = std::make_shared<GMlib::PCylinder<float> > (0.4f/scaler,0.4f/scaler,0.5f/scaler);
    motor3_->toggleDefaultVisualizer();
    motor3_->translate(GMlib::Vector<float,3>(-10.0f/scaler, 0.0f/scaler, 0.1f/scaler));
    motor3_->replot(200,200,1,1);
    motor3_->setMaterial(GMlib::GMmaterial::BlackRubber);
    topOnArm.push_back(motor3_);
    this->insert(motor3_.get());

    auto motor4_ = std::make_shared<GMlib::PCylinder<float> > (0.4f/scaler,0.4f/scaler,0.5f/scaler);
    motor4_->toggleDefaultVisualizer();
    motor4_->translate(GMlib::Vector<float,3>(0.0f/scaler, -10.0f/scaler, 0.1f/scaler));
    motor4_->replot(200,200,1,1);
    motor4_->setMaterial(GMlib::GMmaterial::BlackRubber);
    topOnArm.push_back(motor4_);
    this->insert(motor4_.get());

    auto aroundMotor1_ = std:: make_shared<GMlib::PTorus<float> >(6.8f/scaler,0.5f/scaler,0.2/scaler );
    aroundMotor1_->toggleDefaultVisualizer();
    aroundMotor1_->translate(GMlib::Vector<float,3>(10.0f/scaler, 0.0f/scaler, 0.2f/scaler));
    aroundMotor1_->replot(200,200,1,1);
    aroundMotor1_->setMaterial(GMlib::GMmaterial::PolishedRed);
    torus.push_back(aroundMotor1_);
    this->insert(aroundMotor1_.get());

    auto aroundMotor2_ = std:: make_shared<GMlib::PTorus<float> >(6.8f/scaler,0.5f/scaler,0.2/scaler );
    aroundMotor2_->toggleDefaultVisualizer();
    aroundMotor2_->translate(GMlib::Vector<float,3>(0.0f/scaler, 10.0f/scaler, 0.2f/scaler));
    aroundMotor2_->replot(200,200,1,1);
    aroundMotor2_->setMaterial(GMlib::GMmaterial::PolishedRed);
    torus.push_back(aroundMotor2_);
    this->insert(aroundMotor2_.get());

    auto aroundMotor3_ = std:: make_shared<GMlib::PTorus<float> >(6.8f/scaler,0.5f/scaler,0.2/scaler );
    aroundMotor3_->toggleDefaultVisualizer();
    aroundMotor3_->translate(GMlib::Vector<float,3>(-10.0f/scaler, 0.0f/scaler, 0.2f/scaler));
    aroundMotor3_->replot(200,200,1,1);
    aroundMotor3_->setMaterial(GMlib::GMmaterial::PolishedRed);
    torus.push_back(aroundMotor3_);
    this->insert(aroundMotor3_.get());

    auto aroundMotor4_ = std:: make_shared<GMlib::PTorus<float> >(6.8f/scaler,0.5f/scaler,0.2/scaler );
    aroundMotor4_->toggleDefaultVisualizer();
    aroundMotor4_->translate(GMlib::Vector<float,3>(0.0f/scaler, -10.0f/scaler, 0.2f/scaler));
    aroundMotor4_->replot(200,200,1,1);
    aroundMotor4_->setMaterial(GMlib::GMmaterial::PolishedRed);
    torus.push_back(aroundMotor4_);
    this->insert(aroundMotor4_.get());



    auto motorTop1_ = std:: make_shared<GMlib::PSphere<float> > (0.4f/scaler,0.4f/scaler,0.4f/scaler);
    motorTop1_->toggleDefaultVisualizer();
    motorTop1_->translate(GMlib::Vector<float,3>(10.0f/scaler, 0.0f/scaler, 0.2f/scaler));
    motorTop1_->replot(200,200,1,1);
    motorTop1_->setMaterial(GMlib::GMmaterial::PolishedCopper);
    motorTop.push_back(motorTop1_);
    this->insert(motorTop1_.get());

    auto motorTop2_ = std:: make_shared<GMlib::PSphere<float> > (0.4f/scaler,0.4f/scaler,0.4f/scaler);
    motorTop2_->toggleDefaultVisualizer();
    motorTop2_->translate(GMlib::Vector<float,3>(0.0f/scaler, 10.0f/scaler, 0.2f/scaler));
    motorTop2_->replot(200,200,1,1);
    motorTop2_->setMaterial(GMlib::GMmaterial::PolishedCopper);
    motorTop.push_back(motorTop2_);
    this->insert(motorTop2_.get());

    auto motorTop3_ = std:: make_shared<GMlib::PSphere<float> > (0.4f/scaler,0.4f/scaler,0.4f/scaler);
    motorTop3_->toggleDefaultVisualizer();
    motorTop3_->translate(GMlib::Vector<float,3>(-10.0f/scaler, 0.0f/scaler, 0.2f/scaler));
    motorTop3_->replot(200,200,1,1);
    motorTop3_->setMaterial(GMlib::GMmaterial::PolishedCopper);
    motorTop.push_back(motorTop3_);
    this->insert(motorTop3_.get());

    auto motorTop4_ = std:: make_shared<GMlib::PSphere<float> > (0.4f/scaler,0.4f/scaler,0.4f/scaler);
    motorTop4_->toggleDefaultVisualizer();
    motorTop4_->translate(GMlib::Vector<float,3>(0.0f/scaler, -10.0f/scaler, 0.2f/scaler));
    motorTop4_->replot(200,200,1,1);
    motorTop4_->setMaterial(GMlib::GMmaterial::PolishedCopper);
    motorTop.push_back(motorTop4_);
    this->insert(motorTop4_.get());


    auto armsPartsFrontBack = std::make_shared<GMlib::PCylinder<float>>(0.2f/scaler,0.4f/scaler,20.0f/scaler);
    auto armsPartsLeftRight = std::make_shared<GMlib::PCylinder<float>>(0.4f/scaler,0.2f/scaler,20.0f/scaler);
    armsPartsFrontBack->toggleDefaultVisualizer();
    armsPartsLeftRight->toggleDefaultVisualizer();


    armsPartsFrontBack->rotate(GMlib::Angle(90), GMlib::Vector<float,3>( 0.0f, 0.0f, 1.0f ) );
    armsPartsFrontBack->rotate(GMlib::Angle(90), GMlib::Vector<float,3>( 0.0f, 1.0f, 0.0f) );
    armsPartsLeftRight->rotate(GMlib::Angle(90), GMlib::Vector<float,3>( 0.0f, 0.0f, 1.0f ) );
    armsPartsLeftRight->rotate(GMlib::Angle(90), GMlib::Vector<float,3>( 1.0f, 0.0f, 0.0f ) );

    armsPartsFrontBack->replot(200,200,1,1);
    armsPartsLeftRight->replot(200,200,1,1);

    armsPartsFrontBack->setMaterial(GMlib::GMmaterial::BlackRubber);
    armsPartsLeftRight->setMaterial(GMlib::GMmaterial::BlackRubber);

    quadArmsParts.push_back(armsPartsFrontBack);
    quadArmsParts.push_back(armsPartsLeftRight);

    this->insert(armsPartsFrontBack.get());
    this->insert(armsPartsLeftRight.get());

}

Arms::~Arms()
{

}

