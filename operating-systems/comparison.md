# 作業系統比較

| 面向 | Windows／Linux 差異 |
| --- | --- |
| 文字換行 | Windows 常見 CRLF，Linux 常見 LF；依 repository 的 .gitattributes 等規範處理 |
| 檔名大小寫 | Windows 常見檔案系統預設不區分大小寫，Linux 常見區分；實際依檔案系統與配置 |
| 檔名限制 | Windows Win32 一般路徑不允許尾部空格，或反斜線、斜線、冒號、星號、問號、雙引號、小於、大於、直線等字元 |
| 軟體生態 | Steam 個別遊戲支援平台不同，須查實際遊戲 |
| GPU 容器 | 舊筆記稱 Windows 沒有 NVIDIA Docker；現已可在支援的 Windows WSL2 Linux 容器環境使用 NVIDIA GPU，不能與原生 Windows 容器支援混為一談 |

來源：TOOLS_NOTE/作業系統/比較（Git 歷史）。GPU 支援仍須依實際驅動及容器環境確認。
