#!/usr/bin/env bash
set -e #有錯時停止腳本
END=50
./tool/talker.sh &
for i in $(seq 1 $END);
do
    echo -- $i;
    sleep 1
done