# 🎮 So Long

> A small 2D game built as part of the 42 Málaga curriculum using the MLX42 graphics library.

## 📌 Project Overview

**So Long** is a simple top-down 2D game where the player must collect all the collectibles on the map and reach the exit to win. The project focuses on understanding and applying fundamental programming concepts like file parsing, memory management, and event-driven graphics rendering in C, using the **MLX42** library.

## 🚀 Features

- Custom map parsing from `.ber` files  
- Real-time movement and animations  
- Collision detection  
- Event handling for keyboard input  
- Pixel rendering with MLX42  

## 🧱 Tech Stack

- **Language:** C  
- **Graphics:** [MLX42](https://github.com/codam-coding-college/MLX42) (based on GLFW and OpenGL)  
- **Build Tools:** Makefile  
- **OS:** macOS  

## 📁 Map Format

Maps are stored in `.ber` files and must follow these rules:

- Rectangular shape  
- Surrounded by walls (`1`)  
- Contains one player (`P`), at least one exit (`E`), and at least one collectible (`C`)  

Example:
11111
1P0C1
10001
1C0E1
11111


## 🧠 What I Learned

- Working with 2D arrays and file I/O  
- Integrating and using a third-party graphics library (MLX42)  
- Managing real-time input and game logic  
- Handling memory safely and efficiently  
- Compiling and debugging on **macOS**

## 📸 Screenshots

*(Feel free to add a couple of screenshots or a short gameplay GIF here!)*

---

📫 Feel free to reach out or fork the project if you'd like to build something similar!
