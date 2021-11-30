#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Maze.h"

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif

#define CONSOLE 1

int main(int argc, char* argv[]) {
    //Check for memory leakage
    VS_MEM_CHECK

    //Open files and verify functionality
    if (argc < 3) {
        std::cerr << "Please provide name of input and output files.\n";
        return 1;
    }

    std::cout << "Input file: " << argv[1] << std::endl;
    std::ifstream in(argv[1]);
    if (!in) {
        std::cerr << "Unable to open " << argv[1] << " for input";
        return 2;
    }

    std::cout << "Output File: " << (CONSOLE ? "cout" : argv[2]) << std::endl;
    std::ostream& out = CONSOLE ? std::cout : *(new std::ofstream(argv[2]));

    if (!out) {
        in.close();
        std::cerr << "Unable to open " << argv[2] << " for output";
        return 3;
    }

    //Begin parsing input file
    size_t h, w, d;
    std::string mazeString;

    in >> h >> w >> d;
    for (std::string line; getline(in, line);) {
        mazeString.append(line + " ");
    }

    Maze theMaze(h, w, d, mazeString);

    out << "Solve Maze:\n" << theMaze;

    if (theMaze.find_maze_path()) {
        out << std::endl << "Solution:\n" << theMaze;
    }
    else {
        out << std::endl << "No Solution Exists!\n";
    }


    in.close();
    if (!CONSOLE) {
        delete& out;
    }
}