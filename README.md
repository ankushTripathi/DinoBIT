# DinoBIT
Recreating Google Chrome Dinosaur Game.
Completely in C++ using only std libraries.
This is my intro to game programming and applying OOPs concepts.

Game Specifics :

Dino is 'x' 
Tree is 'T'
Free Cell is '-'
(originally it was 0 and 1 , therefore the name)

Dino is Running at the speed of 1 cell.

Dino jumps with [space] key, and skips 3 cells.
As it is a trajectory, Dino is at the highest point in flight at 2nd cell after jump.
i.e. if Dino jumps at cell 1, he is mid flight at cell 2, his max jump height is reached at start of cell 3 and lands on cell 4.
This max height is just above the Tree Height.

Dino should avoid running into Tree by jumping.
Dino can keep jumping as long as he doesn't bump into tree.

Game Features :
Game Dificulty increases with time.
Keep track of High Score.
Extensible to support multi OS (Windows,Unix).




