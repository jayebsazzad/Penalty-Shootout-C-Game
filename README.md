# ⚽ PSG vs Arsenal: Penalty Shootout

A lightweight, text-based Penalty Shootout game built entirely in C that runs right inside your terminal. Face off against the computer in a high-stakes shootout!

## 🕹️ Gameplay
* **Teams:** PSG vs. Arsenal
* **Format:** 5 rounds of alternating penalty kicks and saves.
* **Tiebreaker:** Transitions into dramatic sudden death if the scores remain tied after 5 rounds.
* **Controls:** Simply follow the in-game terminal prompts to choose your direction and execute your moves.

## 🛠️ Cross-Platform Compatibility Note
This project was natively compiled for Windows. If you are running this code on **Mac** or **Linux**, please make the following minor adjustments to the source code before compiling:

1. Change the header file from `#include <windows.h>` to `#include <unistd.h>`.
2. Replace the capitalized `Sleep()` functions with lowercase `sleep()`.
3. Adjust the delay arguments from **milliseconds** (Windows standard) to **seconds** (Unix standard).

---
*Built as a foundational C programming project. Enjoy the match!* 🚀
