# Linux 使用者環境與桌面

來源：TOOLS_NOTE/作業系統/Linux note（Git 歷史）。依目標系統實際配置確認。

## 桌面選取與剪貼簿

舊 Debian 桌面環境中反白文字後按滑鼠中鍵可貼上，通常是 X11 PRIMARY selection，與 CLIPBOARD 分開；Wayland、桌面及應用程式支援可能不同。

## 使用者切換與環境

sudo 通常依 sudoers 政策過濾環境，不一定是登入 shell；su - 建立登入環境並通常切換至目標 HOME，su 保留較多原環境但 PATH 等可能重設。screen 啟動時通常繼承環境，已存在 session 不一定跟隨新 shell 的配置。不要假定完全繼承或完全清空，可比較 env。
