# Python 技術筆記

> 來源：`TOOLS_NOTE/程式語言/py note`（Git 歷史）。內容分為一般概念與歷史環境問題。

## 常見語言與工具行為

- `argparse`：長選項推導預設 dest 時，連字號轉底線，例如 `--output-dir` 對應 `args.output_dir`；可用 dest 自訂，並非所有引數字串都轉換。
- `__slots__`：限制實例可新增的屬性；需留意繼承及是否仍存在 `__dict__`。
- `pickle`：可透過 `__getstate__`／`__setstate__` 客製序列化；區域函式與類別通常無法直接以標準 pickle 序列化。不可載入不可信資料。

## Python 環境與偵錯

- Linux 可用 `whereis python` 查找位置；確認實際執行的 interpreter 宜用 `command -v python` 或 `python -c 'import sys; print(sys.executable)'`。
- 舊 VS Code debugger 曾將類別／模組方法顯示在 function variables；依偵錯器版本而異，尚未重新驗證。
- 安裝名稱與 import 名稱：Pillow → PIL、PyTorch 官方 pip 套件 torch（舊筆記稱 pytorch，Conda 曾使用 pytorch）→ torch；tensorflow、numpy、keras 通常同名。

## 影像處理

- 常見影像副檔名：`.jpg`、`.jpeg`、`.png`。
- OpenCV 常用 BGR 通道順序，Pillow／Matplotlib 的彩色影像常用 RGB；跨套件時確認通道順序。
- `cv2.imwrite(filename, img)` 的 filename 須含支援的副檔名，例如 `cv2.imwrite("out.jpg", img)`，以選擇影像編碼器。

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

## NumPy／PyTorch 對照

| 任務 | NumPy | PyTorch |
| --- | --- | --- |
| Tensor → ndarray／ndarray → Tensor | `t.detach().cpu().numpy()` | `torch.from_numpy(a)`／`torch.as_tensor(a)` |
| 插入軸 | `np.expand_dims(x, axis=1)`／`x[:, np.newaxis, :]` | `x.unsqueeze(1)`／`x[:, None, :]` |
| HWC → CHW | `x.transpose(2,0,1)` | `x.permute(2,0,1)` 或 `x.transpose(1,2).transpose(0,1)` |
| 五個 (2,3) 沿軸 1 串接 → (2,15) | `np.concatenate(items, axis=1)`／`np.hstack(items)` | `torch.cat(items, dim=1)` |
| 五個 (2,3) 新軸 1 → (2,5,3) | `np.stack(items, axis=1)` | `torch.stack(items, dim=1)` |
| 改形 | `x.reshape(2,3)` | `x.reshape(2,3)`／符合 stride 條件時 `x.view(2,3)` |
| 限制值域 | `np.clip(x, low, high)` | `torch.clamp(x, low, high)` |
| float32 | `x.astype(np.float32)` | `x.float()` |

`np.vstack` 沿垂直方向堆疊；不是 axis=1 的通用別名。轉換 tensor 到 NumPy 須注意 CPU、梯度、dtype 與共享記憶體，例如 `t.detach().cpu().numpy()`；from_numpy 僅接收 ndarray。max 預設 axis=None，不是 axis=0；maximum 是逐元素比較並支援 broadcasting。

原筆記的平面座標例：A = np.array([[1,2,3,8],[5,10,7,8]])，A.max()=10，np.argmax(A)=5；r=5//A.shape[1]、c=5%A.shape[1] 得 (1,1)，適用此二維 C-order 索引；通用方式為 unravel_index。

## 歷史故障操作

依實際版本、錯誤訊息與環境重現，不直接套用舊解法。

- maskrcnn-benchmark 的 `_C.cpython-37m-x86_64-linux-gnu.so: undefined symbol: _ZN2at18SparseCUDATensorIdEv`：舊筆記判斷 PyTorch 版本與編譯擴充時不同，當時移除該專案 build 產物，重新執行 setup.py 建置。應先確認 ABI、版本與建置流程，不盲目刪除目錄。
- CUDA out of memory：先嘗試降低 batch size，並檢查顯存占用。

## Conda 初始化歷史結構

舊 Bash 設定定義 conda_setup 函式：先執行安裝目錄 bin/conda shell.bash hook（stderr 重導至 /dev/null），成功時 eval 其輸出；失敗則 source etc/profile.d/conda.sh，若不存在便將 bin 加入 PATH，最後 unset __conda_setup。原片段只定義函式，未顯示呼叫；不應直接當成完整初始化腳本。個人絕對路徑已泛化。建議使用 conda init bash 產生對應安裝版本的配置，腳本用法見 [Shell 腳本](shell-scripting.md)。
