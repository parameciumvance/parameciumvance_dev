# Python 技術筆記

> 來源：[舊版 Python 筆記](../../TOOLS_NOTE/程式語言/py%20note)。內容分為一般概念與歷史環境問題。

## 常見語言與工具行為

- `argparse`：選項名稱中的連字號通常轉為屬性名稱的底線，例如 `--output-dir` 對應 `args.output_dir`。
- `__slots__`：可限制實例的屬性配置方式，但需留意繼承與 `__dict__` 的情況。
- `pickle`：可透過 `__getstate__`／`__setstate__` 客製序列化；區域函式與類別通常無法直接以標準 pickle 序列化。
- 影像色彩：OpenCV 常用 BGR 通道順序，Pillow／Matplotlib 常用 RGB，跨套件時應確認色彩通道。
- `cv2.imwrite`：檔名副檔名通常用於選擇影像編碼器。

## NumPy 常用操作

```python
import numpy as np

a = np.array([-2, -1, 0, 1, 2])
np.max(a)                  # 單一最大值
np.maximum(a, 0)           # 逐元素與 0 取最大
np.clip(a, 0, 1)           # 限制範圍

matrix = np.array([[1, 2, 3], [4, 9, 6]])
row, col = np.unravel_index(np.argmax(matrix), matrix.shape)
```

## NumPy 與 PyTorch 對照

| 目的 | NumPy | PyTorch |
| --- | --- | --- |
| 增加維度 | `np.expand_dims(x, axis=1)` | `x.unsqueeze(1)` |
| 調整軸順序 | `x.transpose(2, 0, 1)` | `x.permute(2, 0, 1)` |
| 沿既有軸串接 | `np.concatenate(items, axis=1)` | `torch.cat(items, dim=1)` |
| 建立新軸堆疊 | `np.stack(items, axis=1)` | `torch.stack(items, dim=1)` |
| 限制值域 | `np.clip(x, low, high)` | `torch.clamp(x, low, high)` |

注意 NumPy 使用 `axis`，PyTorch 許多對應 API 使用 `dim`；`reshape` 與 `view` 的記憶體布局限制也可能不同。

## 舊環境故障線索

原筆記記錄 PyTorch／CUDA 編譯擴充模組版本不一致，以及 GPU 記憶體不足等問題。這些情況需依實際版本、錯誤訊息與環境重現，不能直接套用舊解法。舊筆記中的個人絕對路徑不應複製到通用操作指南。
