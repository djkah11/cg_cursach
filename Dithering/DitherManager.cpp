#include "DitherManager.h"
#include <iostream>


int DitherManager::Dither(DitherManager::kind_dither kindDither)
{
    switch (kindDither) {
    case white_noise: {
       return whiteNoiseDithering.Dither(image1, image2);
    }
    case blue_noise: {
        return blueNoiseDithering.Dither(image1, image2);
    }
    case violet_noise: {
       return violetNoiseDithering.Dither(image1, image2);
    }
    case pink_noise: {
       return pinkNoiseDithering.Dither(image1, image2);

    }
    case brown_noise: {
       return brownNoiseDithering.Dither(image1, image2);
    }
    case floyd_sd: {
       return floydSDDithering.Dither(image1,image2);
    }
    case false_floyd_sd: {
       return falseFloydSDDithering.Dither(image1,image2);
    }
    case jjn:{
       return jjnDithering.Dither(image1,image2);

    }
    case yliluoma1:{
       return yliluoma1Dithering.Dither(image1, image2);
    }

    default:
       return whiteNoiseDithering.Dither(image1, image2);
    };



}

int DitherManager::Benchmark(DitherManager::kind_dither kindDither)
{ switch (kindDither) {
    case white_noise: {
       return whiteNoiseDithering.Dither(image1);
        break;
    }
    case blue_noise: {
        return blueNoiseDithering.Dither(image1, image2);
    }
    case violet_noise: {
        return violetNoiseDithering.Dither(image1, image2);

    }
    case pink_noise: {
         return pinkNoiseDithering.Dither(image1, image2);

    }
    case brown_noise: {
        return brownNoiseDithering.Dither(image1);

    }
    case floyd_sd: {
        return floydSDDithering.Dither(image1);

    }
    case false_floyd_sd: {
        return falseFloydSDDithering.Dither(image1);

    }
    case jjn:{
        return jjnDithering.Dither(image1);

    }
    case yliluoma1:{
        return yliluoma1Dithering.Dither(image1);

    }

    default:
        return whiteNoiseDithering.Dither(image1);
    };

}

void DitherManager::initImages(std::shared_ptr<QImage> &_image1, std::shared_ptr<QImage> &_image2)
{
    image1 = _image1;
    if(!_image1.get())
        std::cout<<"image1 is null in initImages"<<std::endl;
    if(!_image2.get())
        std::cout<<"image2 is null in initImages"<<std::endl;
    image2 = _image2;
}

QString DitherManager::getImageName(DitherManager::kind_dither kindDither, bool isGIF)
{
    switch (kindDither) {
    case white_noise: {
        return (static_cast<QString>("white_noise_dith."+static_cast<QString>(isGIF?"gif":"bmp")));
    }
    case brown_noise: {
        return (static_cast<QString>("brown_noise_dit.")+static_cast<QString>(isGIF?"gif":"bmp"));
    }
    case pink_noise: {
        return (static_cast<QString>("pink_noise_dith.")+static_cast<QString>(isGIF?"gif":"bmp"));
    }
    case violet_noise: {
        return (static_cast<QString>("violet_noise_dith.")+static_cast<QString>(isGIF?"gif":"bmp"));
    }
    case blue_noise: {
        return (static_cast<QString>("blue_noise_dith.")+static_cast<QString>(isGIF?"gif":"bmp"));
    }
    case floyd_sd: {
        return (static_cast<QString>("floydsd_noise_dith.")+static_cast<QString>(isGIF?"gif":"bmp"));
    }
    case false_floyd_sd: {
        return (static_cast<QString>("false_floydsd_noise_dith.")+static_cast<QString>(isGIF?"gif":"bmp"));
    }
    case jjn: {
        return (static_cast<QString>("jjn_noise_dith.")+static_cast<QString>(isGIF?"gif":"bmp"));
    }
    case yliluoma1: {
        return (static_cast<QString>("yliluoma1_noise_dith.")+static_cast<QString>(isGIF?"gif":"bmp"));
    }
    default:
        return (static_cast<QString>("smth.")+static_cast<QString>(isGIF?"gif":"bmp"));
    }
}

std::shared_ptr<QImage> &DitherManager::getImage()
{
    return image2;
}


