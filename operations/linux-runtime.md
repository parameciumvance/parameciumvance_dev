# Linux 執行環境與診斷

來源：TOOLS_NOTE/作業系統/Linux note（Git 歷史）。依目標系統實際配置確認。

## 使用者執行期目錄

`/run/user/1000` 是 UID 1000 的典型 runtime 目錄，通常由 session 管理機制在首次登入建立，最後 session 結束後清理；linger、背景服務及配置可能改變生命週期。舊筆記觀察預先建立的目錄會在登入被刪除重建，不應視為所有環境保證。不要手動預建或存放永久資料。

參考：https://unix.stackexchange.com/questions/162900/what-is-this-folder-run-user-1000

## 桌面選取與剪貼簿

舊 Debian 桌面環境中反白文字後按滑鼠中鍵可貼上，通常是 X11 PRIMARY selection，與 CLIPBOARD 分開；Wayland、桌面及應用程式支援可能不同。

## 手冊與命令

線上手冊：https://man7.org/linux/man-pages/index.html 。標題括號數字表示章節。

| 章節 | 內容 |
| --- | --- |
| 1 | 可執行程式或 shell 指令 |
| 2 | 系統呼叫 |
| 3 | 函式庫 |
| 4 | 特殊檔案（如 /dev） |
| 5 | 檔案格式與協定，如 /etc/passwd |
| 6 | 遊戲 |
| 7 | 雜項、慣例、巨集，如 man(7)、groff(7) |
| 8 | 系統管理命令 |
| 9 | Kernel routines（非標準，依系統） |

`man 5 passwd` 可指定章節；`command -v python3` 查找命令。

## 檔案與資源管理

```bash
find /path/to/file/ -iname filename
tar cvf aaa.tar folder
tar xvf aaa.tar
fuser -m /the_dir
```

find -iname 不區分大小寫；tar 上例未壓縮，解包前應確認內容與目的路徑。fuser -m 查找使用該掛載檔案系統的程序。

## 使用者切換與環境

sudo 通常依 sudoers 政策過濾環境，不一定是登入 shell；su - 建立登入環境並通常切換至目標 HOME，su 保留較多原環境但 PATH 等可能重設。screen 啟動時通常繼承環境，已存在 session 不一定跟隨新 shell 的配置。不要假定完全繼承或完全清空，可比較 env。

## 相關領域

- [二進位診斷與 CPU 指令集](../development/build/binary-diagnostics.md)
- [時間同步](time-synchronization.md)
- [APT 歷史案例與套件查詢](../development/package-management/apt-legacy-incidents.md)
- [媒體處理](../development/media-processing.md)
