echo "do createsamples? Y or N"
read sample

num=2477
npos=$[$num-150]
nneg=7493
nstages=25
echo $num
echo $npos

if [[ $sample = 'Y' ]];then
opencv_createsamples -vec pos.vec -info posdata.txt -w 20 -h 20 -num $num  
fi
echo "do haartraining? Y or N"
read train
if [[ $train = 'Y' ]];then
opencv_traincascade  -data xml_cascade -vec pos.vec -bg negdata.txt -numPos $npos -numNeg $nneg -numStages $nstages -precalcValbufSize 1024 -precalcdxBufSize 2048 -featureType HAAR  -w 20 -h 20 -minHitRate 0.998 -maxFalseAlarmRate 0.45 -weightTrimRate 0.95 -maxDepth 1 -maxWeakCount 100 -mode ALL
fi  
echo "done"
