# 二進位診斷與 CPU 指令集

| 命令 | 用途 |
| --- | --- |
| `readelf -d file` | ELF 動態資訊，如 RUNPATH |
| `ldd file` | 動態函式庫相依；勿對不可信執行檔執行 |
| `objdump -t file` | 符號表 |
| `objdump -T file` | 動態符號表 |
| `nm file` | 符號表 |

## GCC 目標 CPU 特徵

```bash
gcc -march=native -dM -E - < /dev/null | egrep "SSE|AVX" | sort
```

此舊指令查詢 GCC 在本機目標選項下定義的 SSE／AVX 巨集，不是通用的硬體能力偵測，也不代表交叉編譯目標能力。部署至不同 CPU 時須選適當架構旗標。

來源：TOOLS_NOTE/作業系統/Linux note（Git 歷史）。
