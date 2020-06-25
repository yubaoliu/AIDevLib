#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
std::string type2str(int type);
int main(int argc, char** argv)
{
    // construct Mat
    float fx = 535.4;
    float fy = 539.2;
    float cx = 320.1;
    float cy = 247.6;
    Mat K = (Mat_<double>(3, 3) << fx, 0, cx, 0, fy, cy, 0, 0, 1);
    std::cout << "Size of matrix: " << K.elemSize() << "bytes" << std::endl;
    // https://docs.opencv.org/2.4/modules/core/doc/basic_structures.html#mat-type
    // CV_64F ->  6
    std::cout << "Matrix data type: " << K.type() << std::endl;
    std::cout << "Type: " << type2str(K.type()) << std::endl;
    return 0;
}

// onedrive.live.com/?id=root&cid=5B866A3145DD7B1F
std::string type2str(int type)
{
    std::string r;

    uchar depth = type & CV_MAT_DEPTH_MASK;
    uchar chans = 1 + (type >> CV_CN_SHIFT);

    switch (depth) {
    case CV_8U:
        r = "8U";
        break;
    case CV_8S:
        r = "8S";
        break;
    case CV_16U:
        r = "16U";
        break;
    case CV_16S:
        r = "16S";
        break;
    case CV_32S:
        r = "32S";
        break;
    case CV_32F:
        r = "32F";
        break;
    case CV_64F:
        r = "64F";
        break;
    default:
        r = "User";
        break;
    }

    r += "C";
    r += (chans + '0');

    return r;
}
