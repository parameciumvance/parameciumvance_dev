# 組態管理

背景參數應依作用域、型別、更新方式與生命週期選擇來源。

| 方式 | 優點與限制 |
| --- | --- |
| ROS1 rosparam | 支援命名空間與結構化值；同一 master 的 parameter server 可跨 launch 讀取，原筆記稱不能跨 launch，可能涉及私有命名空間或啟動順序，待驗證。 |
| 環境變數 | Bash 可 source 設定檔更新；值為字串，需解析，沒有原生階層；子程序繼承而非自動同步。 |
| YAML | 支援階層及型別，需解析器；Bash 或 launch 直接取值較不方便，但 ROS1 rosparam 可載入 YAML。 |

來源：開發/專案SOP（Git 歷史）。
