# Filebeat 與 glibc 版本相容性

舊 ELK 日誌筆記記錄 Ubuntu 22.04（glibc 2.35）與 Filebeat 的相容性問題，當時使用 Filebeat 7.17.2，並認為低於 7.17.2 的版本會衝突。

參考：https://discuss.elastic.co/t/filebeat-and-glibc-errors-on-ubuntu-22-04/306653

這是歷史版本線索，未重新驗證精確修復分界，不可推論所有舊版本都會失敗。排查時確認 Filebeat 版本、發行版、glibc 版本及完整錯誤訊息，並依廠商支援矩陣選擇版本。

來源：TOOLS_NOTE/日誌/ELK（Git 歷史）。
