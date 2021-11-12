#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
using namespace cv;
using namespace std;
int main() {

//    Mat img = imread("E:\\人脸识别\\jm切图1117\\标记图.png");
//    Mat img = imread("C:\\Users\\lenovo\\Desktop\\lingan_logo.png");
//    imshow("show",img);
//    std::cout << "Hello, World!" << std::endl;

    VideoCapture capture(0);
    if (!capture.isOpened()) {
        std::cout << "open camera error!" << std::endl;
        return -1;
    }

    Mat gray,frame,dst,dilat,morphlogy;
//    Mat kernel = getStructuringElement(MORPH_RECT,Size(5,5),Point(-1,-1));
    Mat kernel = getStructuringElement(MORPH_CROSS,Size(5,5),Point(-1,-1));
    while (true){
        capture >> frame;
        if (frame.empty()){
            std::cout << "the frame is empty !" << std::endl;
            continue;
        }
//        cvtColor(frame,gray,CV_BGR2GRAY);
        // 函数可以对输入图像用特定结构元素进行腐蚀操作，该结构元素确定腐蚀操作过程中的邻域的形状，各点像素值将被替换为对应邻域上的最小值
//        erode(frame, dst, kernel);
        // 函数可以对输入图像用特定结构元素进行膨胀操作，该结构元素确定膨胀操作过程中的邻域的形状，各点像素值将被替换为对应邻域上的最大值：
//        dilate(frame,dilat,kernel);
//        morphologyEx(frame,morphlogy,kernel);

//        rotate(gray,gray,ROTATE_90_CLOCKWISE);
//        medianBlur(gray,gray,5);
//        Sobel(gray,gray,5,-1,5);
        // 镜像处理 flipCode 1 左右镜像 , 0 上下镜像
        flip(frame,frame,1);
        medianBlur(frame,gray,7);
        Laplacian(gray,gray,CV_8U,5);
        const int EDGES_THRESHOLD = 90;
        threshold(gray, gray, EDGES_THRESHOLD, 255, THRESH_BINARY_INV);

        Size size = gray.size();

        Size reduceSize;
        reduceSize.width = size.width / 2;
        reduceSize.height = size.height / 2;
        Mat reduceImage = Mat(reduceSize, CV_8UC3);
        resize(gray, reduceImage, reduceSize);

        Mat tmp = Mat(reduceSize, CV_8UC3);
        int repetitions = 7;
        for (int i = 0; i < repetitions; i++){
            int kernelSize = 9;
            double sigmaColor = 9;
            double sigmaSpace = 7;
            bilateralFilter(reduceImage, tmp, kernelSize, sigmaColor, sigmaSpace);
            bilateralFilter(tmp, reduceImage, kernelSize, sigmaColor, sigmaSpace);
        }

        Mat magnifyImage;
        resize(reduceImage, magnifyImage, size);
//        Mat dst;
        dst.setTo(0);
        magnifyImage.copyTo(dst, frame);

        imshow("frame",frame);
        imshow("dst",dst);
        imshow("gray",gray);
//        imshow("kernel",dst);
//        imshow("dilate",dilat);
        int key = waitKey(1);
        if (key == 'q') {
            break;
        }

    }

    return 0;
}
