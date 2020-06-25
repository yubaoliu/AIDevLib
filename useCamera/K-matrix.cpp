#include <iostream>

int main()
{
    // Camera parameters, TUM fr3 dataset
    float fx = 535.4;
    float fy = 539.2;
    float cx = 320.1;
    float cy = 247.6;
    // Construct K matrix
    Mat K = (Mat_<double>(3, 3) << fx, 0, cx, 0, fy, cy, 0, 0, 1);
}
