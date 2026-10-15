# Git 顯示檔案已修改，但內容沒有差異

> 來源：[舊版 Git TROUBLESHOOT](../TOOLS_NOTE/版本控制%20git/TROUBLESHOOT)。

## 症狀

`git status` 顯示 modified，但內容沒有預期的文字差異。

## 診斷

```bash
git diff --summary
git diff --raw
git config --get core.filemode
```

如果出現 `old mode 100755`、`new mode 100644`，代表 Git 偵測到可執行位元變化。

## 處理原則

- 若程式確實應具可執行權限，修正工作樹權限並視需要提交 mode 變更。
- 若檔案不應可執行，確認這是有意的模式變更。
- 若檔案系統無法可靠回報可執行位元，才評估對**該儲存庫**設定 `git config core.filemode false`。

設定 `core.filemode=false` 只影響 Git 如何判定工作樹的執行位元差異，不會修復作業系統權限，也可能掩蓋必要的執行權限變更。

## Issue 回饋

若在專案中反覆發生，依[Issue 三問制度](../guides/development/project-development.md#issue錯誤修正的三個必答問題)檢查測試、SOP 與本故障紀錄是否需要更新。
