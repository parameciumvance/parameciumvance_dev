# Linux 手冊與命令

來源：TOOLS_NOTE/作業系統/Linux note（Git 歷史）。依目標系統實際配置確認。

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
