# Raspberry-Pi
Image Processing On Raspberry-Pi 2
My Chinese is better than English. :blush: It will be very nice of you to point out the error(code or English).

This is the work from my Lab.
We need to impove the visibility of the image from the camera. This need to be real-time and well improved.

We only have about 40ms to capture a frame and then do some algorithm on it and showing. 

From TestCapFrameAndShowTime, the result is 20ms-24ms to capture a frame and show it.

From TestHistEqualizeTime_HSV, the result is about 15ms while doing global histogram equalization on a image(700*1024).

From TestClaheTime_YUV, I changed the color space from HSV to YUV. The fuction cvtColor(,,CV_YUV2BGR) decrease to 25ms from 150ms of cvtColor(,,CV_HSV2BGR). CLAHE needs 90ms, the average time to capture-process-show is 165ms.
