# Python 與科學運算套件版本相容性

## Python 2 → 3

- print 改為函式；zip、map 回傳 iterator 而非 list，也不是 generator；需要實體列表時使用 list(zip(...))、list(map(...))。
- `format(obj, '>20')` 是否支援取決於 `__format__`；一般 object 預設只支援空格式，必要時 `format(str(obj), '>20')`。冒號屬 f-string／format replacement field 語法，不是 format() 的格式參數前綴。
- Python 2 unicode 對應 Python 3 str；舊 str 的二進位用途通常改 bytes，文字用途則 str。使用 encode/decode 明確轉換；basestring 的替代取決於是否也接受 bytes；dict.iteritems() 改 dict.items()（view）。
- 讀取 Python 2 pickle 時可能使用 encoding='utf-8' 或 'bytes'（原筆記為讀圖案例），取決於原始資料編碼；僅載入可信 pickle。

## 科學運算套件歷史案例

- NumPy：讀取物件陣列可能需要 `np.load(..., allow_pickle=True)`，僅適用可信來源。
- TensorFlow：舊 0.12 時期 tf.split 參數順序變動，現行常見為 `tf.split(value, num_or_size_splits, axis=...)`；精確版本分界待核對。TF2 移除 tf.contrib，參見 https://github.com/tensorflow/community/blob/master/rfcs/20180907-contrib-sunset.md 。
- SciPy：舊 misc.imread／imresize 在 1.2 移除的紀錄，替代為 imageio.imread、skimage.transform.resize；注意 dtype、值域與插值差異。
- PyTorch：舊筆記記錄 1.7 tensor 迭代 grad_fn 從 selectBackward 變 unbindBackward，並遇到 inplace 限制；可能涉及多 view 輸出與 autograd，不視為已確認退化。1.6 的 torch.onnx.utils._model_to_graph node repr 改變影響 mmdnn；私有 API 非穩定契約。2021-02-18 記錄 torch<1.6 QAT 訓練與偵測異常，缺重現條件，待驗證。

## Python 環境升降版歷史案例

以下來自開發/版本更新（Git 歷史），缺少重現條件，不是支援矩陣。

- Python 3.9：舊建議 Ubuntu 20.04；protobuf 4.25 與 Caffe 衝突、NumPy 1.26.1 的 `numpy_stack` 問題（原文名稱，未確認實際 API 或錯誤）。
- Python 3.8：舊建議 Ubuntu 20.04、TensorFlow 2.x；Python 3.6 則曾建議 Ubuntu 18.04。
- Ubuntu 16.04 pip 8.1 曾安裝失敗，舊解法 `python -m pip install --upgrade pip`；pip 10.0.1 曾為 Python 3.6.5 選到不相容 protobuf 4.21.0。原建議一律升級 pip 不宜套用，須選擇仍支援目標 Python 的 pip 版本並隔離環境。
- TensorFlow 1.x 舊降版建議 Python 3.7；TensorFlow 2.5.3 曾記錄 NumPy 1.19 限制。應查具體版本的套件 metadata，不代表整個系列均相容。
- OpenCV：舊建議 opencv==4.7.0.72，4.8.0 曾與 CUDA 相關環境衝突，錯誤 `File "setup.py" line 448 in _classify_installed_files_override`、`Exception: Not found: 'python/cv2/py.typed'`。實際 pip 套件名可能為 opencv-python，需區分 wheel、source build 與 CUDA 版本，根因未確認。

## 原始版本筆記（歷史快照，未重新驗證）

```text

print

zip/map now returns generator rather than list
zip(x)/map(x) -> list(zip(x))/list(map(x))

format(object,':>20') -> format(str(object),':>20') 
obj直接格式化只接受空字串 i.e. format(object,'')

bytes vs str -> decode/encode
basestring -> str or bytes
unicode -> str
str -> bytes

dict.iteritems -> dict.items

encoding="utf-8" / "bytes"(pickle讀圖)


-----------numpy-------------


allow_pickle=True


-----------tensorflow-------------

tf.split(axis, num_or_size_splits, value) version<=0.12
tf.split(value, num_or_size_splits, axis) version>0.12

TF2
no tf.contrib (https://github.com/tensorflow/community/blob/master/rfcs/20180907-contrib-sunset.md)

------------scipy-----------------
scipy.misc.imread 在1.2移除,用imageio.imread代替
scipy.misc.imresize 在1.2移除,用skimage.transform.resize代替

------------torch-----------------
"for t_i in t:" t_i的gradfn從selectBackward變為unbindBackward (ver1.7)
不能對t_i做inplace操作...（退化？？理由待研究）

torch 1.6行為改變 torch.onnx.utils._model_to_graph回傳node的repr改變(影響mmdnn)

torch<1.6在qat訓練和偵測會有異常出現(20210218)
```
