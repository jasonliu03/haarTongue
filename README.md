
0. ./resizeSample (dst->posdata)
1. ./genInfoFiles.sh (gen posdata.txt, negdata.txt)
2. ./haartrain.sh (need adjust params) 
3. ./convert_cascade (gen haar_adaboost.xml from xml directory using middle levers if trainging not done)
4. ./detectObject (test detect acc default using fotDetect directory)
