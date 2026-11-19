# Shell 腳本：環境初始化與參數解析

> 來源：[舊 Bash 筆記](../../TOOLS_NOTE/程式語言/shell語言/bash%20note)及[完整歷史腳本範例](examples/getopt-conda-legacy.sh)。完整範例已搬入本領域，以下整理用途與限制。

## source 與執行環境

`source file`（或 `. file`）會在**目前 shell** 執行檔案內容；執行 `./script.sh` 則通常啟動子程序。子程序的變數變更不會自動回寫父 shell。

舊筆記提及「腳本中 source .bashrc 會被忽略」；更精確地說，`~/.bashrc` 常包含**非互動 shell 直接返回**的防護邏輯，因此在腳本中 source 後，預期的初始化內容可能沒有執行。建議將需要重用的環境變數或函式抽成獨立、可明確載入的檔案。

## 錯誤處理

原始範例使用：

```bash
#!/usr/bin/env bash
set -e
```

`set -e` 會在部分命令失敗時結束 shell，但在條件判斷、管線、函式等情境有例外，**不等於所有錯誤都會自動中止**。視需求考慮 `set -o pipefail` 並明確檢查重要命令。

## Conda 啟動（歷史範例）

原始腳本使用：

```bash
. "$(dirname "$CONDA_EXE")/../etc/profile.d/conda.sh"
conda activate base
```

這依賴 `CONDA_EXE` 已設定且該路徑結構有效；在不同安裝方式與 CI 環境需另行驗證。範例原本的路徑未加引號，整理時已補上。

## getopt 參數解析

原始腳本展示 GNU `getopt` 的短選項 `-a`、`-b <值>`、`-c[可選值]` 與對應長選項，並用 `eval set -- "$TEMP"` 重新排列參數。

注意：
- `getopt` 的 GNU 與 BSD 實作不完全相同，不能假設跨平台一致。
- 原始腳本使用 `set -e`，緊接 `getopt` 失敗後才檢查 `$?`，在某些情況下可能已提前退出。較穩妥的寫法是直接以 `if ! TEMP=$(getopt ...); then ... fi` 處理失敗。
- `eval` 只應搭配符合預期且可信的引用／跳脫輸出；不要自行拼接未經處理的外部字串。

## 相關文件

- [完整 Bash 範例（歷史版本，未修正）](examples/getopt-conda-legacy.sh)
- [程式設計](README.md)
