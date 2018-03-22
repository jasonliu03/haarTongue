echo "do createsamples? Y or N"
read sample

num=1081
npos=$[$num-20]
nneg=3028
nstages=15
mem=2048
echo $num
echo $npos

if [[ $sample = 'Y' ]];then
opencv_createsamples -vec pos.vec -info posdata.txt -w 20 -h 20 -num $num  
fi
echo "do haartraining? Y or N"
read train
if [[ $train = 'Y' ]];then
opencv_haartraining  -data xml  -vec pos.vec -w 20 -h 20  -bg negdata.txt  -npos $npos  -nneg $nneg  -nstages $nstages  -nsplits 2  -nonsym  -minhitrate 0.998  -maxfalsealarm 0.45  -mem $mem  -mode ALL
fi  
echo "done"
