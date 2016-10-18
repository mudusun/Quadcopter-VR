#include "skybox.h"

Skybox::Skybox()
{
    GMlib::PSurfTexVisualizer<float,3>* northSkyboxTexture()
    {
        GMlib::PSurfTexVisualizer<float,3> *image = new GMlib::PSurfTexVisualizer<float,3>;

        QString texHandle = "../../gmlib_qmldemo/Skybox/atmosphere.png";

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


    GMlib::PSurfTexVisualizer<float,3>* southSkyboxTexture()
    {
        GMlib::PSurfTexVisualizer<float,3> *image = new GMlib::PSurfTexVisualizer<float,3>;

        QString texHandle = "../../gmlib_qmldemo/Skybox/atmosphere.png";

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
    GMlib::PSurfTexVisualizer<float,3>* Controller::westSkyboxTexture()
    {
        GMlib::PSurfTexVisualizer<float,3> *image = new GMlib::PSurfTexVisualizer<float,3>;

        QString texHandle = "../../gmlib_qmldemo/Skybox/atmosphere2.png";

        QImage img = QImage(texHandle);

        if(! QFile::exists(texHandle))

            std::cerr << "File " << texHandle.toStdString() <<" does not exists"<<std::endl;

        if( img.isNull() ) {
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

    GMlib::PSurfTexVisualizer<float,3>* Controller::eastSkyboxTexture()
    {
        GMlib::PSurfTexVisualizer<float,3> *image = new GMlib::PSurfTexVisualizer<float,3>;

        QString texHandle = "../../gmlib_qmldemo/Skybox/atmosphere2.png";

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
    GMlib::PSurfTexVisualizer<float,3>* Controller::topSkyboxTexture()
    {
        GMlib::PSurfTexVisualizer<float,3> *image = new GMlib::PSurfTexVisualizer<float,3>;

        QString texHandle = "../../gmlib_qmldemo/Skybox/top.png";

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

}
