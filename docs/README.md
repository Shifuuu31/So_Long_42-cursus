# So_Long Documentation Index & Knowledge Base

Welcome to the central documentation index for `So_Long_42-cursus`. This knowledge base provides an interconnected technical reference detailing the game engine architecture, map parsing and DFS validation rules, low-level 2D rendering optimizations, keyboard event handling, build steps, and automated testing suites.

---

## 1. Documentation Overview

The documentation suite is organized into specialized reference guides:

- **[Project Landing Page (README.md)](../README.md)**: High-level overview, quickstart, controls, gameplay showcase, and 20-level campaign guide.
- **[Project Technical Audit (PROJECT_AUDIT.md)](PROJECT_AUDIT.md)**: Exhaustive code audit, function inventory, data structures, and cross-platform analysis.
- **[System Architecture (ARCHITECTURE.md)](ARCHITECTURE.md)**: Execution lifecycle, subsystem interactions, pipeline flowchart, and data flow.
- **[Game Mechanics & Rules (GAME_MECHANICS.md)](GAME_MECHANICS.md)**: Movement vectors, collision detection, collectible state transitions, and victory conditions.
- **[Map Format Specification (MAP_FORMAT.md)](MAP_FORMAT.md)**: `.ber` file syntax, geometric constraints, DFS flood-fill pathfinding, and diagnostics.
- **[Build & Usage Guide (BUILD_AND_USAGE.md)](BUILD_AND_USAGE.md)**: Linux & macOS prerequisites, compilation targets, map execution, and troubleshooting.
- **[Testing & Verification (TESTING.md)](TESTING.md)**: 57-assertion automated unit test suite (`make test`), 27-map verification matrix, and benchmarks.
- **[Official 42 Subject Specification (en.subject.pdf)](../en.subject.pdf)**: Complete 42 curriculum requirements for So_Long v5.0.

---

## 2. Quick Navigation

Find relevant documentation by developer task:

| I want to... | Documentation Resource | Direct Link |
| :--- | :--- | :--- |
| **Understand the game objectives & rules** | Project Overview | [Overview](../README.md#2-project-overview) |
| **Check keyboard controls (Linux & macOS)** | Controls Guide | [Controls](../README.md#6-controls) |
| **Install prerequisites & build the binary** | Build Guide | [Build & Usage Guide](BUILD_AND_USAGE.md#1-prerequisites) |
| **Run the 20-level progressive campaign** | Campaign Guide | [Campaign Map List](../README.md#8-20-level-progressive-campaign) |
| **Understand how map validation & flood-fill work** | Map Specification | [Map Format Guide](MAP_FORMAT.md#2-validation-constraints) |
| **Understand dirty-tile rendering optimization** | Architecture & Performance | [Dirty-Tile Redraw](ARCHITECTURE.md#24-event-dispatching--movement) |
| **Run the 57-assertion unit test suite** | Testing Guide | [Testing Guide](TESTING.md#2-automated-unit-test-suite-make-test) |
| **Review function prototypes and data structures** | Technical Audit | [Function Inventory](PROJECT_AUDIT.md#3-function-inventory) |
| **Inspect official 42 evaluation score (100%)** | Validation Evidence | [Validation Evidence](../README.md#14-validation-evidence) |

---

## 3. Source File & Subsystem Map

The codebase is organized into separated directories:

```text
So_Long_42-cursus/
├── header/              # Public interfaces & definitions
│   ├── so_long.h        # Primary game state (t_sl) & prototypes
│   └── libft.h          # Custom C standard library utilities
├── src/                 # Implementation source files
│   ├── main.c           # Entry point & execution coordinator
│   ├── map.c            # File parsing, dimensions, & wall checking
│   ├── move.c           # Movement, collision, & dirty-tile redraw
│   ├── path.c           # Recursive DFS flood-fill reachability check
│   ├── tools.c          # Coordinate discovery & error logging
│   ├── tools_2.c        # Counter initializers & exit messages
│   ├── window.c         # MiniLibX window, textures, & event hooks
│   └── libft/           # 13 core Libft functions linked into so_long
├── maps/                # Standard maps & 20-level campaign (.ber)
├── images/              # 40x40 XPM pixel art textures
├── tests/               # Automated unit test suite (57 assertions)
├── docs/                # Comprehensive engineering documentation
└── assets/              # Banners, diagrams, and gameplay screenshots
```
