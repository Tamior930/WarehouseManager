# Warehouse Manager

A multi-player Sokoban-style puzzle game where players work together to move boxes to their target positions. Built with C++ and Raylib.

![Home Screenshot](https://github.com/tamior930/WarehouseManager/blob/main/res/screenshot.png?raw=true)

![Gameplay Screenshot](https://github.com/tamior930/WarehouseManager/blob/main/res/gameplay.png?raw=true)

## Features

- 🎮 Multiple playable levels with increasing difficulty
- 👥 Support for up to 4 players
- ⌨️ Customizable controls
- 🎨 Different visual themes for each level
- ⚙️ Configurable display settings (resolution, V-sync)


## Getting Started

### Prerequisites

- C++ compiler
- CMake 3.x or higher
- Raylib library

### Installation

<details>
<summary>Using CLion</summary>

1. Clone the repository:

```bash
git clone https://github.com/tamior930/WarehouseManager.git
```

2. Open the project directory in CLion
3. Create a new CMakeLists.txt file
4. Replace the CMakeLists.txt contents with the one from the clion branch
5. Load the CMake project
6. Build and run Warehouse Manager

</details>

<details>
<summary>Using Code::Blocks</summary>

1. Download the Code::Blocks version:

```bash
curl -L -O https://github.com/tamior930/WarehouseManager/archive/refs/heads/codeBlocks.zip
```

2. Extract the downloaded zip file
3. Open Code::Blocks
4. Go to File -> Open
5. Navigate to the extracted folder and open the .cbp project file
6. Build the project (F9)
7. Run the game (F10)

Note: Make sure you have the MinGW compiler properly configured in Code::Blocks.

</details>

## Controls

| Player | Movement Keys |
|--------|--------------|
| Player 1 | W/S/A/D |
| Player 2 | Arrow Keys |
| Player 3 | T/F/G/H |
| Player 4 | I/J/K/L |

Controls can be customized in the options menu.


## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.