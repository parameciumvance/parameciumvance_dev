#!/bin/bash

#避免連桌面環境一起裝的錯誤(參考linux note-Ubuntu20錯誤:桌面環境做為依賴被無意安裝)
sudo apt install libnotify4 --no-install-recommends

#apt依賴
echo "Installing ubuntu packages"
sudo apt-get update
sudo apt-get install ${PACKAGES} -y

#ros包依賴
rosdep install --from-paths ${ROS_WS}/src --ignore-src -r -y

#remove official version to avoid conflict to our version
#navigation-stack
sudo apt remove \
ros-${ROS_DISTRO}-amcl \