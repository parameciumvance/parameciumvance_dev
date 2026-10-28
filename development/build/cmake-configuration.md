# CMake 建置組態

> 來源：[舊 CMake 筆記](../../開發/CMAKE%20note)。原始內容簡短，以下補充語意及適用限制。

## 組態與編譯旗標

CMake 常見的 `Debug`、`Release` 組態會影響最佳化與除錯設定。舊筆記提及 Release 的 `-O3 -DNDEBUG`、Debug 的 `-g`；**這不是跨編譯器、跨專案保證的固定預設**，實際旗標依 CMake、工具鏈、平台與專案覆寫設定而異。

可以查詢專案的 CMake cache、實際編譯命令或工具鏈設定確認生效選項。

## 在來源目錄外建置

```bash
cmake -S . -B build
cmake --build build
```

`-S` 與 `-B` 為較新版本 CMake 的明確來源／建置目錄選項。舊版 CMake 可改為：

```bash
mkdir -p build
cd build
cmake ..
cmake --build .
```

舊筆記將 `cmake -B build` 與 Ubuntu 20.04／CMake 3.16 綁定，應理解為當時環境的使用經驗，不是以 Ubuntu 發行版決定語法的通用規則。

## 相關資料

- [ROS1／catkin 建置歷史案例](ros1-catkin-legacy.md)
