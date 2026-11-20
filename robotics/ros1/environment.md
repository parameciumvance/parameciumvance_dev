# ROS1 開發環境與依賴

以下為歷史案例，未重新驗證；ROS1 已終止官方維護，不應直接執行舊部署腳本。專案專屬路徑僅作歷史追溯。舊流程為 source 環境、更新依賴、編譯安裝至專案前綴、source 安裝環境。

Ubuntu 20.04 的 libnotify4 預防對策，見 [Ubuntu 安裝注意事項](../../operating-systems/installation/ubuntu.md)。

## 機器端開發歷史流程

原專案使用 `share/rover_maintain_setup.source` 作為參考，依序 `. setup.source`、`./bbot_latest/tool/update_dependency.bash`、編譯並安裝到 `bbot_latest`、`. install_pkgs.source`。這些名稱僅為原始案例的追溯線索，不是 ROS 標準路徑或通用命令。

## 歷史依賴腳本

原腳本保留供研究，變數須由環境設定，不是可直接執行的通用 SOP。return 只適用被 source 或函式內；未知 OS 分支不應以成功表示失敗。移除套件前須模擬並檢查反向依賴；不可直接照做。python-is-python3 不是所有非 bionic 發行版均提供。

update_dependency.bash
```
OS=`lsb_release -sc`

#避免連桌面環境一起裝的錯誤(ubuntu20的bug)
sudo apt install libnotify4 --no-install-recommends

#讓python腳本在直接執行或未被標準安裝時也一致用python3,參考"python直譯器宣告問題"
if [ "${OS}" != "bionic" ]; then
    sudo apt install python-is-python3
fi

PACKAGES=""
if [ "${OS}" = "trusty" ]; then
    echo "14.04 selected\n"
    PACKAGES=${PACKAGES_14_04};
elif [ "${OS}" = "xenial" ]; then
    echo "16.04 selected\n"
    PACKAGES=${PACKAGES_16_04};
elif [ "${OS}" = "bionic" ]; then
    echo "18.04 selected\n"
    PACKAGES=${PACKAGES_18_04};
elif [ "${OS}" = "focal" ]; then
    echo "20.04 selected\n"
    PACKAGES=${PACKAGES_20_04};
else
    echo "unknown OS, aborting\n"
    return 0
fi;

echo ${PACKAGES}

# required libraries and packages
echo "Installing ubuntu packages"
sudo apt-get update
sudo apt-get install ${PACKAGES} -y
rosdep install --from-paths ${ROS_WS}/src --ignore-src -r -y

# remove official version to avoid conflict to our version
# navigation-stack
sudo apt remove \
ros-${ROS_DISTRO}-amcl \
ros-${ROS_DISTRO}-base-local-planner \
ros-${ROS_DISTRO}-carrot-planner \
ros-${ROS_DISTRO}-clear-costmap-recovery \
ros-${ROS_DISTRO}-costmap-2d \
ros-${ROS_DISTRO}-dwa-local-planner \
ros-${ROS_DISTRO}-fake-localization \
ros-${ROS_DISTRO}-global-planner \
ros-${ROS_DISTRO}-map-server \
ros-${ROS_DISTRO}-move-base \
ros-${ROS_DISTRO}-move-slow-and-clear \
ros-${ROS_DISTRO}-nav-core \
ros-${ROS_DISTRO}-navfn \
ros-${ROS_DISTRO}-navigation \
ros-${ROS_DISTRO}-rotate-recovery \
ros-${ROS_DISTRO}-voxel-grid

echo "done"
```

#### 準備
(ROS Noetic)sudo apt-get install python3-rosdep
(ROS Melodic and earlier)sudo apt-get install python-rosdep
sudo rosdep init
rosdep update

#### 依賴
更新依賴腳本:update_dependency.bash

寫在package.xml中的依賴會從[rosdep目錄](https://github.com/ros/rosdistro/tree/master/rosdep)中尋找對應名稱

目錄居然是個別貢獻新增的,要用的庫不一定在裡面(e.g. socketio_client)
不在的庫就要另外在腳本中列出用apt直接安裝

rosdep目錄介紹
[Contributing rosdep rules](http://docs.ros.org/en/independent/api/rosdep/html/contributing_rules.html)

#### 金鑰歷史線索
原筆記記錄效期至 2025/6/1，未標明金鑰 ID；不可作為目前有效性依據。

#### 和conda共用
在虛擬環境下python工具需另外下載(pip)
pip install catkin_pkg empy nose setuptools numpy rospkg PyYAML defusedxml opencv-python
catkin-> catkin_pkg empy nose setuptools
rospy-> numpy rospkg PyYAML
rosmaster-> defusedxml
其他-> opencv-python

#### python執行檔
python直譯器宣告問題
如果腳本前直譯器宣告是"#!/usr/bin/env python"或"#!/usr/bin/python"直接執行會變成用python2
但在使用catkin_install_python安裝後,直譯器宣告都會自動變成"#!/usr/bin/env python3"
為了讓python腳本在直接執行或未被標準安裝時也一致用python3,應該要先apt install python-is-python3

直譯器補充：catkin_install_python 依配置的 Python interpreter 重寫 shebang，並非總是 python3；直接執行時 python 可能不存在或指向不同版本。Conda 套件版本須與 ROS 發行版及 ABI 配合；舊 pip 清單不是完整鎖定環境。
