# Python 與 C++：語意與常見操作比較

> 來源：`TOOLS_NOTE/程式語言/PY vs C++`（Git 歷史）。原筆記主要是語法速查，這裡優先釐清容易造成錯誤類比的語意。

## 名稱、物件與複製

舊筆記以 `a = b` 對照 `int& a = b`，以 `a = b.copy()` 對照 `int a = b`。這有助於記憶部分情境，但**不是一般性的語意等價關係**。

Python 的賦值通常是將名稱綁定到物件，並不自動複製物件：

```python
a = [1, 2]
b = a
b.append(3)
assert a == [1, 2, 3]
```

若需要獨立的列表，可用 `a.copy()` 建立**淺複製**；巢狀可變物件仍可能共享。需要遞迴複製時，視情況使用 `copy.deepcopy`。

C++ 的 `int& a = b;` 是對現有物件建立參考；`int a = b;` 對整數型別建立另一個值。對自訂類別，複製、移動、參考及擁有權由型別與運算決定，不能直接以 Python 的 `.copy()` 類比。

## 條件分支

| Python | C++ |
| --- | --- |
| `if condition:` | `if (condition) { ... }` |
| `elif condition:` | `else if (condition) { ... }` |
| `else:` | `else { ... }` |

Python 使用縮排界定區塊；C++ 常用大括號，語句通常以分號結束。

## 輸入輸出

| 任務 | Python | C++ |
| --- | --- | --- |
| 輸出文字 | `print("msg")` | `std::cout << "msg";` |
| 讀取輸入 | `input("msg")` | `std::getline(std::cin, s);` |
| 檔案操作 | `open(...)` | `std::ifstream`／`std::ofstream` |

`input()` 讀回字串；C++ `std::cin >> value` 則依變數型別進行格式化讀取，兩者並不完全等價。

## 模組與標準函式庫

原筆記將 Python `math`、`time`、`random` 與 C++ 的 `<cmath>`、`<ctime>`、`<cstdlib>` 等對照。這些只能視為**功能相近的查找線索**，不能假設 API、隨機性、時區處理或數值語意相同。

例如 C++ 的亂數生成通常使用 `<random>`，而非將 Python `random` 直接等同 `<cstdlib>`。

## 延伸閱讀

- [Python 技術筆記](python.md)
- [程式設計領域](README.md)

## 型別轉換與函式庫速查補充

Python `int(x)`、`float(x)` 可解析字串或轉換數值；C++ `static_cast<int>(x)`、`static_cast<float>(x)` 主要用於允許的型別轉換，字串解析另用 `std::stoi`、`std::stof` 等。Python `help()` 提供執行期說明，C++ 無直接對等內建函式。

| Python | C++ 功能查找線索（非等價） |
| --- | --- |
| `sys` | 依需求使用標準函式庫或平台 API |
| `input`、`print` | `<iostream>` |
| `io` | `<fstream>`、`<sstream>` |
| `str` | `<string>`、`<cstring>`、`<cctype>`（字元分類） |
| `str.format` | `<iomanip>`、C++20 `<format>` |
| `os.system`、`os.execv` | `<cstdlib>` 的 `std::system`；execv 是 POSIX API，非等價操作 |
| `math`、`cmath` | `<cmath>`、`<complex>` |
| `time`、`datetime` | `<ctime>`、`<chrono>` |
| `random`、`os.urandom` | `<random>`、平台安全亂數 API；不能以普通 PRNG 取代安全亂數 |
| `os`（posix/nt） | `<filesystem>`、平台 API；舊筆記的 `<direct.h>` 為 Windows 特定標頭 |
| `struct` | 明確處理二進位序列化、大小與位元組序 |

舊筆記另列 `_random`、`_struct`、`_datetime`，屬實作相關模組線索，不宜作為可攜公共 API。
