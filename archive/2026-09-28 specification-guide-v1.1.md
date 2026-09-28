對指南的建議
1. 缺少放「行為決定的理由」的地方。 指南是 spec 寫「做什麼」、design 寫「怎麼做」,但這個專案有第三種東西:效果文的解讀,例如 P-018 在第一頁不能用。它包含兩部分:
   - 行為本身:可以觀察到,應該寫進 spec。我查了一下,P-018 在第一頁不能用、S-026 / S-057 不詢問是否使用,這兩條目前都不在 spec 裡,屬於缺漏。
   - 理由與確認狀態:為什麼這樣解讀、是你決定的還是只告知過你。這不是「怎麼做」,也不是歷史。
     建議在 §7 明確允許能力的 design.md 有一節「行為決定與理由」,只記錄目前仍有效的決定。
2. 跨能力的設計放哪裡沒有規定。 例如「只有回合玩家能攻擊」(引擎的事)是「下一場戰鬥」效果解讀的前提(卡片效果的事);待命時效的處理同時落在 engine.py 和效果樹。建議寫明「由主導的能力持有,其他能力放連結」,系統層級的概觀放在 capability-map。
3. §13.2 應該寫明:OpenSpec 不會處理 design.md。 spec 有 delta 機制,design 只能手動合併,最容易忘。建議要求 change 的 tasks 列出這一步。我們的 config.yaml 已經有這條規則,改成指向 §13 即可。
4. 同一套閱讀步驟重複了三次。 §9、§12、§16 各列了一份「動手前要讀什麼」,內容略有不同,agent 可能照不同版本做。建議只保留一份,其他地方引用它。
5. §10 的覆蓋程度沒有判定標準。 「Documented」和「Partial」會變成主觀判斷。建議定義,例如:
   - Documented:該領域已知的行為都有需求和情境,並有對應的測試。
   - Partial:只涵蓋一部分。
6. 小地方:
   - 標題層級不一致:1–3 節用 ##,4–18 節用 #。
   - §16 提到 AGENTS.md 要指向本指南,config.yaml 的 context 也應該指向,因為 OpenSpec 產生 artifact 時會把 context 帶進去。
   - 指南是英文、spec 是中文。我會用中文寫 capability-map 和各能力的 design,和現有 spec 一致。

---

這些建議我基本都同意，而且第 1、2、3 點會讓原本的框架更完整。尤其第 1 點揭露了一個我前一版切成 WHAT/HOW 時過度簡化的地方：current knowledge 不只有 WHAT 與 HOW，還有仍有效的 WHY / interpretation rationale。這種理由不應被丟進 archive，因為它仍是理解目前規格所需要的知識。
我會把模型調整成：
spec.md
= 現行 WHAT
= observable / normative behavior

design.md
= 現行 HOW + WHY
= established design
+ active behavioral interpretations / rationale

capability-map.md
= 系統地圖 + 跨 capability 導航

archive
= historical WHY + historical CHANGE HOW

其中 design 的 WHY 要限定為「仍然有效、理解現況所需要的 rationale」，避免 design.md 變成歷史垃圾桶。