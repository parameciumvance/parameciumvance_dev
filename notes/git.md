# Git 技術筆記

> 來源：[舊版 Git 筆記](../TOOLS_NOTE/版本控制%20git/版本控制note)。本頁整理可重用的概念；舊版工具與安裝指令仍以原文保存。

## 檔案模式與權限

Git 對一般檔案主要追蹤是否具有**可執行位元**（例如 `100644` 與 `100755`），並不完整追蹤 Unix 的擁有者、群組與所有權限位元。跨系統協作時應注意工作目錄的檔案權限與 Git 記錄的可執行狀態是兩回事。

若檔案內容沒有變更，但 Git 顯示 modified，可先使用：

```bash
git diff --summary
git diff --check
git config --get core.filemode
```

若只有 mode 改變，應先確認是否是預期的執行權限調整。設定 `core.filemode=false` 會讓 Git 忽略工作樹的可執行位元差異，但**不是所有權限問題的通用修復**。

## Git LFS

使用 Git LFS 的儲存庫，Git checkout 後可能需要取得大型檔案內容：

```bash
git lfs pull
```

需先確認系統已安裝 Git LFS，且對遠端儲存庫有存取權。若下載到的是指標文字而非實際檔案，應檢查 LFS 設定。

## 歷史線索

舊筆記記錄 SmartGit 22.1 Preview 的 Save As 權限問題；這是特定版本歷史事件，非現行通則。

## 延伸閱讀

- [Git 檔案模式排查](../troubleshooting/git-filemode.md)
