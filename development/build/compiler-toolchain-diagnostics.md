# 編譯與工具鏈故障排查

> 來源：[舊 C/C++ 編譯故障筆記](../../TOOLS_NOTE/程式語言/C%26C%2B%2B/TROUBLESHOOT)。部分內容屬舊版 GCC／CUDA 經驗，需按實際版本驗證。

## 排查順序

1. 確認編譯器、連結器、建置系統與實際執行的命令及版本。
2. 確認原始碼與相依套件完整，包含 Git submodule。
3. 檢查標頭搜尋路徑、函式庫路徑、編譯旗標與語言標準。
4. 檢查路徑中是否包含空白、括號或非 ASCII 字元，以及是否正確引用。
5. 比對工具鏈與 SDK 的支援矩陣，不只看編譯器版本號。

## 子模組未取得

舊專案若以 submodule 管理依賴，可檢查：

```bash
git submodule status
git submodule update --init --recursive
```

初次 clone 時也可使用 `git clone --recurse-submodules`。**不是所有倉庫都使用 submodule**，應先確認。

## C 函式庫與 C++ 連結

C++ 程式引用 C API 時，標頭可能需要以 `extern "C"` 指定 C 語言連結方式，以避免名稱修飾不一致：

```cpp
#ifdef __cplusplus
extern "C" {
#endif
#include "c_library.h"
#ifdef __cplusplus
}
#endif
```

實際是否需要由函式庫標頭是否已自行處理 `__cplusplus` 決定；不要對 C++ API 任意套用。

## GCC／CUDA 相容性（歷史案例）

舊筆記記錄 CUDA 10.0 的 `nvcc` 對 GCC 主機編譯器版本有限制，當時提及 GCC 7 或更早版本。這是**特定歷史工具鏈**的相容性經驗，不代表新版本 CUDA 的規則。遇到 `unsupported GNU version` 等訊息，應以所用 CUDA Toolkit 官方支援表與安裝的標頭檢查為準。

## 其他舊案例

- `not declared`：先確認缺失宣告、標頭、命名空間與 C/C++ 標準；不應一律歸因於 GCC 升級。
- 安裝到系統目錄時可能需要權限：優先使用合適安裝前綴，避免無條件以 `sudo` 編譯。
- 文字路徑中的中文、空白或括號：可能暴露舊建置腳本引用或跳脫不足，應檢查命令而非認定所有工具都不支援。

## 相關領域

- [建置](README.md)
- [版本控制](../version-control/README.md)
