# 媒體處理

## FFmpeg 影片取樣為影像

```bash
ffmpeg -i input.mp4 -r 10 -f image2 foo-%05d.jpg
```

原筆記的 10(fps) 表示每秒 10 幀，不是命令參數字面值。輸出以五位序號命名；若要明確按時間取樣，也可使用 `ffmpeg -i input.mp4 -vf fps=10 foo-%05d.jpg`。調整輸出幀率可能丟棄或重複影格。

來源：TOOLS_NOTE/作業系統/Linux note（Git 歷史）。
