# Build and Usage Guide: So_Long

This guide provides instructions for compiling, running, and troubleshooting `So_Long` on both Linux and macOS.

---

## 1. Prerequisites

### 1.1 Linux (Debian / Ubuntu / Kali / Pop!_OS)
The graphical subsystem requires X11 client libraries, extensions, and BSD utility libraries.

Install the required development headers:
```bash
sudo apt-get update
sudo apt-get install -y gcc make libx11-dev libxext-dev libbsd-dev
```

Ensure an active graphical environment with an open X display:
```bash
echo $DISPLAY  # Typically returns :0 or :1
```

### 1.2 macOS (Apple Silicon & Intel)
On macOS, MiniLibX interfaces directly with Cocoa and OpenGL frameworks.

1. Install Xcode Command Line Tools:
   ```bash
   xcode-select --install
   ```
2. No external library installations are needed; the required frameworks (`OpenGL` and `AppKit`) are bundled with macOS.

---

## 2. Compilation

The project uses a cross-platform [`Makefile`](../Makefile) that automatically detects the host operating system (`Darwin` vs `Linux`) and applies the appropriate compiler and linker flags.

### 2.1 Build Targets

| Command | Action |
| :--- | :--- |
| `make` / `make all` | Compiles dependencies, source files, and produces executable `so_long`. |
| `make test` | Builds and executes the automated C unit test suite (57 assertions). |
| `make clean` | Removes compiled object files (`.o`). |
| `make fclean` | Removes object files and the `so_long` executable. |
| `make re` | Re-executes `fclean` followed by `all` for a clean rebuild. |

### 2.2 Compilation Flags
- **Compiler**: `cc`
- **Strict Flags**: `-Wall -Wextra -Werror -g`
- **Linux Linker Flags**: `-Lminilibx-linux -lmlx -lXext -lX11 -lm -lbsd`
- **macOS Linker Flags**: `-lmlx -framework OpenGL -framework AppKit`

---

## 3. Running the Game

Launch the executable by passing a valid `.ber` map file as the first argument:

```bash
./so_long <path_to_map.ber>
```

### 3.1 Standard Map Showcase
```bash
# Classic introductory map (15 x 7, 4 keys)
./so_long maps/map.ber

# Mini puzzle chamber (7 x 5, 2 keys)
./so_long maps/small_map.ber

# Vertical tower ascent (13 x 29, 10 keys)
./so_long maps/tall_map.ber

# Grand castle grounds (45 x 17, 18 keys)
./so_long maps/big_map.ber

# Rich adventure labyrinth (45 x 23, 24 keys)
./so_long maps/game_map.ber

# Fortress citadel (51 x 25, 28 keys)
./so_long maps/huge_map.ber

# Maximum screen-filling mega maze (59 x 31, 30 keys)
./so_long maps/epic_labyrinth.ber
```

### 3.2 Progressive 20-Level Campaign
Start the 20-level campaign from Tutorial Level 1 up to Master Level 20:

```bash
# Level 1 (Tutorial - 9x5, 2 keys)
./so_long maps/level_01.ber

# Level 5 (The Vault - 17x9, 6 keys)
./so_long maps/level_05.ber

# Level 10 (The Catacombs - 29x13, 13 keys)
./so_long maps/level_10.ber

# Level 15 (Minotaur's Dungeon - 43x19, 23 keys)
./so_long maps/level_15.ber

# Level 20 (The Grand Abyss - 59x31, 35 keys)
./so_long maps/level_20.ber
```

---

## 4. Controls

- **Move Up**: `W` or `Up Arrow`
- **Move Down**: `S` or `Down Arrow`
- **Move Left**: `A` or `Left Arrow`
- **Move Right**: `D` or `Right Arrow`
- **Quit Game**: `ESC` or Window Close Button (`X`)

---

## 5. Troubleshooting

### Issue: `Can't find a suitable X11 include directory`
**Cause**: Missing X11 development headers on Linux.  
**Solution**: Run `sudo apt-get install -y libx11-dev libxext-dev libbsd-dev`.

### Issue: `No protocol specified / Can't open display`
**Cause**: The process is running in a shell where `$DISPLAY` or `XAUTHORITY` is unset or unauthorized.  
**Solution**: Verify `echo $DISPLAY`. In SSH or nested sessions, use `ssh -X` or ensure permissions via `xhost +local:`.

### Issue: `so_long: command not found`
**Cause**: The project has not been compiled yet.  
**Solution**: Run `make` in the repository root.
