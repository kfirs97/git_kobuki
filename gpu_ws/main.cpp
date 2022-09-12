#include <iostream>
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;

int main (int argc, char* argv[])
{
    Mat mat = imread("/home/kfir/Downloads/pic.jpg");
    cuda::GpuMat gpuMat;

    cout << "go threw original mat" << endl;
    for (int i = 0; i < mat.cols; i++) {
        for (int j = 0; j < mat.rows; j++) {
            Vec3b intensity = mat.at<Vec3b>(j, i);
            cout << intensity << ",";
        }
    }

    gpuMat.upload(mat);
    cout << "go threw gpu mat" << endl;
    time_t* gpu_start;
    time_t* gpu_end;
    time(gpu_start);
    for (int i = 0; i < mat.cols; i++) {
        for (int j = 0; j < mat.rows; j++) {
            Vec3b intensity = mat.at<Vec3b>(j, i);
            cout << intensity << ",";
        }
    }

    imshow("kfir", mat);
    waitKey(0);
    return 0;
}