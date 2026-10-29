# 舊知識遷移盤點

> 狀態：進行中。採逐項消耗式遷移：已完整搬移的舊內容於同一 PR 清除；剩餘舊內容即待處理工作。原始版本由 Git 歷史追溯。

| 來源 | 目標 | 狀態 | 注意事項 |
| --- | --- | --- | --- |
| [開發/專案SOP](../開發/專案SOP) | [專案開發流程](development/project-development.md) | 已萃取初版 | ROS1、Ubuntu 舊版細節仍待分類 |
| [開發/測試](../開發/測試) | [測試策略](development/testing.md) | 已萃取初版 | 重啟與設備恢復需補實際案例 |
| [開發/版本更新](../開發/版本更新) | [歷史版本相容性](../notes/version-compatibility-history.md) | 已萃取初版 | 待驗證，不作現行建議 |
| [開發/CMAKE note](../開發/CMAKE%20note) | [CMake 組態](../development/build/cmake-configuration.md) | 已萃取初版 | 實際旗標依工具鏈而定 |
| [TOOLS_NOTE](../TOOLS_NOTE/) | [Git](../development/version-control/git.md)、[Python](../development/programming/python.md)、[Git 權限排查](../development/version-control/git-filemode.md)、[APT 歷史案例](../development/package-management/apt-legacy-incidents.md) | 部分已萃取 | 已增補 [Linux](../operations/linux-runtime.md)、[ROS1 建置](../development/build/ros1-catkin-legacy.md) 與 [ROS1 程序日誌](../operations/ros1-process-logging.md)；其他工具仍待盤點 |
| [TROUBLESHOOT](../TROUBLESHOOT) | [診斷流程](../troubleshooting/diagnostic-workflow.md)、[案例索引](../troubleshooting/legacy-case-index.md) | 已萃取初版 | 各案例仍需逐一確認根因 |
| [TOOLS_NOTE/網路](../TOOLS_NOTE/網路) | [TCP 連接埠診斷](../networking/tcp-port-diagnostics.md) | 已萃取初版 | Telnet 僅用於基本連線測試 |
| [TOOLS_NOTE/程式語言/PY vs C++](../TOOLS_NOTE/程式語言/PY%20vs%20C%2B%2B) | [Python／C++ 語意比較](../development/programming/python-cpp-semantics.md) | 已萃取初版 | 舊版對照非嚴格等價，已註明差異 |
| `TOOLS_NOTE/程式語言/C&C++/C&C++ note`（Git 歷史） | [C/C++ 語意陷阱](../development/programming/c-cpp-pitfalls.md) | **已清除** | 逐項補齊後刪除舊筆記 |
| [TOOLS_NOTE/程式語言/C&C++/TROUBLESHOOT](../TOOLS_NOTE/程式語言/C%26C%2B%2B/TROUBLESHOOT) | [編譯故障](../development/build/compiler-toolchain-diagnostics.md) | **部分剩餘** | 仍待逐項核對原始編譯案例；CUDA／GCC 屬歷史限制 |
| `TOOLS_NOTE/程式語言/shell語言/`（Git 歷史） | [Shell 腳本](../development/programming/shell-scripting.md)、[完整原始腳本](../development/programming/examples/getopt-conda-legacy.sh) | **已清除** | 原始 Bash 筆記已整理，腳本原文搬入正式領域 |
| [開發日誌](../開發日誌/) | archive 或原位 | 待盤點 | 歷史紀錄不應改寫為現行規範 |

## 遷移準則

- **現行建議**：有可重用價值，整理到對應工程領域並標明推薦做法。
- **技術事實與研究**：整理到對應工程領域，標註版本與限制。
- **具體故障案例**：整理到對應工程領域，保留症狀、根因與解法，並加入故障索引。
- **過時但有參考價值**：保留必要的歷史情境與操作細節，完成遷移後清除舊副本。
- **尚未確認**：標記待驗證，不因整理而擅自提升為事實。

每次遷移應檢查內部連結、來源追溯與是否含敏感資料。
