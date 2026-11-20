# C/C++ 常見語意與實作陷阱

> 來源：Git 歷史中的 `TOOLS_NOTE/程式語言/C&C++/C&C++ note`。原始提醒已逐項整理，並補充適用條件。

## const 與指標參數

函式若只讀取指標所指物件，宜在適用時以 `const T*` 表達不修改的介面契約，讓 `const` 物件也能傳入：

```cpp
void inspect(const Data* data);
```

`const T*` 限制的是透過該指標修改所指物件；不等於物件在其他地方永遠不會改變。

## assert 與 Release 組態

標準 C/C++ 的 `assert` 在定義 `NDEBUG` 時會被停用。**不可把必要的副作用放進 assert 表達式**：

```cpp
assert(compute()); // NDEBUG 定義時，compute() 不會執行
```

應改為先執行必要操作，再判斷結果：

```cpp
bool ok = compute();
assert(ok);
```

正式執行時仍必須處理的錯誤，不能只依靠 `assert`。

## switch／case 的局部變數

在 `case` 中宣告需要初始化的局部變數時，使用大括號建立明確作用域，避免控制流程跨越初始化：

```cpp
switch (mode) {
case 1: {
    int value = compute();
    use(value);
    break;
}
default:
    break;
}
```

## C++ 成員初始化順序

非靜態資料成員依**類別宣告順序**初始化，不依建構子初始化列表的書寫順序。

### 順序不一致，但初始化正確

```cpp
struct Example {
    int base;
    int result;
    Example() : result(base + 1), base(10) {}
};
```

實際先初始化 `base` 為 10，再初始化 `result` 為 11。此例沒有讀取尚未初始化的成員，但可能觸發 GCC／Clang 的 `-Wreorder` 警告。

### 真正有問題的宣告順序

```cpp
struct Example {
    int result;
    int base;
    Example() : base(10), result(base + 1) {}
};
```

即使初始化列表將 `base` 寫在前面，仍先初始化 `result`，此時讀取尚未初始化的 `base`，不能依賴其結果。

### 建議寫法

```cpp
struct Example {
    int base;
    int result;
    Example() : base(10), result(base + 1) {}
};
```

依相依關係安排成員宣告順序，讓被依賴的成員先初始化；初始化列表應與宣告順序一致，以提高可讀性並避免順序警告。真正決定初始化順序的是宣告，而非列表。

## signed／unsigned 混合運算

同位寬的無號整數可表達非負值且正值上限較大；但負數轉入時可能發生模數轉換，減法也可能回繞，不能因此省略輸入與界限檢查。

無號整數與有號整數混用時，會套用整數提升及一般算術轉換規則；負值不一定得到直覺結果：

```cpp
unsigned int x = 1;
auto y = -x; // 對無號型別運算，結果不是有號的 -1
```

原筆記提醒 `-uint(1)` 與 `-1 * uint(1)` 不應直接視為有號負一。比較、減法及界限檢查時，優先使用語意合適的型別並明確處理轉換。

## 平台相關標頭與延遲函式

原筆記記錄 `<unistd.h>`（POSIX）與 `<windows.h>`（Windows）是平台相關的標頭，並提到 `usleep`。`usleep` 並非標準 C++ 介面，跨平台 C++ 程式可依需求考慮 `<thread>` 的 `std::this_thread::sleep_for`，但仍需確認精度與即時性要求。

## 相關文件

- [Python 與 C++ 語意比較](python-cpp-semantics.md)
- [編譯與工具鏈故障](../build/compiler-toolchain-diagnostics.md)
