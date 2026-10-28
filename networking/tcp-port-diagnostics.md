# TCP 連接埠可達性檢查

> 來源：[舊網路筆記](../TOOLS_NOTE/網路)。原筆記以 Telnet 測試連接埠，此處整理為通用診斷方法。

## 要回答的問題

指定主機的 TCP 連接埠是否可從目前電腦建立連線？

先區分三件事：
1. DNS 是否能將主機名稱解析為預期位址。
2. TCP 連線是否能建立。
3. 目標應用程式協定是否真的正常運作。

**TCP 連得上不等於應用服務健康**；TCP 連不上也不一定代表服務停止，可能是路由、防火牆、存取控制或代理設定問題。

## 常用檢查方式

### Windows PowerShell

```powershell
Test-NetConnection example.com -Port 443
```

觀察 `TcpTestSucceeded`，並留意解析到的 IP、介面與路由。

### Linux／WSL

有 netcat 時：

```bash
nc -vz -w 3 example.com 443
```

如需測試 HTTPS 應用層，可另外使用：

```bash
curl -I --connect-timeout 3 https://example.com
```

這些命令不代表每個環境都預先安裝相應工具；`curl` 的結果也可能受代理或 TLS 設定影響。

### Telnet（歷史筆記方法）

```text
telnet <host> <port>
```

Telnet 可用於基本 TCP 連線測試，但不適合驗證 TLS、HTTP 等應用協定，也不應用於傳輸敏感憑證。舊筆記提及以 `Ctrl+]` 進入 Telnet 命令模式，再輸入 `quit`；不同用戶端的快捷鍵可能不同。

## 排查順序

1. 確認主機名稱、位址與連接埠。
2. 在客戶端測試 DNS 與 TCP 連線。
3. 比較不同網路位置（本機、WSL、容器、其他主機）的結果。
4. 若 TCP 成功，再測試真正的應用協定。
5. 若 TCP 失敗，檢查監聽位址、防火牆、路由、VPN／代理與服務日誌。

## 相關領域

- [網路通訊](README.md)
- [故障索引](../indexes/troubleshooting.md)
