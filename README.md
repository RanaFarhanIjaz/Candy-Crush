Matrix Game
Overview
Matrix is a gem matching game implemented in C++ using SFML graphics library. Players swap adjacent gems to match three or more of the same type horizontally or vertically to score points.

Install SFML:
Follow SFML's installation guide to set up SFML on your system.
Make sure to link SFML correctly with your IDE or build environment.
Usage
Controls:
Use arrow keys (Up, Down, Left, Right) to move the cursor.
Use WASD keys (W for Up, A for Left, S for Down, D for Right) to swap gems.
Match three or more gems of the same type horizontally or vertically to clear them from the board.
Objective:
Score as many points as possible within the time limit by making strategic gem matches.
Keep an eye on the timer displayed on the screen.
Features
Gem Matching Mechanics:

Standard gem matching where three or more adjacent gems of the same type disappear.
Special Gem Patterns (Elbows):

Matching special "L" shaped patterns (elbows) clears more gems and awards higher points.
Score Tracking:

Current score and high score are displayed on the screen.
High score is saved between game sessions.
Timer:

Countdown timer limits the duration of each game session.
Known Issues
Sometimes cursor movement responsiveness may vary depending on system load.
Minor visual glitches may occur during rapid gem animations.
Credits
SFML - Simple and Fast Multimedia Library: SFML provides the graphics and multimedia framework used in this game (https://www.sfml-dev.org/)

