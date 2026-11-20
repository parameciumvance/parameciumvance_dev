# Ubuntu 安裝注意事項

## Ubuntu Server 20.04：避免意外安裝桌面環境

**安裝時預防對策**：若目標為不需要桌面的 Ubuntu Server 20.04（focal），在系統初始設定階段、安裝應用程式及其他相依套件之前，先確認並安裝 libnotify4，不帶入推薦套件：

```bash
sudo apt install libnotify4 --no-install-recommends
```

原因：原筆記指出 focal 的 libnotify4 將 gnome-shell 列為 Recommends，APT 預設可能安裝推薦依賴，導致後續安裝其他套件時意外帶入桌面環境。Ubuntu 22.04（jammy）則改為 Suggests。

原建議適用於 20.04 <= 版本 < 22.04 的歷史設備環境；實際依賴關係尚未重新驗證。可先使用 `apt-get -s install libnotify4 --no-install-recommends` 模擬確認。此措施不保證其他套件不會另外引入桌面，也不會移除已安裝的桌面。

參考：
- https://github.com/ros-perception/perception_pcl/issues/355 （原作者留言）
- https://packages.ubuntu.com/focal/libnotify4
- 原始來源：TOOLS_NOTE/作業系統/Linux note（Git 歷史）
