#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void help()
{
    std::cout << "./EXEC image" << std::endl;
}

int main(int argc, char** argv)
{
    std::string img_path;
    if (argc == 2) {
        img_path = std::string(argv[1]);
    } else {
        img_path = "../data/cards.png";
    }
    // Load the image
    Mat src = imread(img_path);
    // Check if everything was fine
    if (!src.data)
        return -1;

    imshow("Source Image", src);

    // Test imag
    cv::Mat dst = cv::Mat::zeros(src.rows, src.cols, CV_8UC3);
    // scan imge
    for (int x = 0; x < src.rows; x++) {
        for (int y = 0; y < src.cols; y++) {
            // if (src.at<Vec3b>(x, y) == Vec3b(255, 255, 255)) {
            //     dst.at<Vec3b>(x, y)[0] = 255;
            //     dst.at<Vec3b>(x, y)[1] = 255;
            //     dst.at<Vec3b>(x, y)[2] = 255;
            // } else {
            dst.at<Vec3b>(x, y)[0] = src.at<Vec3b>(x, y)[0];
            dst.at<Vec3b>(x, y)[1] = src.at<Vec3b>(x, y)[1];
            dst.at<Vec3b>(x, y)[2] = src.at<Vec3b>(x, y)[2];
            // }
        }
    }

    imshow("Dst Image", dst);
    waitKey(0);
    return 0;
}
