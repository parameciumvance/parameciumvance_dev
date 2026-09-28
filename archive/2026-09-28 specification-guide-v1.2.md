另外有兩個小建議。
第一，你提出的「確認狀態」很值得保留，但我會固定 vocabulary，例如只允許 Confirmed / Project Decision / Inferred / Pending Confirmation，不要讓每個 agent 自己發明「已確認、曾告知、推測、應該如此……」十幾種狀態。之後甚至可以為 rationale 定一個小模板。
第二，現在既然決定 spec / design / capability-map 都用中文，我會考慮下一版直接把這份 Specification Guide 本身也改成中文。這份文件主要是給團隊讀規則，不是給 OpenSpec parser 解析；全套 current knowledge 使用同一語言，維護起來會更自然。

---

rationale 的四種狀態現在形成了一個很有用的資訊層級：Confirmed 是外部/權威確認；Project Decision 是團隊刻意做出的規範選擇；Inferred 是目前依證據採用但仍可能被推翻；Pending Confirmation 則明確暴露尚未解決的規格債。這對你現在整理既有效果解讀尤其有用。