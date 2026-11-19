# APT 舊版套件來源故障紀錄

> **歷史案例，尚未重新驗證。** 來源：`TOOLS_NOTE/套件管理/apt note`（Git 歷史）。案例與 Ubuntu bionic（18.04）、舊 ROS 軟體來源相關。

## 案例一：RealSense 套件來源回傳 HTTP 403

原筆記記錄 `apt-get update` 連線至舊 RealSense APT 來源時收到 `403 Forbidden`，當時採用更換套件來源網址的方式排除。

**目前處理建議**：先確認 Ubuntu 發行版、來源清單與廠商目前公布的支援方式；不要直接複製舊筆記中的替換指令。

## 案例二：ROS APT 來源金鑰過期

原筆記記錄 `EXPKEYSIG` 錯誤，並連結 ROS GPG 金鑰過期事件：
[ROS GPG key expiration incident](https://discourse.ros.org/t/ros-gpg-key-expiration-incident/20669)。

舊解法使用 `apt-key add`，但此方法已不適合作為現代 Ubuntu 的通用安裝指引。應依目前 ROS 官方文件使用對應發行版支援的金鑰與套件來源配置。

## 故障紀錄應補充

- Ubuntu／ROS 發行版及日期
- 出錯的套件來源、完整錯誤訊息
- 是否已停用或停止支援
- 依官方文件調整後的驗證結果

## 原始錯誤與歷史修復操作（不是現行安裝指引）

RealSense：`http://realsense-hw-public.s3.amazonaws.com/Debian/apt-repo bionic InRelease`，`403 Forbidden [IP: 52.218.110.42 80]`。
```bash
sed 's/http:\/\/realsense-hw-public.s3.amazonaws.com/https:\/\/librealsense.intel.com/' /etc/apt/sources.list
```
此 sed 命令只輸出替換結果，不會直接修改檔案；舊網域是否仍有效未驗證。

ROS：`http://packages.ros.org/ros/ubuntu bionic InRelease`，`EXPKEYSIG F42ED6FBAB17C654 Open Robotics <info@osrfoundation.org>`。原筆記記錄金鑰於 5/29 過期，當時重新下載：
```bash
curl -s https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | sudo apt-key add -
```
此為歷史命令，apt-key 已棄用。

## 案例三：Ubuntu 20.04 意外安裝桌面環境

原筆記指出 focal 的 libnotify4 將 gnome-shell 列為 Recommends，jammy（22.04）改為 Suggests；APT 預設可能安裝推薦依賴。舊建議在 Ubuntu Server 20.04 至未滿 22.04 的設備早期設定先執行：

```bash
sudo apt install libnotify4 --no-install-recommends
```

原作者留言：https://github.com/ros-perception/perception_pcl/issues/355 ；版本資料：https://packages.ubuntu.com/focal/libnotify4 。歷史依賴關係及修正動機未重新驗證；先用 apt 模擬安裝並確認依賴，不保證能避免所有後續桌面依賴。

## 套件查詢與升級

```bash
dpkg -L package
apt-cache madison package
apt-cache policy package
apt-rdepends -f Depends,Recommends -s Depends,Recommends package
```

依序查安裝檔案、版本、候選版本與依賴樹。apt-rdepends 可能須另行安裝。安全更新可參考 CVE Program Mission（https://www.cve.org/）及發行版安全公告；CVE 編號本身不代表本機必受影響。

舊筆記記錄系統升級失敗可能與 ROS 綁定 Ubuntu 版本有關，可能須先移除不相容 ROS 套件；應先核對支援矩陣、備份並模擬變更，不直接移除整套 ROS。
