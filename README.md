<img src="https://i.imgur.com/y2bQtnZ.png" width="150" height="150" alt="Logo" />

# 42-So-long
## Overview
The **so_long** project at **42 School** is a beginner-level graphics project focused on building a simple **2D game using the MinilibX library**. In the game, the player controls a character that must navigate through a small map to collect items and reach the exit while avoiding enemies or obstacles. The project is designed to teach fundamental concepts of game design, rendering, and event handling using C programming.

## Getting started
This project is compatible on Linux and macOS.
> If you are on macOS, make sure you have installed **Xcode Command Line Tools**.
1. Clone this repository
```bash
git clone https://github.com/extrymes/42-So-long.git
cd 42-So-long
```
2. Compile and launch the program
```bash
make
./so_long <maps/map.ber>
```
The map file must be in `.ber` format, as indicated in the so_long specifications.

## Map requirements
Maps must conform to so_long specifications, which are the following:
- The map must be composed of **only 6 possible characters**: `0` for an empty space, `1` for a wall, `C` for a collectible, `X` for an enemy, `P` for the player's starting position and `E` for the exit.
- The map must contain **1 starting position**, **1 exit**, and **at least 1 collectible**.
- The map must be **rectangular** and **surrounded by walls**.
- There must be a **valid path** in the map.

The `maps` folder already contains some maps but you can create your own!

## Contributing
We welcome contributions from everyone! Whether you're fixing bugs, adding new features, improving documentation, or simply sharing your ideas, your input is greatly appreciated.

Thanks for visiting and happy coding!
