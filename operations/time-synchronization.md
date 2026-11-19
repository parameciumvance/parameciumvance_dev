# 系統時間同步

## 狀態檢查

```bash
timedatectl
systemctl status systemd-timesyncd.service
service ntp status
```

依系統實際使用的 NTP daemon 選擇命令，避免同時啟用互相競爭的服務。

## 主板／副板歷史案例

舊設備主板操作（未重新驗證）：

```bash
sudo timedatectl set-ntp false
sudo apt install ntp
sudo timedatectl set-ntp true
```

舊筆記另在 /etc/init/main 加入 `service ntp restart`。此為特定設備啟動配置，不是通用 systemd 設定；set-ntp true 亦不保證選中 ntp daemon。主板若要提供 NTP 服務，還須設定允許用戶端查詢、網路與防火牆。

副板 /etc/systemd/timesyncd.conf 原始設定：

```ini
[Time]
NTP=rover-1
#FallbackNTP=ntp.ubuntu.com
#RootDistanceMaxSec=5
#PollIntervalMinSec=32
#PollIntervalMaxSec=2048
```

執行 `systemctl restart systemd-timesyncd.service`（需要適當權限）。確認 rover-1 能解析並提供 NTP；註解項目不會覆寫配置。歷史設備名稱保留供追溯，實際部署應替換。

來源：TOOLS_NOTE/作業系統/Linux note（Git 歷史）。
