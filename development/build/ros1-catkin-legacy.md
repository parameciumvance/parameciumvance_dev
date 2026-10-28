# ROS1／catkin 建置與依賴歷史案例

> **歷史經驗，未在現行環境重驗。** 來源：[舊 ROS 筆記](../../TOOLS_NOTE/開發套件/ROS%20note)。原始案例涉及 ROS Melodic／Noetic、Ubuntu 18.04／20.04 與特定專案配置。

## 自行維護的套件與系統套件衝突

舊案例：同時存在系統安裝的 ROS 套件與自行編譯的同名套件，編譯時可能從系統路徑取得標頭或函式庫，造成版本不一致。

診斷時應檢查：
- 實際使用的 include、link 與 CMake 搜尋路徑；
- `find_package` 找到的套件與版本；
- 安裝前綴、overlay／workspace 的環境設定；
- 同名套件是否同時由系統套件管理器與原始碼提供。

舊筆記曾以移除官方套件、改用獨立安裝位置處理，但**不能未確認依賴關係就套用移除指令**。

## 產生的標頭檔缺失

舊案例涉及 dynamic_reconfigure 產生的標頭未在編譯目標前生成，筆記以目標依賴關係處理：

```cmake
add_dependencies(my_node ${${PROJECT_NAME}_EXPORTED_TARGETS})
```

這是特定 ROS1／catkin 專案的示意，實際需依專案的 target 與生成規則調整。

## 關聯

- [建置領域](README.md)
- [套件管理](../package-management/README.md)
- [工具索引](../../indexes/tools.md)
