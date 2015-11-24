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
    clock_t start, end;
    start = clock();
	Mat frame, image_HSV, image_CLAHE;



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

    end = clock();

   //print the time of prepare, about 50ms
    cout << "Runtime is :" << (double)(end - start)/CLOCKS_PER_SEC*1000 << "ms" << endl;


    int count = 0;
    double sumTime = 0.0;

	//read every frame from the camera
    while(1)
    {

        count++;
        start = getTickCount();

        imshow("camera",frame);
        capture.read(frame);

        end = getTickCount();
        double deltT = (double)(end - start) / getTickFrequency() * 1000;


        sumTime = deltT + sumTime;

	//every 5 frame calculate the average time , about 20-24ms per-second
        if(count == 5)
        {
            cout << "==================" << endl;
            cout << "the average time of 5 frames is " << sumTime/5 << "ms" << endl;
            cout << "==================" << endl;
            sumTime = 0;
            count = 0;
        }

        if(waitKey(10)>= 0)
        {
            break;
        }

    }

    capture.release();
    return 0;

}




