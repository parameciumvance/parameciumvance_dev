# APT 舊版套件來源故障紀錄

> **歷史案例，尚未重新驗證。** 來源：[舊 APT 筆記](../TOOLS_NOTE/套件管理/apt%20note)。案例與 Ubuntu bionic（18.04）、舊 ROS 軟體來源相關。

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
