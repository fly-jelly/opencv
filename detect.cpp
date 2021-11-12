//
// Created by lenovo on 2021/11/11.
//
#include <iostream>
#include <opencv2/opencv.hpp>


using namespace cv;
using namespace std;
/**
 * 人脸检测以及人脸截取
 * @return
 */
int main(){
    int i = 0;
    VideoCapture capture(0);
    capture.set(CV_CAP_PROP_FRAME_WIDTH,960);
    capture.set(CV_CAP_PROP_FRAME_HEIGHT,540);
    if (!capture.isOpened()){
        return -1;
    }
    Mat frame;
    cv::CascadeClassifier classifier("../models/haarcascades/haarcascade_frontalface_alt.xml");

    vector<Rect> points;
    char name[50];
    while (true){
        capture >> frame;
        if (frame.empty()){
            continue;
        }
        classifier.detectMultiScale(frame,  points);
        Mat img;
        for (auto face : points) {
            rectangle(frame,face,(255,255,0));
            img = frame(face);
//            imshow("face",img);
            sprintf(name,"../face/%d.jpg",i);
            string tmp = name;
            Mat dst;
            resize(img,dst,Size(240,240));
            imwrite(tmp,dst);
            i+=1;
        }
        if (i == 20){
            break;
        }

        imshow("frame",frame);
        int key = waitKey(1);
        if (key == 'q'){
            break;
        }
    }
    return 0;

}

