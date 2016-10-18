#include "controller.h"
#include "scenario.h"


Controller::Controller(std::shared_ptr<GMlib::Camera> cam)
{
    this->setSurroundingSphere(GMlib::Sphere<float,3>(100.0f));

   // quadcopter = new Quadcopter;
    quadcopter = std::make_shared<Quadcopter>();
    quadcopter->insert(cam.get());
    this->insert(quadcopter.get());

    drawTerrain();
    skybox();

}
Controller::~Controller()
{

}


void Controller::drawTerrain()
{
    /*
     *
       vector1            vector3
        |----------------|
        |----------------|
        |----------------|
        |----------------|
        |----------------|
    point----------------vector2


    */

        auto  plane = std::make_shared<GMlib::PPlane<float>>(GMlib::Point<float,3>(-2000.0f,-2000.0f,-1.0f),
                                                             GMlib::Vector<float,3>(0.0f,4000.0f,0.0f),
                                                             GMlib::Vector<float,3>(4000.0f,0.0f,0.0f));
        plane->toggleDefaultVisualizer();
        plane->translate(GMlib::Vector<float,3>(0.0f, 0.0f, 0.95f));
        plane->replot(200,200,1,1);
        plane->setMaterial(GMlib::GMmaterial::Emerald);
        plane_.push_back(plane);
        this->insert(plane.get());


}

void Controller::skybox()
{
          GMlib::PSurfTexVisualizer<float,3> *image = northSkyboxTexture();
          auto plane_north =  std::make_shared<GMlib::PPlane<float>>(GMlib::Point<float,3>(2000,-2000,0),GMlib::Vector<float,3>(0,0,3000),GMlib::Vector<float,3>(0,4000,0));
          plane_north->insertVisualizer(image);
          plane_north->replot(2,2,1,1);
          plane_north->translate(GMlib::Vector<float,3>(0.0,0.0,-500.0));
          plane_north->setMaterial(GMlib::GMmaterial::Silver);
          skybox_.push_back(plane_north);
          this->insert(plane_north.get());

          GMlib::PSurfTexVisualizer<float,3> *image2 = southSkyboxTexture();
          auto plane_south = std::make_shared<GMlib::PPlane<float>>(GMlib::Point<float,3>(-2000,-2000,0),GMlib::Vector<float,3>(0,0,3000),GMlib::Vector<float,3>(0,4000,0));
          plane_south->insertVisualizer(image2);
          plane_south->rotate(GMlib::Angle(180), GMlib::Vector<float,3>( 0.0f, 0.0f, 1.0f ));
          plane_south->translate(GMlib::Vector<float,3>(4000.0,0.0,-500.0));
          plane_south->replot(2,2,1,1);
          plane_south->setMaterial(GMlib::GMmaterial::Silver);
          skybox_.push_back(plane_south);
          this->insert(plane_south.get());

          GMlib::PSurfTexVisualizer<float,3> *image3 = westSkyboxTexture();
          auto plane_west =  std::make_shared<GMlib::PPlane<float>>(GMlib::Point<float,3>(-2000,-2000,0),GMlib::Vector<float,3>(0,0,3000),GMlib::Vector<float,3>(0,4000,0));
          plane_west->insertVisualizer(image3);
          plane_west->rotate(GMlib::Angle(90), GMlib::Vector<float,3>( 0.0f, 0.0f, 1.0f ));
          plane_west->translate(GMlib::Vector<float,3>(4000.0f,0.0f,-500.0f));
          plane_west->replot(2,2,1,1);
          plane_west->setMaterial(GMlib::GMmaterial::Silver);
          skybox_.push_back(plane_west);
          this->insert(plane_west.get());

          GMlib::PSurfTexVisualizer<float,3> *image4 = eastSkyboxTexture();
          auto plane_east =  std::make_shared<GMlib::PPlane<float>>(GMlib::Point<float,3>(-2000,-2000,0),GMlib::Vector<float,3>(0,0,3000),GMlib::Vector<float,3>(0,4000,0));
          plane_east->insertVisualizer(image4);
          plane_east->rotate(GMlib::Angle(270), GMlib::Vector<float,3>( 0.0f, 0.0f, 1.0f ));
          plane_east->translate(GMlib::Vector<float,3>(4000.0f,0.0f,-500.0f));
          plane_east->replot(2,2,1,1);
          plane_east->setMaterial(GMlib::GMmaterial::Silver);
          skybox_.push_back(plane_east);
          this->insert(plane_east.get());

          GMlib::PSurfTexVisualizer<float,3> *image5 = topSkyboxTexture();
          auto plane_top =  std::make_shared<GMlib::PPlane<float>>(GMlib::Point<float,3>(2000,-2000,0),GMlib::Vector<float,3>(4000,0,0),GMlib::Vector<float,3>(0,4000,0));
          plane_top->insertVisualizer(image5);
          plane_top->translate(GMlib::Vector<float,3>(-4000.0f,0.0f,3000.0f));
          plane_top->replot(2,2,1,1);
          plane_top->setMaterial(GMlib::GMmaterial::Silver);
          skybox_.push_back(plane_top);
          this->insert(plane_top.get());

}

GMlib::PSurfTexVisualizer<float, 3> *Controller::westSkyboxTexture()
{
    GMlib::PSurfTexVisualizer<float,3> *image = new GMlib::PSurfTexVisualizer<float,3>;

    QString texHandle = "C:/Users/hxu001/Documents/gmlib_qmldemo.git/skybox/skybox_west.jpg";

    QImage img = QImage(texHandle);

    if(! QFile::exists(texHandle))

        std::cerr << "File " << texHandle.toStdString() <<" does not exists"<<std::endl;

    if( img.isNull() )
    {
        std::cerr<<"Doesnt exists"<<std::endl;
    }

    assert(!img.isNull());
    img = img.convertToFormat(QImage::Format_RGB888);


    GMlib::GL::Texture westSkyboxTex;
    westSkyboxTex.create( GL_TEXTURE_2D );
    westSkyboxTex.texImage2D( 0, GL_RGB, img.width(), img.height(), 0, GL_RGB, GL_UNSIGNED_BYTE, img.bits() );
    westSkyboxTex.texParameteri( GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    westSkyboxTex.texParameteri( GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    westSkyboxTex.texParameterf( GL_TEXTURE_WRAP_S, GL_REPEAT);
    westSkyboxTex.texParameterf( GL_TEXTURE_WRAP_T, GL_REPEAT);

    image->setTexture(westSkyboxTex);
    return image;

}

GMlib::PSurfTexVisualizer<float, 3> *Controller::eastSkyboxTexture()
{
    GMlib::PSurfTexVisualizer<float,3> *image = new GMlib::PSurfTexVisualizer<float,3>;

    QString texHandle = "C:/Users/hxu001/Documents/gmlib_qmldemo.git/skybox/skybox_east.jpg";

    QImage img = QImage(texHandle);

    if(! QFile::exists(texHandle))

        std::cerr << "File " << texHandle.toStdString() <<" does not exists"<<std::endl;

    if( img.isNull() ) {
        std::cerr<<"Doesnt exists"<<std::endl;
    }

    assert(!img.isNull());
    img = img.convertToFormat(QImage::Format_RGB888);


    GMlib::GL::Texture eastSkyboxTex;
    eastSkyboxTex.create( GL_TEXTURE_2D );
    eastSkyboxTex.texImage2D( 0, GL_RGB, img.width(), img.height(), 0, GL_RGB, GL_UNSIGNED_BYTE, img.bits() );
    eastSkyboxTex.texParameteri( GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    eastSkyboxTex.texParameteri( GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    eastSkyboxTex.texParameterf( GL_TEXTURE_WRAP_S, GL_REPEAT);
    eastSkyboxTex.texParameterf( GL_TEXTURE_WRAP_T, GL_REPEAT);

    image->setTexture(eastSkyboxTex);
    return image;

}

GMlib::PSurfTexVisualizer<float, 3> *Controller::southSkyboxTexture()
{
    GMlib::PSurfTexVisualizer<float,3> *image = new GMlib::PSurfTexVisualizer<float,3>;

    QString texHandle = "C:/Users/hxu001/Documents/gmlib_qmldemo.git/skybox/skybox_south.jpg";

    QImage img = QImage(texHandle);

    if(! QFile::exists(texHandle))

        std::cerr << "File " << texHandle.toStdString() <<" does not exists"<<std::endl;

    if( img.isNull() ) {
        std::cerr<<"Doesnt exists"<<std::endl;
    }

    assert(!img.isNull());
    img = img.convertToFormat(QImage::Format_RGB888);


    GMlib::GL::Texture southSkyboxTex;
    southSkyboxTex.create( GL_TEXTURE_2D );
    southSkyboxTex.texImage2D( 0, GL_RGB, img.width(), img.height(), 0, GL_RGB, GL_UNSIGNED_BYTE, img.bits() );
    southSkyboxTex.texParameteri( GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    southSkyboxTex.texParameteri( GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    southSkyboxTex.texParameterf( GL_TEXTURE_WRAP_S, GL_REPEAT);
    southSkyboxTex.texParameterf( GL_TEXTURE_WRAP_T, GL_REPEAT);

    image->setTexture(southSkyboxTex);
    return image;

}

GMlib::PSurfTexVisualizer<float,3> *Controller::topSkyboxTexture()
{
    GMlib::PSurfTexVisualizer<float,3> *image = new GMlib::PSurfTexVisualizer<float,3>;

    QString texHandle = "C:/Users/hxu001/Documents/gmlib_qmldemo.git/skybox/skybox_up.jpg";

    QImage img = QImage(texHandle);

    if(! QFile::exists(texHandle))

        std::cerr << "File " << texHandle.toStdString() <<" does not exists"<<std::endl;

    if( img.isNull() ) {
        std::cerr<<"Doesnt exists"<<std::endl;
    }

    assert(!img.isNull());
    img = img.convertToFormat(QImage::Format_RGB888);


    GMlib::GL::Texture topSkyboxTex;
    topSkyboxTex.create( GL_TEXTURE_2D );
    topSkyboxTex.texImage2D( 0, GL_RGB, img.width(), img.height(), 0, GL_RGB, GL_UNSIGNED_BYTE, img.bits() );
    topSkyboxTex.texParameteri( GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    topSkyboxTex.texParameteri( GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    topSkyboxTex.texParameterf( GL_TEXTURE_WRAP_S, GL_REPEAT);
    topSkyboxTex.texParameterf( GL_TEXTURE_WRAP_T, GL_REPEAT);

    image->setTexture(topSkyboxTex);
    return image;

}

GMlib::PSurfTexVisualizer<float, 3> *Controller::northSkyboxTexture()
{
    GMlib::PSurfTexVisualizer<float,3> *image = new GMlib::PSurfTexVisualizer<float,3>;

    QString texHandle = "C:/Users/hxu001/Documents/gmlib_qmldemo.git/skybox/skybox_north.jpg";

    QImage img = QImage(texHandle);

    if(! QFile::exists(texHandle))

        std::cerr << "File " << texHandle.toStdString() <<" does not exists"<<std::endl;

    if( img.isNull() ) {
        std::cerr<<"Doesnt exists"<<std::endl;
    }

    assert(!img.isNull());
    img = img.convertToFormat(QImage::Format_RGB888);


    GMlib::GL::Texture northSkyboxTex;
    northSkyboxTex.create( GL_TEXTURE_2D );
    northSkyboxTex.texImage2D( 0, GL_RGB, img.width(), img.height(), 0, GL_RGB, GL_UNSIGNED_BYTE, img.bits() );
    northSkyboxTex.texParameteri( GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    northSkyboxTex.texParameteri( GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    northSkyboxTex.texParameterf( GL_TEXTURE_WRAP_S, GL_REPEAT);
    northSkyboxTex.texParameterf( GL_TEXTURE_WRAP_T, GL_REPEAT);

    image->setTexture(northSkyboxTex);
    return image;

}

void Controller::moveUp()
{
    quadcopter->goUp();
}

void Controller::moveDown()
{
    quadcopter->goDown();
}

void Controller::pitchForward()
{
    quadcopter->pitchF();
}

void Controller::pitchBackward()
{
    quadcopter->pitchBack();
}

void Controller::startPropellers()
{
    quadcopter->onPropellers();
}

void Controller::stopPropellers()
{
    quadcopter->offPropellers();
}

void Controller::rollLeft()
{
    quadcopter->rollR();
}

void Controller::rollRight()
{
    quadcopter->rollR();
}

void Controller::yawRight()
{
    quadcopter->yawR();
}

void Controller::yawLeft()
{
    quadcopter->yawL();
}

void Controller::moveUpReleased()
{
    quadcopter->goUpReleased();
}

void Controller::moveDownReleased()
{
    quadcopter->goDownReleased();
}

void Controller::pitchForwardReleased()
{
    quadcopter->pitchFrontReleased();
}

void Controller::pitchBackwardReleased()
{
    quadcopter->pitchBackReleased();
}

void Controller::rollLeftReleased()
{
    quadcopter->rollLReleased();
}

void Controller::rollRightReleased()
{
    quadcopter->rollRReleased();
}

void Controller::yawRightReleased()
{
    quadcopter->yawRReleased();
}

void Controller::yawLeftReleased()
{
    quadcopter->yawLReleased();
}



