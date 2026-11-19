# Python 技術筆記

> 來源：`TOOLS_NOTE/程式語言/py note`（Git 歷史）。內容分為一般概念與歷史環境問題。

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

## 操作與環境補充

- 常見影像副檔名：.jpg、.jpeg、.png；`cv2.imwrite("out.jpg", img)` 必須選擇支援的編碼器。
- Linux 可用 `whereis python` 查找位置；確認實際執行的 interpreter 宜用 `command -v python` 或 `python -c 'import sys; print(sys.executable)'`。
- 舊 VS Code debugger 曾將類別／模組方法顯示在 function variables；依偵錯器版本而異。
- 安裝名稱與 import 名稱：Pillow → PIL、PyTorch 官方 pip 套件 torch（舊筆記稱 pytorch，Conda 曾使用 pytorch）→ torch；tensorflow、numpy、keras 通常同名。
- pickle 不可載入不可信資料。

## NumPy／PyTorch 進階對照

| 任務 | NumPy | PyTorch |
| --- | --- | --- |
| 資料轉換 | `np.asarray(t)`／`t.numpy()` | `torch.as_tensor(a)`／`torch.from_numpy(a)` |
| 插入軸 | `x[:, np.newaxis, :]` | `x[:, None, :]` |
| HWC → CHW | `x.transpose(2,0,1)` | `x.permute(2,0,1)` 或 `x.transpose(1,2).transpose(0,1)` |
| 五個 (2,3) 沿軸 1 串接 → (2,15) | `np.concatenate(items, axis=1)`／`np.hstack(items)` | `torch.cat(items, dim=1)` |
| 五個 (2,3) 新軸 1 → (2,5,3) | `np.stack(items, axis=1)` | `torch.stack(items, dim=1)` |
| 改形 | `x.reshape(2,3)` | `x.reshape(2,3)`／符合 stride 條件時 `x.view(2,3)` |
| float32 | `x.astype(np.float32)` | `x.float()` |

`np.vstack` 沿垂直方向堆疊；不是 axis=1 的通用別名。轉換 tensor 到 NumPy 須注意 CPU、梯度、dtype 與共享記憶體，例如 `t.detach().cpu().numpy()`；from_numpy 僅接收 ndarray。max 預設 axis=None，不是 axis=0；maximum 是逐元素比較並支援 broadcasting。

原筆記的平面座標例：A = np.array([[1,2,3,8],[5,10,7,8]])，A.max()=10，np.argmax(A)=5；r=5//A.shape[1]、c=5%A.shape[1] 得 (1,1)，適用此二維 C-order 索引；通用方式為 unravel_index。

## 歷史故障操作

- maskrcnn-benchmark 的 `_C.cpython-37m-x86_64-linux-gnu.so: undefined symbol: _ZN2at18SparseCUDATensorIdEv`：舊筆記判斷 PyTorch 版本與編譯擴充時不同，當時移除該專案 build 產物，重新執行 setup.py 建置。應先確認 ABI、版本與建置流程，不盲目刪除目錄。
- CUDA out of memory：先嘗試降低 batch size，並檢查顯存占用。

## Conda 初始化歷史結構

舊 Bash 設定定義 conda_setup 函式：先執行安裝目錄 bin/conda shell.bash hook（stderr 重導至 /dev/null），成功時 eval 其輸出；失敗則 source etc/profile.d/conda.sh，若不存在便將 bin 加入 PATH，最後 unset __conda_setup。原片段只定義函式，未顯示呼叫；不應直接當成完整初始化腳本。個人絕對路徑已泛化。建議使用 conda init bash 產生對應安裝版本的配置，腳本用法見 [Shell 腳本](shell-scripting.md)。
