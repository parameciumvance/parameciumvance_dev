END=10
./tool/talker_b.sh &
pid=$!
echo $pid
for i in $(seq 1 $END);
do
    echo hi;
    sleep 1
done
kill $pid