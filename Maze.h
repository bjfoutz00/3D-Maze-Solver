#ifndef MAZE_H
#define MAZE_H
#include <sstream>
#include <iomanip>
#include <iostream>
#include "MazeInterface.h"

enum cells { OPEN, BLOCKED, VISITED, EXIT, LEFTWARDS, RIGHTWARDS, UPWARDS, DOWNWARDS, OUTWARDS, INWARDS };

////////POSSIBLY CHANGE NAMES/////////
#define LEFT	h, w - 1, d
#define RIGHT	h, w + 1, d
#define UP		h - 1, w, d
#define DOWN	h + 1, w, d
#define OUT		h, w, d - 1
#define IN		h, w, d + 1

class Maze :
	public MazeInterface {
private:
	size_t height = 0;
	size_t width = 0;
	size_t depth = 0;
	size_t*** maze = 0;

	size_t hCounter = 0;
	size_t wCounter = 0;
	size_t dCounter = 0;

public:
	Maze(size_t h, size_t w, size_t d, std::string s) {
		height = h;
		width = w;
		depth = d;
		std::stringstream ss(s);

		maze = new size_t**[depth];
		for (size_t i = 0; i < depth; i++) {
			maze[i] = new size_t*[height];
			for (size_t j = 0; j < height; j++) {
				maze[i][j] = new size_t[width];
				for (size_t k = 0; k < width; k++) {
					ss >> maze[i][j][k];
				}
			}
		}
	}
	~Maze() {
		for (size_t i = 0; i < depth; i++) {
			for (size_t j = 0; j < height; j++) {
				delete[] maze[i][j];
			}
			delete[] maze[i];
		}
		delete[] maze;
	}

	/** Set maze value
	   @parm height
	   @parm width
	   @parm layer
	   @parm value
	*/
	void setValue(int height, int width, int layer, int value) {
		maze[layer][height][width] = value;
	}

	/** Solve maze
	   @return true if solveable, else false
	*/
	bool find_maze_path() {
		return solveMaze();
	}

	bool solveMaze(size_t h = 0, size_t w = 0, size_t d = 0) {
		//3 base cases
		if ((h < 0) || (h >= height) || (w < 0) || (w >= width) || (d < 0) || (d >= depth)) {
			return false;
		}
		if (maze[d][h][w] != OPEN) {
			return false;
		}
		if ((h == height - 1) && (w == width - 1) && (d == depth - 1)) {
			maze[d][h][w] = EXIT;
			return true;
		}
		maze[d][h][w] = VISITED;
		//Recursive cases
		if (solveMaze(LEFT)) {
			maze[d][h][w] = LEFTWARDS;
			return true;
		}
		if (solveMaze(RIGHT)) {
			maze[d][h][w] = RIGHTWARDS;
			return true;
		}
		if (solveMaze(UP)) {
			maze[d][h][w] = UPWARDS;
			return true;
		}
		if (solveMaze(DOWN)) {
			maze[d][h][w] = DOWNWARDS;
			return true;
		}
		if (solveMaze(OUT)) {
			maze[d][h][w] = OUTWARDS;
			return true;
		}
		if (solveMaze(IN)) {
			maze[d][h][w] = INWARDS;
			return true;
		}
		maze[d][h][w] = VISITED;
		return false;
	}


	/** Output maze (same order as input maze)
	  @return string of 3D layers
	*/
	std::string toString() const {
		std::ostringstream oss;
		for (size_t i = 0; i < depth; i++) {
			oss << "Layer " << i + 1;
			for (size_t j = 0; j < height; j++) {
				oss << std::endl;
				for (size_t k = 0; k < width; k++) {
					switch (maze[i][j][k]) {
					case OPEN:
						oss << std::setw(2) << '_';
						break;
					case BLOCKED:
						oss << std::setw(2) << 'X';
						break;
					case VISITED:
						oss << std::setw(2) << '*';
						break;
					case EXIT:
						oss << std::setw(2) << 'E';
						break;
					case LEFTWARDS:
						oss << std::setw(2) << 'L';
						break;
					case RIGHTWARDS:
						oss << std::setw(2) << 'R';
						break;
					case UPWARDS:
						oss << std::setw(2) << 'U';
						break;
					case DOWNWARDS:
						oss << std::setw(2) << 'D';
						break;
					case OUTWARDS:
						oss << std::setw(2) << 'O';
						break;
					case INWARDS:
						oss << std::setw(2) << 'I';
						break;
					}
				}
			}
			oss << std::endl;
		}
		return oss.str();
	}
	friend std::ostream& operator<<(std::ostream& oss, const Maze& maze) {
		oss << maze.toString();
		return oss;
	}
};

#endif // MAZE_H