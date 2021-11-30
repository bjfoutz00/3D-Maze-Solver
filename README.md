# 3D-Maze-Solver
Demonstrates knowledgeable use of recursion to solve a 3-dimensional cubic maze


The program will take an input file containing the following:

1. 3 integers determining the length, width, and height of the cubic maze
2. _h_ amount of tables of 1s and 0s detailing each slice of the maze. Each table is of size _h_ rows and _w_ columns.
    (a 0 represents an open path, while a 1 represents a "wall.")
    The first 1/0 of the first table will always be the entrance to the maze, while the last 1/0 of the last table will always be the exit to the maze
For example, a maze with _l, w,_ and _h_ of 2 would take the following input:

2 2 2

0 0
1 1

1 0
0 0


The program will then solve the maze. It will first parse the input and output the generated maze, using a '\_' in place of a 0 and a 'X' in place of a 1.
Then it will output the solved maze, using letters to represent the correct path. If there are multiple paths, it will show the first path solved.

The following letters represent each direction:
U: Up
D: Down
L: Left
R: Right
I: In ('up' a layer)
O: Out ('down' a layer)
E: Exit

If the maze is unsolvable, the program will output: "No Solution Exists!"
