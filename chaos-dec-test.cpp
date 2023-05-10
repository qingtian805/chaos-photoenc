#include <opencv2/opencv.hpp>
#include <chaos-ranenc.h>
#include <chaos-arnold.h>
#include <chaos-rng.h>
#include <iostream>

using namespace cv;
using namespace chaos;
int main(void)
{
    Mat image, out;
    chaos_rng rng = chaos_rng(3.99, 0.25);

    image = imread("/home/kevin/git-chaos-cpp/teste.png");
    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }

    out = Mat::zeros(image.rows, image.cols, CV_8UC3);

    if(out.empty()){
        printf("Not enough memory \n");
        return -1;
    }

    chaos::chaos_ranenc::rand_enc(image, rng);

    chaos::chaos_arnold::rarnold_n(image, out, 3);

    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", out);
    waitKey(0);

    imwrite("/home/kevin/git-chaos-cpp/testd.png", out);

    return 0;
}