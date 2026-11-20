# 容器建置

## Debian／Ubuntu 非互動套件安裝

舊 Ubuntu 18.04 Dockerfile 升級時記錄 `ARG DEBIAN_FRONTEND=noninteractive`，避免 debconf 互動提示。宜將設定限制在必要建置階段或單一 RUN（例如 `RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y package`，package 為示意）。不保證所有安裝程式都不互動，不宜無條件設成持久 ENV。

來源：開發/版本更新（Git 歷史）；歷史環境未重驗。
