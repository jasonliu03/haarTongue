#include "opencv/cv.h"
#include "opencv2/opencv.hpp"
#include "stdio.h"
#include <iostream>

using namespace std;
using namespace cv;

CvMemStorage* storageS;
CvHaarClassifierCascade* cascadeS;
char const* cascade_nameS = "haarcascade_tongue.xml";
//char const* cascade_nameS = "haar_adaboost.xml";
CvRect *r, maxR;

bool doDetect(IplImage* imageSrcS) {
  bool isTongue = false;
  cascadeS = (CvHaarClassifierCascade*)cvLoad(cascade_nameS, 0, 0, 0);
  storageS = cvCreateMemStorage(0);

  double scale = 1.0;
  IplImage* gray =
      cvCreateImage(cvSize(imageSrcS->width, imageSrcS->height), 8, 1);
  IplImage* small_img =
      cvCreateImage(cvSize(cvRound(imageSrcS->width / scale),
                           cvRound(imageSrcS->height / scale)),
                    8, 1);

  cvCvtColor(imageSrcS, gray, CV_BGR2GRAY);
  cvResize(gray, small_img, CV_INTER_LINEAR);
  cvClearMemStorage(storageS);

  int rSize, maxSize = 0;
  int cnt = 0;
  if (cascadeS) {
    CvSeq* tongues = cvHaarDetectObjects(small_img, cascadeS, storageS, 1.1, 2,
                                         CV_HAAR_FIND_BIGGEST_OBJECT |
                                             CV_HAAR_DO_ROUGH_SEARCH |
                                             CV_HAAR_DO_CANNY_PRUNING,
                                         cvSize(100, 100));
    cnt = tongues->total;
    for (int i = 0; i < (tongues ? tongues->total : 0); i++) {
      r = (CvRect*)cvGetSeqElem(tongues, i);
      rSize = r->width * r->height;
      if (rSize > maxSize) {
        maxSize = rSize;
        maxR = *r;
      }
    }

  } else {
    cout << "Loading haarcascade_tongue.xml is wrong!!" << endl;
  }

  cvReleaseImage(&gray);
  cvReleaseImage(&small_img);
  if (cnt == 0) {
    maxR.x = 0;
    maxR.y = 0;
    maxR.width = 0;
    maxR.height = 0;
    isTongue = false;
  } else {
    isTongue = true;
  }
  return isTongue;
}

int main()
{
    string dir_path = "./forDetect/";
    Directory dir;
    vector<string> fileNames = dir.GetListFiles(dir_path, "*", false);

    for(int i=0; i < fileNames.size(); i++){
        string fileFullName = dir_path + fileNames[i];
        cout << "fileFullName:" << fileFullName << endl;

        IplImage* imageSrcS = cvLoadImage(fileFullName.c_str()); 
        bool rst = doDetect(imageSrcS);
        cout << "rst:" << rst << endl;
        cvRectangle (
            imageSrcS,
            cvPoint(maxR.x,maxR.y),
            cvPoint(maxR.x+maxR.width,maxR.y+maxR.height),
            cvScalar(0x00,0x00,0xff) /* blue */
        );

        cvShowImage("rst", imageSrcS);
        cvWaitKey(0);
    }
    return 0;
}

