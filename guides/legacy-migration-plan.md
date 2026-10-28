# 舊知識遷移盤點

> 狀態：進行中。保留原始文件，採增量萃取，不以大量搬移作為整理目標。

| 來源 | 目標 | 狀態 | 注意事項 |
| --- | --- | --- | --- |
| [開發/專案SOP](../開發/專案SOP) | [專案開發流程](development/project-development.md) | 已萃取初版 | ROS1、Ubuntu 舊版細節仍待分類 |
| [開發/測試](../開發/測試) | [測試策略](development/testing.md) | 已萃取初版 | 重啟與設備恢復需補實際案例 |
| [開發/版本更新](../開發/版本更新) | [歷史版本相容性](../notes/version-compatibility-history.md) | 已萃取初版 | 待驗證，不作現行建議 |
| [開發/CMAKE note](../開發/CMAKE%20note) | 依建置領域分類（待確認） | 待處理 | 需確認版本與用途 |
| [TOOLS_NOTE](../TOOLS_NOTE/) | [Git](../development/version-control/git.md)、[Python](../development/programming/python.md)、[Git 權限排查](../development/version-control/git-filemode.md)、[APT 歷史案例](../development/package-management/apt-legacy-incidents.md) | 部分已萃取 | 其他工具、語言與平台筆記仍待盤點 |
| [TROUBLESHOOT](../TROUBLESHOOT) | [診斷流程](../troubleshooting/diagnostic-workflow.md)、[案例索引](../troubleshooting/legacy-case-index.md) | 已萃取初版 | 各案例仍需逐一確認根因 |
| [開發日誌](../開發日誌/) | archive 或原位 | 待盤點 | 歷史紀錄不應改寫為現行規範 |

## 遷移準則

- **現行建議**：有可重用價值，整理到 guides。
- **技術事實與研究**：整理到 notes，標註版本與限制。
- **具體故障案例**：整理到 troubleshooting，保留症狀、根因與解法。
- **過時但有參考價值**：保留原始紀錄，必要時歸檔。
- **尚未確認**：標記待驗證，不因整理而擅自提升為事實。

每次遷移應檢查內部連結、來源追溯與是否含敏感資料。
