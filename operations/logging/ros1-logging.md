# ROS1 日誌輸出與保留

歷史案例，非 ROS2 通用規則。

roslaunch 的 screen／log 在即時性與保存性有取捨。log 緩衝可能延遲輸出；舊 workaround：

```bash
stdbuf -o L roslaunch <launchfile>
```

參考 https://github.com/ros/rosconsole/issues/5 。不保證子程序或所有 logging 實作受 stdbuf 影響；screen 也不代表完全沒有其他日誌。

## 保存與容量

舊筆記的輪替命令（僅歷史紀錄，不直接執行）：

```bash
rm -rf /root/.ros/logBU
mv /root/.ros/log /root/.ros/logBU
mkdir /root/.ros/log
```

此操作刪除舊備份，應先確認容量、保存政策、權限、程序是否仍開啟檔案與實際 ROS_LOG_DIR；主要風險是磁碟空間耗盡，不是必然 RAM 耗盡。

## 中文顯示

舊案例加入 #include <locale.h> 與 setlocale(LC_CTYPE,"zh_TW.utf8"); 無效，改用 setlocale(LC_ALL, ""); 後成功；原因待研究，須確認系統 locale、環境變數與輸出編碼。

參考 http://wiki.ros.org/indigo/Installation/UbuntuARM 、 https://docs.microsoft.com/zh-tw/cpp/c-runtime-library/reference/setlocale-wsetlocale?view=msvc-170 。
