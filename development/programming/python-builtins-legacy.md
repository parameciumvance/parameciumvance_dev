# Python 語言與內建功能：歷史盤點

原始盤點未標明 Python 版本；內部模組相依關係不是公共 API 契約。下方原文為歷史快照，不是現行完整清單。

## 使用前的修正

- 三引號是字串常值，不是多行註解；特定位置才是 docstring。Python 3 仍接受 `u` 字串前綴（3.3 起重新支援）。
- `>`／`>=` 對應 `__gt__`／`__ge__`，原文誤寫為 `<`／`<=`。二元與比較運算還涉及反向方法、子類優先及 NotImplemented；`+=` 可 fallback 到普通二元運算。
- `__getitem__`、`__setitem__`、`__delitem__` 接收索引物件本身；並非一律呼叫 `__index__`，例如 dict 的字串鍵與 slice。
- 一般屬性查找使用 `__getattribute__`，`__getattr__` 是找不到屬性時的 fallback。屬性名稱參數是字串。
- `with` 的 `__exit__` 也處理例外；可抑制例外。`print` 使用字串表示但並非單純等價於原文所有情境的呼叫。
- `__all__` 主要控制 `from mod import *`，不限制一般明確 import。
- 單底線是慣例，雙前綴底線可能 name mangling，不是安全存取限制；dunder 方法有特殊協定。
- 原文 `global(os,re,fnmatch)` 疑為 `glob`；global 是關鍵字。標準庫模組可能隨版本移除，例如 parser、audioop；以目標 Python 版本官方文件為準。
- `__name__` 等通常是模組屬性，不應一律視為 builtins；quit、exit、help 等可由 site 提供，非所有執行環境可用。

## 原始盤點全文（未驗證）

```text
關鍵字
and or not is in
True False None
if elif else pass
for while break continue
def return yield lambda
class
from import as with
try except finally assert raise 

                
global del async  await nonlocal

                                

符號
+a      a.__pos__()
-a      a.__neg__()
~a      a.__invert__()

a+b     a.__add__(b)
a-b     a.__sub__(b)
a*b     a.__mul__(b)
a@b     a.__matmul__(b)
a/b     a.__truediv__(b)
a//b    a.__floordiv__(b)
a%b     a.__mod__(b)
a**b    a.__pow__(b)
a<<b    a.__lshift__(b)
a>>b    a.__rshift__(b)
a&b     a.__and__(b)
a^b     a.__xor__(b)
a|b     a.__or__(b)

  a+b     若a.__add__(b)回傳NotImplemented 則 b.__radd__(a) 
  a+=b    a.__iadd__(b)

a==b    a.__eq__(b)
a!=b    a.__ne__(b)
a<b     a.__lt__(b)
a<=b    a.__le__(b)
a<b     a.__gt__(b)
a<=b    a.__ge__(b)

a(b)    a.__call__(b)

a[b]=c  a.__setitem__(b.__index__(),c)
a[b]    a.__getitem__(b.__index__())
del a[b] a.__delitem__(b.__index__())


a.b=c   a.__setattr__(b,c)
a.b     a.__getattr__(b)
del a.b  a.__delattr__(b)

_ __ 標示符(private 魔法方法)
:     block(if for while def class with)
已移除  <>(!=)   `(repr)   u' u"(All strings are unicode strings in Python 3)


'''   """  多行註解

'     "
b'    b"
f'    f"
r'    r"

,      
...(Ellipsis)        
j J (虛數)        
\        


len(a)  a.__len__()
str(a)  a.__str__()     ps. print(a) 就是 print(str(a)
repr(a) a.__repr__()  ps. cmd>>a 顯示 repr(a)
iter(a) a.__iter__()
next(a) a.__next__()

with a: dosomething       a.__enter__()  dosomething  a.__exit__()

from mod import X (requires X in mod.__all__ if mod.__all__ is defined)

純算法
_bisect
_operator
_heapq

標準庫
sys
math,cmath(cmath可處理複數)
    builtins
    keyword
    _struct struct (bytes結構)  
    itertools
    _contextvars=contextvars 
    _thread
    _warnings warnings(sys){linecache tracemalloc re traceback}
    types(sys)
    enum(sys types)
    _codecs codecs(sys)
    encodings(sys codecs)
    _abc/_py_abc abc _collections_abc(sys abc)  
    numbers(abc)
    _weakref _weakrefset weakref(sys _collections_abc itertools)
    reprlib(itertools _thread)
    _collections collections(sys _collections_abc operator keyword heapq _weakref reprlib itertools)
    _functools functools(abc collections reprlib _thread)    
    
time[.localtime .gmtime]
zlib


_sre   re (enum functools) sre_compile(_sre) sre_parse sre_constants
posix/nt  _stat=stat os(sys abc _collections_abc stat) genericpath(os) posixpath/ntpath(os genericpath)
_locale locale(_locale sys encodings re _collections_abc functools)

_random[.getrandbits .random] random(warnings os bisect)
_ctypes ctypes(sys os struct) c互動

_socket 網路插座
_io (open()) 檔案存取 io(abc)


_md5 _sha系列（hashlib） 密碼雜湊




tokenize(sys re codecs collections io itertools) token
linecache (sys os functools tokenize)
traceback(sys linecache _collections itertools)


threading(_thread sys os time traceback itertools collections _weakrefset)





高階
_datetime=datetime(time,math)
_string string(re collections)

fnmatch(os re functools)
global(os,re,fnmatch)
shutil(sys,os,fnmatch,zlib,bz2,lzma,pwd,grp)

gettext(sys,os,re,locale) 翻譯
argparse(sys.argv,os,re,shutil,gettext)

_pydecimal(sys math numbers contextvars re){locale collections itertools}=decimal
fractions(sys math numbers operator re decimal)
statistics(math numbers operator bisect collections itertools random fractions decimal)

_pickle (高階_io)


urllib(sys warnings time bisect contextlib os re io hashlib socket http ?base64 email string tempfile){ssl mimetypes ftplib  fnmatch getpass _scproxy nturl2path winreg}

三方
setuptools(distutils)
PyQt5 gi.PyGTK (GUI)
matplotlib (繪圖GUI)



urllib3
requests(urllib3)

numpy
cv2(numpy)
PIL

scipy
skimage

yacs
h5py[hdf5] lmdb leveldb
tqdm

torch
torchvision
tensorflow-gpu tensorflow
keras



-------------------------------
_codecs_cn/jp/tw/hk/kr/iso2022
_imp                
gc
_ast                                    

_json               
_csv
marshal
_blake2             
_symtable
_lsprof             
mmap
_tracemalloc        
_multibytecodec     
_opcode             
parser
array               
atexit              
audioop             
xxsubtype
        
binascii            
zipimport
errno
faulthandler

Windows專用
_winapi  winreg  msvcrt

Unix專用
fcntl  grp  pwd  spwd  syslog 


__builtins__
--------------------
__name__
__doc__
__package__
__loader__
__spec__
__build_class__
__import__

isinstance
callable
type
issubclass

print input

int float complex bool 
ord chr str format

tuple list dict set

None False True

map zip range sorted len enumerate filter

iter next

object super NotImplemented

abs max min sum pow round divmod

all any


bin oct hex


repr ascii eval exec compile




dir
getattr
setattr
hasattr
delattr

hash
id
globals
locals
vars
Ellipsis
memoryview
bytearray
bytes
classmethod
staticmethod
property
reversed
slice
frozenset
__debug__
BaseException
Exception
TypeError
StopAsyncIteration
StopIteration
GeneratorExit
SystemExit
KeyboardInterrupt

ImportError
ModuleNotFoundError
OSError
EnvironmentError
IOError
EOFError
RuntimeError
RecursionError
NotImplementedError
NameError
UnboundLocalError
AttributeError
SyntaxError
IndentationError
TabError
LookupError
IndexError
KeyError
ValueError
UnicodeError
UnicodeEncodeError
UnicodeDecodeError
UnicodeTranslateError
AssertionError
ArithmeticError
FloatingPointError
OverflowError
ZeroDivisionError
SystemError
ReferenceError
BufferError
MemoryError

Warning
UserWarning
DeprecationWarning
PendingDeprecationWarning
SyntaxWarning
RuntimeWarning
FutureWarning
ImportWarning
UnicodeWarning
BytesWarning
ResourceWarning

ConnectionError
BlockingIOError
BrokenPipeError
ChildProcessError
ConnectionAbortedError
ConnectionRefusedError
ConnectionResetError
FileExistsError
FileNotFoundError
IsADirectoryError
NotADirectoryError
InterruptedError
PermissionError
ProcessLookupError
TimeoutError

open
quit
exit
copyright
credits
license
help
```
