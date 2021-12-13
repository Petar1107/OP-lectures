#ifndef BOARD_H
#define BOARD_H
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
struct point
{
	int x;
	int y;
	point(int X, int Y)
	{
		x = X;
		y = Y;
	}
};
class board
{
	int rows;
	int cols;
	char** mat;
	char c;
public:
	void draw_char(int i, int j, char c);
	void draw_up_line(point p, char c);
	void draw_line(point p1, point p2, char c);
	void display();
	void createBoard();
	void allocateBoard();
	board()
	{
		cols = 20;
		rows = 10;
		c = 'o';
		allocateBoard();
		createBoard();
	}
	board(int X, int Y)
	{
		cols = X;
		rows = Y;
		c = 'o';
		allocateBoard();
		createBoard();
	}
	board(const board& other)
	{
		cols = other.cols;
		rows = other.rows;
		allocateBoard();
		createBoard();
	}
	~board()
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] mat[i];
		}
		delete[] mat;
	}
};

#endif // !BOARD_H
