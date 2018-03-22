echo "do createsamples? Y or N"
read sample
if [[ $sample = 'Y' ]];then
opencv_createsamples -vec pos.vec -info posdata.txt -w 20 -h 20 -num 583  
fi
echo "do haartraining? Y or N"
read train
if [[ $train = 'Y' ]];then
opencv_haartraining  -data xml2  -vec pos.vec -w 20 -h 20  -bg negdata.txt  -npos 560  -nneg 1832  -nstages 15  -nsplits 2  -nonsym  -minhitrate 0.998  -maxfalsealarm 0.45  -mem 1024  -mode ALL
fi  
echo "done"
