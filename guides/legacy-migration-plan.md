# 舊知識遷移盤點

> 狀態：進行中。採逐項消耗式遷移：已完整搬移的舊內容於同一 PR 清除；剩餘舊內容即待處理工作。原始版本由 Git 歷史追溯。

| 來源 | 目標 | 狀態 | 注意事項 |
| --- | --- | --- | --- |
| `開發/專案SOP`（Git 歷史） | [專案開發流程](development/project-development.md) | **已清除** | 專案流程及組態、介面、維運等領域 |
| `開發/測試`（Git 歷史） | [測試策略](development/testing.md) | **已清除** | 重啟及 ROS 測試歷史案例已整合 |
| `開發/版本更新`（Git 歷史） | [Python 相容性](../development/programming/python-version-compatibility.md)、[容器建置](../development/build/container-build.md) | **已清除** | 歷史線索，未實測 |
| `開發/CMAKE note`（Git 歷史） | [CMake 組態](../development/build/cmake-configuration.md) | **已清除** | 實際旗標依工具鏈而定 |
| `TOOLS_NOTE/`（Git 歷史） | 各正式知識領域 | **已清除** | 20 份舊檔全數遷移 |
| `TOOLS_NOTE/版本控制 git/`（Git 歷史） | [Git](../development/version-control/git.md)、[權限排查](../development/version-control/git-filemode.md) | **已清除** | 兩份原始筆記已逐項補齊 |
| `TOOLS_NOTE/套件管理/apt note`（Git 歷史） | [APT 歷史案例](../development/package-management/apt-legacy-incidents.md) | **已清除** | 保留原始錯誤與歷史指令 |
| [TROUBLESHOOT](../TROUBLESHOOT) | [診斷流程](../troubleshooting/diagnostic-workflow.md)、[案例索引](../troubleshooting/legacy-case-index.md) | 已萃取初版 | 各案例仍需逐一確認根因 |
| `TOOLS_NOTE/網路`（Git 歷史） | [TCP 連接埠診斷](../networking/tcp-port-diagnostics.md) | **已清除** | Telnet 僅用於基本連線測試 |
| `TOOLS_NOTE/程式語言/PY vs C++`（Git 歷史） | [Python／C++ 語意比較](../development/programming/python-cpp-semantics.md) | **已清除** | 舊版對照非嚴格等價，已註明差異 |
| `TOOLS_NOTE/程式語言/C&C++/C&C++ note`（Git 歷史） | [C/C++ 語意陷阱](../development/programming/c-cpp-pitfalls.md) | **已清除** | 逐項補齊後刪除舊筆記 |
| `TOOLS_NOTE/程式語言/C&C++/TROUBLESHOOT`（Git 歷史） | [編譯故障](../development/build/compiler-toolchain-diagnostics.md) | **已清除** | 保留原版本線索 |
| `TOOLS_NOTE/程式語言/py note`（Git 歷史） | [Python 技術筆記](../development/programming/python.md) | **已清除** | 個人路徑泛化 |
| `TOOLS_NOTE/程式語言/python/`（Git 歷史） | [內建功能盤點](../development/programming/python-builtins-legacy.md)、[版本相容性](../development/programming/python-version-compatibility.md) | **已清除** | 原始清單與修正說明分開 |
| `TOOLS_NOTE/程式語言/shell語言/`（Git 歷史） | [Shell 腳本](../development/programming/shell-scripting.md)、[完整原始腳本](../development/programming/examples/getopt-conda-legacy.sh) | **已清除** | 原始 Bash 筆記已整理，腳本原文搬入正式領域 |
| `TOOLS_NOTE/作業系統/Linux note`（Git 歷史） | [Linux](../operating-systems/linux/README.md)、[Ubuntu 安裝注意事項](../operating-systems/installation/ubuntu.md)、[時間同步](../operations/time-synchronization.md)、[APT 查詢與升級](../development/package-management/apt.md)、[二進位診斷](../development/build/binary-diagnostics.md)、[媒體處理](../development/media-processing.md) | **已清除** | 依任務拆分，歷史命令未重驗 |
| `TOOLS_NOTE/作業系統/比較`（Git 歷史） | [作業系統比較](../operating-systems/comparison.md) | **已清除** | 更新 GPU 容器限制說明 |
| `TOOLS_NOTE/日誌/ELK`（Git 歷史） | [Filebeat 相容性](../operations/logging/filebeat-compatibility.md) | **已清除** | 保留原版本線索 |
| `TOOLS_NOTE/嵌入式平台/`（Git 歷史） | [嵌入式平台](../embedded-platforms/README.md) | **已清除** | K210、Raspberry Pi |
| `TOOLS_NOTE/週邊裝置/realsense`（Git 歷史） | [深度相機](../sensors/depth-cameras/realsense-backends.md) | **已清除** | 歷史源碼研究 |
| `TOOLS_NOTE/開發套件/ROS note`（Git 歷史） | [ROS1](../robotics/ros1/README.md)、[建置](../development/build/ros1-catkin-legacy.md)、[程序](../operations/ros1-process.md)、[日誌](../operations/logging/ros1-logging.md) | **已清除** | 原腳本及歷史版本線索，專案路徑僅供追溯 |
| `TOOLS_NOTE/常用工具`（Git 歷史） | [工具索引](../indexes/tools.md) | **已清除** | 依用途索引 |
| [開發日誌](../開發日誌/) | archive 或原位 | 待盤點 | 歷史紀錄不應改寫為現行規範 |

## TOOLS_NOTE 稽核紀錄

- 原始基準：[遷移前完整目錄](https://github.com/parameciumvance/parameciumvance_dev/tree/ebd91a8cb804609385b75955d3e4c712e39ab905/TOOLS_NOTE)，共 20 份檔案。
- 已重新讀取全部原始筆記，對照主要知識與歷史操作；補回 unsigned 說明、Shell PATH、Conda 初始化範例、NumPy 操作與 ROS 開發流程等細節。
- Python 內建盤點與 Shell 範例已確認包含完整原文。
- 第十二階段工作分支的 64 份非封存 Markdown 已掃描標準相對路徑目標，未發現不存在的目標；不包含外部連結、章節錨點或完整 Markdown 語法驗證。
- 尚未完成逐條驗收矩陣、外部來源查證及歷史環境實測；檔案遷移不等同技術驗證。

## 遷移準則

- **現行建議**：有可重用價值，整理到對應工程領域並標明推薦做法。
- **技術事實與研究**：整理到對應工程領域，標註版本與限制。
- **具體故障案例**：整理到對應工程領域，保留症狀、根因與解法，並加入故障索引。
- **過時但有參考價值**：保留必要的歷史情境與操作細節，完成遷移後清除舊副本。
- **尚未確認**：標記待驗證，不因整理而擅自提升為事實。

每次遷移應檢查內部連結、來源追溯與是否含敏感資料。
