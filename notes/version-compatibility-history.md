# 歷史版本相容性筆記

> **歷史紀錄，非現行安裝建議。** 來源：[開發/版本更新](../開發/版本更新)。原始筆記未完整記錄作業系統、套件來源、硬體與重現步驟；以下僅保留待驗證線索。

| 技術組合／情境 | 舊筆記內容 | 解讀與後續 |
| --- | --- | --- |
| Ubuntu 18.04 / Dockerfile | 提及 `DEBIAN_FRONTEND=noninteractive` | 僅是非互動安裝情境的設定線索，不代表所有 Dockerfile 都需要 |
| Python 3.9 / Ubuntu 20.04 | 舊環境搭配建議 | 不應視為目前版本支援矩陣 |
| protobuf 4.25 / Caffe | 曾記錄衝突 | 需確認實際套件版本與錯誤 |
| NumPy 1.26.1 | 曾記錄 `numpy_stack` 問題 | 缺少重現資訊，待查 |
| Python 3.8 / TensorFlow 2.x | 舊升級紀錄 | 需依目標 TensorFlow 版本確認支援 |
| Python 3.6 / 舊 pip | 曾遭遇套件解析／安裝問題 | Python 3.6 已屬歷史環境，避免直接套用升級指令 |
| OpenCV 4.7.0.72 / 4.8.0 | 舊筆記提及 CUDA 與 `cv2/py.typed` 相關建置錯誤 | 需區分 pip 套件、原始碼編譯與 CUDA 支援 |
| TensorFlow 1.x / 2.5.3 | 記錄 Python 與 NumPy 相容性限制 | 必須依特定版本官方相容表確認 |

## 版本相容性問題的建議記錄欄位

- OS 與架構、Python／編譯器版本
- 套件完整版本及安裝來源（pip、conda、apt、source build）
- GPU、CUDA、驅動及相關工具鏈（如適用）
- 錯誤訊息、最小重現步驟
- 已驗證的解法及適用範圍
- 驗證日期、參考連結

## 提醒

不要將「一律升級 pip」、「某版 Ubuntu 必須配某版 Python」等歷史個案寫成跨環境通則。優先以目標專案的 lockfile、相容性矩陣與實際測試為依據。
