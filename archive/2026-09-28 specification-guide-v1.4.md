可選的小建議
1. §7.3 哪些理由要標確認狀態:原文寫「每一項需要記錄確認程度的 rationale」,範圍不夠明確。建議改成「§7.2 的每一項行為決定 MUST 標註確認狀態;設計上的理由不需要」。這樣 agent 就不會漏標,也不會連設計理由都去標。
2. Pending Confirmation 期間 spec 寫什麼:建議補一句「spec 照常描述目前實作的行為;確認後若行為要改,走 change」。否則 agent 可能不確定還沒確認的行為要不要寫進 spec。
3. §10.1 的「已宣告的 scope」宣告在哪裡:建議寫明是寫在 spec 的 ## Purpose。

---

這三點我都贊成，而且都屬於消除 Agent 解讀空間的小修正，不需要再改整體架構。尤其第 2 點很重要：Pending Confirmation 不應讓 current spec 出現真空；spec 永遠描述目前系統的 current behavior，是否已確認則是另一個維度。

有一個地方我特別喜歡這次修正後的模型：現在 「事實」與「信心／權威來源」被完全拆開了。
例如一個尚有疑義的效果可以同時是：
spec:
目前系統做 A

design/rationale:
為什麼做 A：根據效果文推論
狀態：Pending Confirmation

之後你決定其實應該做 B，也不會偷偷把 current spec 改成尚不存在的 B，而是：
Current A
   ↓
OpenSpec change
   ↓
Spec delta: A → B
Implementation: A → B
   ↓
Current B

這和我們前面建立的 current state / change state / history 分層非常一致。我會把這版視為可以定稿的 v1.4。