#ifndef _LIBASTAR_
#define _LIBASTAR_

#include "ros/ros.h"
#include "GraphNode.h"
#include <queue>
#include <stdio.h>

#define MATRIX_HEIGHT 10
#define MATRIX_WIDTH 10
#define CURSE_LENGHT (MATRIX_WIDTH+MATRIX_HEIGHT)/2*1

//#define DEBUG
#define DEBUG2

class LibAstar
{
	public:

    Point goal_;
    Point start_;
    std::priority_queue<GraphNode> open_list[2];
    unsigned int closed_list[MATRIX_HEIGHT][MATRIX_WIDTH];
    unsigned int opened_list[MATRIX_HEIGHT][MATRIX_WIDTH];
    bool map[MATRIX_HEIGHT][MATRIX_WIDTH];
    char dir_map[MATRIX_HEIGHT][MATRIX_WIDTH];
    char getDir(int,int);

    LibAstar(Point &goal, Point &start);

    std::string pathFinder();

    bool validPoint(Point point);
    void clearLists();
    void clearMap();
    void clearDirMap();
    void printClosedList();
    void printOpenedList();
    void printDirMap();
    void printMap();
    void debug();
};

#endif

