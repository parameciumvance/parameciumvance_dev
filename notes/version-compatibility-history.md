# 版本相容性問題的記錄方式

歷史案例已按領域整合至 [Python 與科學運算套件版本相容性](../development/programming/python-version-compatibility.md) 及 [容器建置](../development/build/container-build.md)。

## 版本相容性問題的建議記錄欄位

- OS 與架構、Python／編譯器版本
- 套件完整版本及安裝來源（pip、conda、apt、source build）
- GPU、CUDA、驅動及相關工具鏈（如適用）
- 錯誤訊息、最小重現步驟
- 已驗證的解法及適用範圍
- 驗證日期、參考連結

## 提醒

不要將「一律升級 pip」、「某版 Ubuntu 必須配某版 Python」等歷史個案寫成跨環境通則。優先以目標專案的 lockfile、相容性矩陣與實際測試為依據。
