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
