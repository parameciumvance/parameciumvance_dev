# ROS1／catkin 建置與依賴歷史案例

> **歷史經驗，未在現行環境重驗。** 來源：TOOLS_NOTE/開發套件/ROS note（Git 歷史）。原始案例涉及 ROS Melodic／Noetic、Ubuntu 18.04／20.04 與特定專案配置。

## 自行維護的套件與系統套件衝突

舊案例：同時存在系統安裝的 ROS 套件與自行編譯的同名套件，編譯時可能從系統路徑取得標頭或函式庫，造成版本不一致。

診斷時應檢查：
- 實際使用的 include、link 與 CMake 搜尋路徑；
- `find_package` 找到的套件與版本；
- 安裝前綴、overlay／workspace 的環境設定；
- 同名套件是否同時由系統套件管理器與原始碼提供。

舊筆記曾以移除官方套件、改用獨立安裝位置處理，但**不能未確認依賴關係就套用移除指令**。

舊案例具體為 my_A 與依賴 A 的 B 同時編譯，B 可能先找到 official_A；原筆記記錄 /opt/melodic/include 位於 catkin_INCLUDE_DIRS 前方、自編套件獨立安裝至 /opt/ros_pkgs，並研究 find_package(catkin COMPONENTS xxx) 合併 include 路徑的順序。標準 ROS 安裝常為 /opt/ros/melodic，原路徑為歷史記錄；實際順序依 CMake 及 overlay 配置。明確依賴路徑能否優先於間接依賴仍待研究。

## 產生的標頭檔缺失

舊案例涉及 dynamic_reconfigure 產生的標頭未在編譯目標前生成，筆記以目標依賴關係處理：

```cmake
add_dependencies(my_node ${${PROJECT_NAME}_EXPORTED_TARGETS})
```

原案例缺少 `<rpi_rover/RpiRoverConfig.h>`，target 為 rpi_rover_node。

這是特定 ROS1／catkin 專案的示意，實際需依專案的 target 與生成規則調整。

## 關聯

- [建置領域](README.md)
- [套件管理](../package-management/README.md)
- [工具索引](../../indexes/tools.md)
