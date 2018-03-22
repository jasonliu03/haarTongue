#include "opencv2/opencv.hpp"
#include "stdio.h"

int cascade()
{

char* haartraining_ouput_dir ="xml"; //根据实际情况修改

char* ouput_file ="xml/haar_adaboost.xml";//根据实际情况修改


const char* size_opt = "--size=";

char comment[1024];

CvHaarClassifierCascade* cascade = 0;

CvSize size;


size.width= 20; //根据实际情况修改

size.height= 20; //根据实际情况修改


cascade= cvLoadHaarClassifierCascade(haartraining_ouput_dir,size);

if(!cascade ){

    fprintf(stderr,"Inputcascade could not be found/opened\n");

return -1;

}

sprintf(comment, "Automaticallyconverted from %s, window size = %dx%d",ouput_file, size.width, size.height );

cvSave(ouput_file, cascade, 0, comment, cvAttrList(0,0) );

return 0;

}

int main()
{
    cascade();
    return 0;
}
