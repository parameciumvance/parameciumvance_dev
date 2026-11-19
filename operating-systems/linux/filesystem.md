# Linux 檔案系統

來源：TOOLS_NOTE/作業系統/Linux note（Git 歷史）。依目標系統實際配置確認。

## 使用者執行期目錄

`/run/user/1000` 是 UID 1000 的典型 runtime 目錄，通常由 session 管理機制在首次登入建立，最後 session 結束後清理；linger、背景服務及配置可能改變生命週期。舊筆記觀察預先建立的目錄會在登入被刪除重建，不應視為所有環境保證。不要手動預建或存放永久資料。

參考：https://unix.stackexchange.com/questions/162900/what-is-this-folder-run-user-1000
