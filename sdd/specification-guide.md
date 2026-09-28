# Specification Guide

## 1. Purpose

This document defines how specifications and design documentation are organized and maintained in this repository.

The goals are to:

- Provide a clear source of truth for current system behavior.
- Provide a clear description of the current system design.
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
- **Change intent and design** — what a particular change intends to modify and how.
- **History** — why and how previous changes were made.

These concerns MUST NOT be treated as interchangeable.

In summary:

| Artifact | Purpose |
|---|---|
| `capability-map.md` | Navigate the system and its capabilities |
| `spec.md` | Describe current observable behavior |
| capability `design.md` | Describe current established design |
| change `proposal.md` | Describe why a change is needed and its scope |
| change `design.md` | Describe how a particular change will be implemented |
| `tasks.md` | Track implementation work for a change |
| archived change | Preserve historical change context and decisions |

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

A `design.md` SHOULD exist when documenting established architecture or implementation decisions materially improves understanding or maintenance of the capability.

---

# 4. Capabilities

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

# 5. Capability Map

`openspec/capability-map.md` is the primary navigation entry point for understanding the specification set.

It answers:

> What major capabilities exist, what are they responsible for, how are they related, and where should I start reading?

The capability map SHOULD contain:

- A brief system overview.
- A list of known applications or major subsystems.
- Known capabilities and their purposes.
- Important relationships between capabilities.
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

The capability map is a **navigation and discovery document**.

It MUST NOT duplicate detailed normative requirements from capability specifications.

The existence of the capability map MUST NOT be interpreted as proof that all system capabilities have been documented.

---

# 6. Current Specifications

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

Implementation details that can change without changing the behavioral contract SHOULD generally not be specified here.

---

# 7. Current Design

A capability's optional:

```text
openspec/specs/<capability>/design.md
```

describes the **current established design** of that capability.

It answers:

> How is this capability currently designed?

Typical content includes:

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

The capability design describes the **current state**, not the history of how that state was reached.

It SHOULD NOT contain obsolete architecture, temporary migration mechanisms, implementation progress, or historical alternatives that are no longer relevant.

---

# 8. Change-Level Design

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

# 9. Brownfield Specification Policy

This repository contains existing software whose behavior and design may not yet be fully documented.

Specifications are therefore maintained **incrementally**.

The absence of a specification does NOT imply:

- that the capability does not exist;
- that the behavior does not exist;
- that existing behavior is accidental;
- that undocumented behavior may safely be removed.

Before modifying an existing area, engineers and agents SHOULD:

1. Read the capability map.
2. Identify potentially affected capabilities.
3. Read available `spec.md` files.
4. Read available capability `design.md` files when relevant.
5. Inspect relevant existing code.
6. Inspect relevant existing tests.
7. Identify existing behavior affected by the proposed change.
8. Clarify ambiguous or undocumented behavior when necessary.

A complete reverse specification of the entire repository is NOT required before development can proceed.

Instead, missing specifications SHOULD be added or improved when they become relevant to a change.

---

# 10. Specification Coverage

Brownfield specifications may be incomplete.

Where useful, documentation SHOULD distinguish between:

- **Documented**
- **Partial**
- **Not documented**

Partial coverage is acceptable and preferable to implying completeness where none exists.

Agents MUST NOT infer that behaviors absent from the specification do not exist.

Existing code and tests remain important evidence when working in incompletely specified areas.

---

# 11. Change Workflow

The normal development workflow is:

```text
Understand existing context
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

---

# 12. Before Implementing a Change

Before implementation:

1. Identify the affected capabilities.
2. Review their current specifications.
3. Review their current designs when relevant.
4. Inspect relevant code and tests where specifications are incomplete.
5. Identify compatibility requirements and important existing behavior.
6. Resolve material ambiguities before relying on assumptions.

For brownfield code, implementation MUST NOT assume that undocumented behavior is invalid.

---

# 13. Before Archiving a Change

A completed change MUST be reconciled with the current-state documentation before archival.

## 13.1 Current Specifications

Behavioral changes MUST be reflected in the affected capability `spec.md`.

After reconciliation, the capability specification MUST describe the resulting current behavior rather than the history of the change.

## 13.2 Current Designs

Review the change-level `design.md` and the implemented result.

If the change modifies an established:

- architecture
- component responsibility
- data flow
- state ownership
- concurrency model
- persistence model
- protocol structure
- important internal interface
- established implementation pattern
- other persistent design decision

the affected capability `design.md` SHOULD be updated.

The change-level design MUST NOT simply be copied into the capability design.

The capability design describes the resulting current state.

Information that is only relevant to the transition remains in the archived change.

Examples include:

- migration steps
- temporary compatibility mechanisms
- rejected alternatives
- implementation sequencing
- obsolete architecture
- temporary workarounds

## 13.3 Capability Map

`openspec/capability-map.md` SHOULD be updated when the change:

- introduces a new capability;
- removes a capability;
- materially changes a capability's responsibility;
- materially changes relationships between capabilities; or
- changes known specification/design coverage.

---

# 14. Archival Semantics

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

Archived changes
    = historical WHY / CHANGE HOW
```

---

# 15. Documentation Navigation

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

Archived changes SHOULD normally be consulted only when historical rationale or evolution is needed.

---

# 16. Agent Instructions

AI agents working in this repository MUST follow this guide.

Before proposing or implementing a change, an agent SHOULD:

1. Read this guide.
2. Read `openspec/capability-map.md`.
3. Identify affected capabilities.
4. Read their current specifications.
5. Read their current designs when relevant.
6. Inspect code and tests where current documentation is incomplete.
7. Avoid assuming undocumented behavior may safely be changed.

Before archiving a change, an agent MUST perform the reconciliation procedure defined in **Before Archiving a Change**.

Repository-level agent configuration such as `AGENTS.md` SHOULD point to this document rather than duplicating these rules.

---

# 17. Source-of-Truth Rules

When interpreting project documentation:

**Current behavior**

```text
openspec/specs/<capability>/spec.md
```

is the normative specification when that behavior is documented.

**Current design**

```text
openspec/specs/<capability>/design.md
```

is the maintained description of established design where such documentation exists.

**Change history**

```text
openspec/changes/archive/
```

preserves historical intent and design decisions.

Because this is a brownfield project with incremental specification coverage, existing code and tests MUST also be examined when relevant behavior or design is not yet documented.

---

# 18. Evolution of This Framework

This specification framework may evolve as the project gains experience with SDD.

OpenSpec is the current workflow tool, but the principles in this document are intentionally kept separate from tool-specific behavior where practical.

Changes to this guide SHOULD preserve clear distinctions between:

- current behavior;
- current design;
- proposed changes; and
- historical records.