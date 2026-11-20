# APT 套件查詢與升級

## 套件資訊、依賴與升級

```bash
dpkg -L package
apt-cache madison package
apt-cache policy package
apt-rdepends -f Depends,Recommends -s Depends,Recommends package
```

依序查安裝檔案、版本、候選版本與依賴樹。apt-rdepends 可能須另行安裝。安全更新可參考 CVE Program Mission（https://www.cve.org/）及發行版安全公告；CVE 編號本身不代表本機必受影響。

舊筆記記錄系統升級失敗可能與 ROS 綁定 Ubuntu 版本有關，可能須先移除不相容 ROS 套件；應先核對支援矩陣、備份並模擬變更，不直接移除整套 ROS。

- [歷史來源故障](apt-legacy-incidents.md)
- [Ubuntu 安裝注意事項](../../operating-systems/installation/ubuntu.md)
