//
// Created by lenovo on 2021/11/11.
//

#include "opencv2/opencv.hpp"
using namespace cv;

void magnifyGlass(Mat hahaFrame,Mat img) {
    //【1】凸透镜
    int width = hahaFrame.cols;
    int heigh = hahaFrame.rows;
    Point center(width / 2, heigh / 2);
    int R = sqrtf(width * width + heigh * heigh) / 4; //直接关系到放大的力度,与R成正比;
    for (int y = 0; y < heigh; y++)
    {
        uchar *img_p = img.ptr<uchar>(y);//定义一个指针，指向第y列，从而可以访问行数据。
        for (int x = 0; x < width; x++){
            int dis = norm(Point(x, y) - center);//获得当前点到中心点的距离
            if (dis < R)//设置变化区间
            {
                int newX = (x - center.x)*dis / R + center.x;
                int newY = (y - center.y)*dis / R + center.y;

                img_p[3 * x] = hahaFrame.at<uchar>(newY, newX * 3);
                img_p[3 * x + 1] = hahaFrame.at<uchar>(newY, newX * 3 + 1);
                img_p[3 * x + 2] = hahaFrame.at<uchar>(newY, newX * 3 + 2);

            }
        }
    }
}


void compressGlass(Mat hahaFrame,Mat img) {
    //【2】凹透镜
    int width = hahaFrame.cols;
    int heigh = hahaFrame.rows;
    Point center(width / 2, heigh / 2);
    for (int y = 0; y<heigh; y++){
        uchar *img_p = img.ptr<uchar>(y);
        for (int x = 0; x<width; x++){
            double theta = atan2((double)(y - center.y), (double)(x - center.x));
            int R = sqrtf(norm(Point(x, y) - center)) * 8; //直接关系到挤压的力度，与R成反比;
            int newX = center.x + (int)(R*cos(theta));
            int newY = center.y + (int)(R*sin(theta));

            if (newX<0)
                newX = 0;
            else if (newX >= width)
                newX = width - 1;

            if (newY<0)
                newY = 0;
            else if
                    (newY >= heigh) newY = heigh - 1;

            img_p[3 * x] = hahaFrame.at<uchar>(newY, newX * 3);
            img_p[3 * x + 1] = hahaFrame.at<uchar>(newY, newX * 3 + 1);
            img_p[3 * x + 2] = hahaFrame.at<uchar>(newY, newX * 3 + 2);
        }
    }
}


int main(){

    VideoCapture capture(0);
    if (!capture.isOpened()) {
        return -1;
    }
    Mat frame,show,compress;
    while (true){
        capture >> frame;
        if (frame.empty()){
            continue;
        }
        frame.copyTo(show);
        magnifyGlass(frame,show);

        frame.copyTo(compress);
        compressGlass(frame,compress);
        imshow("show",show);
        imshow("compress",compress);

        int key = waitKey(1);
        if (key == 'q'){
            break;
        }
    }

    return 0;
}

