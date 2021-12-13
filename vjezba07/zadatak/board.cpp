#include "board.h"
void board::allocateBoard()
{
	mat = new char* [cols];
	for (int i = 0; i < cols; i++)
		mat[i] = new char[rows];
}
void board::createBoard()
{
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			if (((i == 0) || (i == cols - 1)) || ((j == 0) || (j == rows - 1)))
			{
				draw_char(i,j,c);
			}
			else
			{
				draw_char(i,j,' ');
			}
		}
	}
}
void board::display()
{
	for (int j = 0; j < rows; j++)
	{
		for (int i = 0; i < cols; i++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void board::draw_char(int i, int j, char c)
{
	mat[i][j] = c;
}
void board::draw_up_line(point p, char c)
{
	for (int counter = 1; counter <= p.y; counter++)
	{
		draw_char(p.x, counter, c);
	}
}
void board::draw_line(point p1, point p2, char c) 
{
	double charsBeetwenPoints = max((abs(p1.x - p2.x)),(abs(p1.y - p2.y)));
	double differenceBetweenPoints = min((abs(p1.x - p2.x)), (abs(p1.y - p2.y)));
	double counter = 0;
	if (abs(p1.x - p2.x) > abs(p1.y - p2.y))
	{
		if ((p1.x <= p2.x )&&( p1.y <= p2.y))
		{
			for (int i = p1.x; i <= p1.x + charsBeetwenPoints; i++)
			{
				draw_char(i, round(p1.y + counter), c);
				counter+=(differenceBetweenPoints/charsBeetwenPoints);
			}
		}
		else if ((p1.x <= p2.x) && (p1.y >= p2.y)) 
		{
			for (int i = p1.x; i <= p1.x + charsBeetwenPoints; i++) 
			{
				draw_char(i, round(p1.y - counter), c);
				counter += (differenceBetweenPoints / charsBeetwenPoints);
			}
		}
		else if ((p1.x >= p2.x) && (p1.y <= p2.y))
		{
			for (int i = p1.x; i >= p1.x - charsBeetwenPoints; i--)
			{
				draw_char(i, round(p1.y + counter), c);
				counter += (differenceBetweenPoints / charsBeetwenPoints);
			}
		}
		else
		{
			for (int i = p2.x; i <= p2.x + charsBeetwenPoints; i++) 
			{
				draw_char(i, round(p1.y + counter), c);
				counter += (differenceBetweenPoints / charsBeetwenPoints);
			}
		}
	}
	else 
	{
		if ((p1.x <= p2.x) && (p1.y <= p2.y))
		{
			for (int i = p1.y; i <= p1.y + charsBeetwenPoints; i++)
			{
				draw_char(round(p1.x + counter), i, c);
				counter += (differenceBetweenPoints / charsBeetwenPoints);
			}
		}
		else if ((p1.x <= p2.x) && (p1.y >= p2.y)) 
		{
			for (int i = p1.y; i >= p2.y - charsBeetwenPoints; i--) 
			{
				draw_char(round(p1.x + counter), i, c);
				counter += (differenceBetweenPoints / charsBeetwenPoints);
			}
		}
		else if ((p1.x >= p2.x) && (p1.y <= p2.y)) 
		{
			for (int i = p1.y; i <= p1.y + charsBeetwenPoints; i++) 
			{
				draw_char(round(p1.x - counter), i, c);
				counter += (differenceBetweenPoints / charsBeetwenPoints);
			}
		}
		else
		{
			for (int i = p2.y; i <= p2.y + charsBeetwenPoints; i++)
			{
				draw_char(round(p1.x + counter), i, c);
				counter += (differenceBetweenPoints / charsBeetwenPoints);
			}
		}
	}
}
