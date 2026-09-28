# Specification Guide

## 1. Purpose

This document defines how specifications and design knowledge are organized and maintained in this repository.

The goals are to:

- Provide a clear source of truth for current system behavior.
- Provide a clear description of the current system design.
- Preserve currently relevant behavioral interpretations and rationale.
- Support incremental specification of an existing brownfield system.
- Preserve the rationale and history of individual changes.
- Make specifications understandable and navigable for both engineers and AI agents.
- Keep the specification structure independent from any specific SDD tool where practical.

OpenSpec is currently used to support the change workflow.

---

## 2. Core Principles

The documentation model distinguishes between:

- **Current behavior** — what the system currently guarantees.
- **Current design** — how the system is currently designed.
- **Current rationale** — why a currently valid behavioral interpretation or design decision exists.
- **Change intent and design** — what a particular change intends to modify and how.
- **History** — why and how previous changes were made.

These concerns MUST NOT be treated as interchangeable.

| Artifact | Purpose |
|---|---|
| `capability-map.md` | Navigate the system and its capabilities |
| `spec.md` | Describe current observable and normative behavior |
| capability `design.md` | Describe current established design and currently relevant rationale |
| change `proposal.md` | Describe why a change is needed and its scope |
| change `design.md` | Describe how a particular change will be implemented |
| `tasks.md` | Track implementation and documentation work for a change |
| archived change | Preserve historical change context and decisions |

Conceptually:

```text
spec.md
    = current WHAT

design.md
    = current HOW
    + currently relevant WHY

capability-map.md
    = system map and cross-capability navigation

archived changes
    = historical WHY / CHANGE HOW
```

---

## 3. Repository Structure

The expected OpenSpec structure is:

```text
openspec/
├── capability-map.md
├── config.yaml
│
├── specs/
│   ├── <capability-a>/
│   │   ├── spec.md
│   │   └── design.md
│   │
│   └── <capability-b>/
│       ├── spec.md
│       └── design.md
│
└── changes/
    ├── <change>/
    │   ├── proposal.md
    │   ├── design.md
    │   ├── tasks.md
    │   └── specs/
    │
    └── archive/
```

Not every capability is required to have a `design.md`.

A `design.md` SHOULD exist when documenting established architecture, implementation decisions, behavioral interpretations, or rationale materially improves understanding or maintenance of the capability.

---

## 4. Capabilities

A capability represents a coherent area of system behavior or responsibility.

Capabilities SHOULD be organized around stable system responsibilities rather than individual implementation files or classes.

Examples:

```text
app2-command
app2-communication
app2-control
```

Application names MAY be used as capability prefixes when multiple applications exist in the same repository.

For example:

```text
app1-command
app1-network

app2-command
app2-network
```

Shared capabilities SHOULD use an appropriate shared namespace rather than being assigned arbitrarily to one application.

---

## 5. Capability Map

`openspec/capability-map.md` is the primary navigation entry point for understanding the specification set.

It answers:

> What major capabilities exist, what are they responsible for, how are they related, and where should I start reading?

The capability map SHOULD contain:

- A brief system overview.
- A list of known applications or major subsystems.
- Known capabilities and their purposes.
- Important relationships between capabilities.
- Important cross-capability flows or dependencies.
- Suggested entry points or reading order where useful.
- Specification coverage for brownfield areas where documentation is incomplete.

Example:

```markdown
## App2

App2 receives commands from the host and controls the target device.

| Capability | Purpose | Spec Coverage | Design Coverage |
|---|---|---|---|
| app2-communication | Host/device communication | Partial | Partial |
| app2-command | Command processing and dispatch | Partial | Documented |
| app2-control | Device control behavior | Not documented | Not documented |
```

The capability map is a **navigation and system-level overview document**.

It MUST NOT duplicate detailed normative requirements from capability specifications.

It SHOULD describe cross-capability relationships at a high level, but detailed behavior and design knowledge SHOULD remain owned by an appropriate capability.

The existence of the capability map MUST NOT be interpreted as proof that all system capabilities have been documented.

---

## 6. Current Specifications

A capability's:

```text
openspec/specs/<capability>/spec.md
```

describes the **current expected observable behavior** of that capability.

It answers:

> What does the system currently guarantee?

Specifications SHOULD focus on externally or behaviorally meaningful requirements rather than unnecessary implementation details.

Examples include:

- inputs and outputs
- externally observable behavior
- state-dependent behavior
- protocol behavior
- failure behavior
- compatibility requirements
- important constraints and invariants
- behavioral interpretations that affect observable results

If an interpretation results in observable behavior, the resulting behavior MUST be represented in the specification when that area is documented.

For example, if an effect cannot be used under a particular condition, that restriction belongs in the specification regardless of where the interpretation originated.

Implementation details that can change without changing the behavioral contract SHOULD generally not be specified here.

---

## 7. Current Design and Rationale

A capability's optional:

```text
openspec/specs/<capability>/design.md
```

describes the **current established design and currently relevant rationale** of that capability.

It answers:

> How is this capability currently designed?

and, where necessary:

> Why is the current behavior or design understood this way?

Typical design content includes:

- architecture
- component responsibilities
- important data flows
- state ownership
- concurrency model
- persistence model
- protocol structure
- important internal interfaces
- established implementation patterns
- important technical constraints

### Behavioral Decisions and Rationale

`design.md` MAY contain a section such as:

```markdown
## Behavioral Decisions and Rationale
```

for currently relevant decisions that explain the interpretation of behavior defined in `spec.md`.

This section MAY record:

- why an ambiguous rule or effect is interpreted in a particular way;
- evidence used to reach the interpretation;
- whether the interpretation was explicitly confirmed;
- whether it is based on an existing implementation, source material, domain interpretation, or project decision;
- important assumptions required to understand the current behavior.

The **resulting behavior itself** MUST be represented in `spec.md` when applicable.

The rationale in `design.md` explains why that behavior is currently understood or specified that way.

Where useful, rationale entries SHOULD reference the corresponding requirement or scenario.

For example:

```text
spec.md
REQ-P018-xxx:
P-018 cannot be used on the first page.

design.md
Behavioral Decisions and Rationale:
REQ-P018-xxx is interpreted this way because ...
Confirmation status: Confirmed / Project decision / Inferred / Pending confirmation
```

Only rationale that remains relevant to understanding the **current system** SHOULD remain in the capability design.

Superseded interpretations and obsolete rationale belong in archived changes or other historical records.

---

## 8. Cross-Capability Ownership

Behavior or design may involve more than one capability.

Each piece of detailed knowledge SHOULD have one primary owning capability.

The owning capability SHOULD be the capability whose responsibility most directly governs the behavior or design decision.

Other affected capabilities SHOULD reference the owning capability rather than duplicate the same normative requirement or detailed rationale.

For example:

```text
engine capability
    owns:
    "Only the active-turn player may attack."

card-effect capability
    relies on:
    engine attack eligibility rules
```

The card-effect specification or design MAY link to the engine requirement rather than redefine the rule.

For cross-capability design:

- detailed design SHOULD be owned by the primary capability;
- dependent capabilities SHOULD reference the owning capability where useful;
- `capability-map.md` SHOULD describe important system-level relationships and flows.

If no single capability is a reasonable owner because the decision is genuinely system-wide, the system-level relationship SHOULD be summarized in `capability-map.md`, with detailed documentation placed in the most appropriate shared capability or dedicated system-level documentation.

Duplication of normative requirements across capabilities SHOULD be avoided.

---

## 9. Change-Level Design

A change-specific:

```text
openspec/changes/<change>/design.md
```

has a different purpose from a capability-level `design.md`.

It answers:

> How should this particular change be implemented?

It may therefore contain information that should never appear in the current capability design, including:

- migration strategy
- temporary compatibility mechanisms
- implementation sequence
- alternatives considered
- rejected approaches
- transition architecture
- change-specific risks

After completion, the change design becomes part of the historical record.

It MUST NOT automatically be treated as the current capability design.

---

## 10. Brownfield Specification Policy

This repository contains existing software whose behavior and design may not yet be fully documented.

Specifications are therefore maintained **incrementally**.

The absence of a specification does NOT imply:

- that the capability does not exist;
- that the behavior does not exist;
- that existing behavior is accidental;
- that undocumented behavior may safely be removed.

A complete reverse specification of the entire repository is NOT required before development can proceed.

Instead, missing specifications and design knowledge SHOULD be added or improved when they become relevant to a change.

### Coverage Levels

Specification coverage SHOULD use the following meanings:

**Documented**

The known behavior within the declared scope is represented by requirements and scenarios, and corresponding verification or tests exist where reasonably testable.

"Documented" does not claim that unknown behavior cannot exist.

**Partial**

Only part of the known behavior within the capability or declared area has been specified, or important scenarios or verification coverage remain missing.

**Not documented**

No meaningful current specification has yet been established for the area.

Design coverage MAY use the same terms, interpreted with respect to known architecture and design knowledge rather than behavioral requirements and tests.

Coverage status is informational and MUST NOT be interpreted as proof of completeness.

---

## 11. Required Reading Before a Change

Before proposing or implementing a change, engineers and agents SHOULD:

1. Read this guide.
2. Read `openspec/capability-map.md`.
3. Identify potentially affected capabilities.
4. Read their available `spec.md` files.
5. Read their available capability `design.md` files when relevant.
6. Inspect relevant existing code.
7. Inspect relevant existing tests.
8. Identify existing behavior and design affected by the proposed change.
9. Identify cross-capability dependencies.
10. Clarify material ambiguities or undocumented behavior when necessary.

For brownfield code, undocumented behavior MUST NOT be assumed to be invalid or safe to change.

Other sections of this guide refer to this procedure as the **Required Reading procedure**.

---

## 12. Change Workflow

The normal development workflow is:

```text
Required Reading
        ↓
Propose
        ↓
Specify / Clarify
        ↓
Design
        ↓
Plan tasks
        ↓
Implement
        ↓
Verify
        ↓
Reconcile current documentation
        ↓
Archive
```

Not every change requires every artifact to contain substantial content.

The amount of specification and design work SHOULD be proportional to the scope and risk of the change.

Change tasks SHOULD include required current-documentation reconciliation when the change may affect capability specifications, capability designs, rationale, or the capability map.

---

## 13. Before Archiving a Change

A completed change MUST be reconciled with the current-state documentation before archival.

### 13.1 Current Specifications

Behavioral changes MUST be reflected in the affected capability `spec.md`.

OpenSpec provides delta-spec synchronization for capability specifications.

After synchronization, the capability specification MUST describe the resulting current behavior rather than the history of the change.

### 13.2 Current Designs and Rationale

OpenSpec's standard delta-spec synchronization does **not** automatically reconcile capability-level `design.md`.

Current design and rationale reconciliation is therefore an explicit project responsibility.

Before archival:

1. Review the change-level `design.md`.
2. Review the implemented result.
3. Identify affected capability-level `design.md` files.
4. Update them when established design or currently relevant rationale has changed.
5. Verify that they describe the resulting current state.

This reconciliation SHOULD appear as an explicit task in `tasks.md` whenever a change may affect current design or rationale.

A capability `design.md` SHOULD be updated when a change modifies an established:

- architecture
- component responsibility
- data flow
- state ownership
- concurrency model
- persistence model
- protocol structure
- important internal interface
- established implementation pattern
- behavioral interpretation or rationale
- other persistent design decision

The change-level design MUST NOT simply be copied into the capability design.

Do not carry transition-only information into the current design, including:

- migration steps
- temporary compatibility mechanisms
- rejected alternatives
- implementation sequencing
- obsolete architecture
- temporary workarounds

Such information remains in the archived change.

### 13.3 Capability Map

`openspec/capability-map.md` SHOULD be updated when the change:

- introduces a new capability;
- removes a capability;
- materially changes a capability's responsibility;
- materially changes relationships between capabilities; or
- changes known specification/design coverage.

Where applicable, capability-map reconciliation SHOULD also appear in `tasks.md`.

---

## 14. Archival Semantics

Archived OpenSpec changes are historical records.

They answer questions such as:

> Why was this change made?

> What alternatives were considered?

> How was the transition planned?

> What constraints existed at the time?

Archived change artifacts SHOULD NOT be used as the primary description of the current system when an applicable current specification or current design exists.

Conceptually:

```text
Current spec.md
    = current WHAT

Current design.md
    = current HOW
    + currently relevant WHY

Archived changes
    = historical WHY / CHANGE HOW
```

---

## 15. Documentation Navigation

For understanding the system, the recommended reading path is:

```text
capability-map.md
        ↓
affected capability
        ↓
spec.md
        ↓
design.md (when relevant)
        ↓
code / tests
```

Archived changes SHOULD normally be consulted when historical rationale or system evolution is needed.

When beginning a change, follow the full **Required Reading procedure** defined in §11.

---

## 16. Agent and OpenSpec Integration

AI agents working in this repository MUST follow this guide.

Repository-level agent instructions such as `AGENTS.md` SHOULD point to this document rather than duplicate its rules.

For example:

```text
Before specification-driven work, read:
docs/specification-guide.md
```

`openspec/config.yaml` SHOULD also reference this guide in its project context so that OpenSpec-generated artifacts are created with awareness of the repository's specification policy.

Tool-specific configuration SHOULD avoid duplicating the full policy where a reference to this guide is sufficient.

The authoritative definition of this repository's specification workflow is this document, not the agent or OpenSpec configuration.

---

## 17. Source-of-Truth Rules

When interpreting project documentation:

### Current behavior

```text
openspec/specs/<capability>/spec.md
```

is the normative specification when that behavior is documented.

### Current design and rationale

```text
openspec/specs/<capability>/design.md
```

is the maintained description of established design and currently relevant rationale where such documentation exists.

### System navigation

```text
openspec/capability-map.md
```

is the maintained map of known capabilities and important relationships.

It is not a substitute for capability specifications.

### Change history

```text
openspec/changes/archive/
```

preserves historical intent, alternatives, transition design, and change-specific decisions.

Because this is a brownfield project with incremental specification coverage, existing code and tests MUST also be examined when relevant behavior or design is not yet documented.

---

## 18. Documentation Language

The specification set, capability map, and capability design documentation MAY use Traditional Chinese when that is the established language of the project.

Terminology SHOULD remain consistent across capabilities.

Code identifiers, protocol identifiers, card/effect identifiers, requirement IDs, and other stable technical identifiers SHOULD generally retain their canonical form rather than being translated.

Consistency and unambiguous terminology are more important than requiring a particular natural language.

---

## 19. Evolution of This Framework

This specification framework may evolve as the project gains experience with SDD.

OpenSpec is the current workflow tool, but the principles in this document are intentionally kept separate from tool-specific behavior where practical.

Changes to this guide SHOULD preserve clear distinctions between:

- current behavior;
- current design;
- currently relevant rationale;
- proposed changes; and
- historical records.