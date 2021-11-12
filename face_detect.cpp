//
// Created by lenovo on 2021/11/11.
//
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/face.hpp>
using namespace std;
using namespace cv;
int main(){

    vector<Mat> images;
    vector<int> labels;

    Ptr<cv::face::EigenFaceRecognizer> model = cv::face::EigenFaceRecognizer::create();
    char name[20];

    Mat test = imread("D:\\workspace\\linux\\demo_1\\face\\0.bmp",0);
    imshow("png",test);
    for (int i = 0; i < 20; ++i) {
        sprintf(name,"face/%d.jpg\n",i);
        string str = name;
        printf("-> %s",str.c_str());

        Mat img = imread(str,CV_LOAD_IMAGE_GRAYSCALE);
        if (img.empty()){
            printf("error -> %s","empty");
        }else{
            images.push_back(img);
            imshow(name,img);
            labels.push_back(0);
        }
    }

    Mat testSample = images[1];
    model->train(images, labels);
    int idx = model->predict(testSample);
    string result_message = format("Predicted class = %d / Actual class = %d.", idx, 0);
    cout << result_message << endl;
    // Here is how to get the eigenvalues of this Eigenfaces model:
//    Mat eigenvalues = model->getEigenValues();
    // And we can do the same to display the Eigenvectors (read Eigenfaces):
//    Mat W = model->getEigenVectors();
    // Get the sample mean from the training data
//    Mat mean = model->getMean();
    return 0;
}

