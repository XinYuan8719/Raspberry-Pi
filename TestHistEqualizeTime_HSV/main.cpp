#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <sys/time.h>

using namespace std;
using namespace cv;

Mat doHistEqualizeAndCalAvgTimeUsed(Mat image, int times);

int main()
{
    Mat image1 = imread("123.jpg",CV_8U);
    Mat imageResult;
    Mat image2 = imread("456.jpg",CV_8U);
    Mat image3 = imread("666.png",CV_8U);
    Mat image4 = imread("789.jpg",CV_8U);


    imshow("imageOri", image1);
    imageResult = doHistEqualizeAndCalAvgTimeUsed(image1, 5);
    imshow("imageResult", imageResult);
    waitKey(0);

    imshow("imageOri", image2);
    imageResult = doHistEqualizeAndCalAvgTimeUsed(image2, 5);
    imshow("imageResult", imageResult);
    waitKey(0);

    imshow("imageOri", image3);
    imageResult = doHistEqualizeAndCalAvgTimeUsed(image3, 5);
    imshow("imageResult", imageResult);
    waitKey(0);

    imshow("imageOri", image4);
    imageResult = doHistEqualizeAndCalAvgTimeUsed(image4, 5);
    imshow("imageResult", imageResult);
    waitKey(0);

    return 0;

}

//imput : the image to do
//output: the image done
Mat doHistEqualizeAndCalAvgTimeUsed(Mat image, int times)
{
    cout << "===========================================" << endl;
    cout << "the image is " << image.rows << "*" << image.cols << endl;
    Mat imageResult;
    int64_t start, end;
    int count = 0;
    double sumTimes = 0.0;
    while (count <= times)
    {
        count++;
        start = cv::getTickCount();
        cout << "start is : " << start << endl;
        equalizeHist(image,imageResult);
        //for(int i = 0; i < 1000000; i++);
        end = cv::getTickCount();
        //cout << "end is : " << end << endl;
        double timeResult = (double)(end - start)/cv::getTickFrequency() * 1000;
        cout << "the " << count << " time of Hist, time is " << timeResult << "ms" << endl;
        sumTimes = timeResult + sumTimes;
    }




    cout << "the average time used is : " << sumTimes/count << "ms" << endl;
    cout << "===========================================" << endl;

    return imageResult;
}




