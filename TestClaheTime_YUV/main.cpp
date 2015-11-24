#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <opencv2/opencv.hpp>
#include <sys/time.h>


using namespace std;
using namespace cv;


int main()
{
    clock_t start, end, start1, end1, start2, end2;
    start = clock();

    //===========================================
    //preapare work in using camera
	Mat frame, image_HSV, resultImg, HistEqualImg, finalImg;
	vector<Mat> hsv(3);

	VideoCapture capture(0);
	if(!capture.isOpened())
	{
	    cout << "camera is done , open fail" << endl;
	    return 0;
	}

	//check the camera
	if(!capture.read(frame))
    {
        cout << "read fail" << endl;
        return -1;
	}

    cout << "djdjdjdjdjdjd" << endl;

    end = clock();

    //print the time of prepare, about 50ms
    cout << "Runtime is :" << (double)(end - start)/CLOCKS_PER_SEC*1000 << "ms" << endl;

    //===========================================
    //get frame and HistEqualize

    int count = 0;
    double sumTime = 0.0;

	//read every frame from the camera
	//##########test result is 146-150ms in average per frame
    while(1)
    {

        count++;
        start = getTickCount();

        //imshow("camera", frame);



        cvtColor(frame,image_HSV, CV_BGR2YUV);
        split(image_HSV, hsv);


        //=====##### test result is 90ms in average while doing clahe processing in YUV
        start1 = getTickCount();
        Ptr<CLAHE> clahe = createCLAHE();
        clahe -> setClipLimit(4);
        clahe -> apply(hsv[0],resultImg);
        //equalizeHist(hsv[0], resultImg);
        end1 = getTickCount();
        cout << endl << "clahe use ------> " << (double)(end1 - start1)/getTickFrequency() * 1000 << "ms" << endl;

        //imshow("After HistEqualize", hsv);

        //start2 = getTickCount();
        resultImg.copyTo(hsv[0]);
        merge(hsv, HistEqualImg);
        cvtColor(HistEqualImg, finalImg, CV_YUV2BGR);
        //end2 = getTickCount();
        //cout << endl << "cvtColor(CV_HSV2BGR) use ------> " << (double)(end2 - start2)/getTickFrequency() * 1000 << "ms" << endl;

        imshow("After HistEqualize", finalImg);

        capture.read(frame);

        end = getTickCount();
        double deltT = (double)(end - start) / getTickFrequency() * 1000;

        sumTime = deltT + sumTime;

	//every 5 frame calculate the average time
        if(count == 5)
        {
            cout << "============================" << endl;
            cout << "the average time of 5 frames is " << sumTime/5 << "ms" << endl;
            cout << "============================" << endl;
            sumTime = 0;
            count = 0;
        }

        if(waitKey(10)>= 0)
        {
            break;
        }

    }

    //===========================================

    capture.release();
    return 0;

}




