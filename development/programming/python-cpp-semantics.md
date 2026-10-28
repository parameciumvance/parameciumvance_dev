# Python 與 C++：語意與常見操作比較

> 來源：[舊 Python／C++ 對照筆記](../../TOOLS_NOTE/程式語言/PY%20vs%20C%2B%2B)。原筆記主要是語法速查，這裡優先釐清容易造成錯誤類比的語意。

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
