#include <math.h>
//#include "fdf.h"

//DEBUG
#include <stdio.h>
#include <stdlib.h>

#define TAB_Y 31
#define TAB_X 31

static void draw_line_low(char tab[][TAB_X], int x1, int y1, int x2, int y2)
{
	int dx;
	int dy;
	int yi;
	int e;

	yi = 1;
	dx = x2 - x1;
	dy = y2 - y1;
	dy *= dy > 0 ? 2 : -2;
	e = dy - dx;
	dx *= 2;

	while (x1 <= x2)
	{
		tab[y1][x1] = 'X';
		if (e > 0)
		{
			y1 += yi;
			e -= dx;
		}
		e += dy;
		x1++;
	}
}

static void draw_line_steep(char tab[][TAB_X], int x1, int y1, int x2, int y2)
{
	int dx;
	int dy;
	int xi;
	int e;

	xi = 1;
	dx = x2 - x1;
	dy = y2 - y1;
	dx *= dx > 0 ? 2 : -2;
	e = dy - dx;
	dy *= 2;

	while (y1 <= y2)
	{
		tab[y1][x1] = 'X';
		if (e > 0)
		{
			x1 += xi;
			e -= dy;
		}
		e += dx;
		y1++;
	}
}

void draw_line_pilot(int x1, int y1, int x2, int y2)
{
	char tab[TAB_Y][TAB_X];
	int x;
	int y;

	y = 0;
	while (y < TAB_Y)
	{
		x = 0;
		while (x < TAB_X)
		{
			tab[y][x] = '.';
			x++;
		}
		y++;
	}

	tab[y1][x1] = '#';
	tab[y2][x2] = '#';

	if (fabs((double)(y2 - y1)) < fabs((double)(x2 - x1)))
	{
		if (x1 > x2)
			draw_line_low(tab, x2, y2, x1, y1);
		else
			draw_line_low(tab, x1, y1, x2, y2);
	}
	else
	{
		if (y1 > y2)
			draw_line_steep(tab, x2, y2, x1, y1);
		else
			draw_line_steep(tab, x1, y1, x2, y2);	
	}

	y = TAB_Y - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < TAB_X)
		{
			printf("%c ", tab[y][x]);
			x++;
		}
		printf("\n");
		y--;
	}
}

int main()
{
int	x1 = 15;
int	y1 = 15;
int	x2 = 1;
int	y2 = 1;

while (1)
{
x1 = 15;
y1 = 15;
x2 = 1;
y2 = 1;
while (x2 <= 28) 
{
	getchar();
	draw_line_pilot(x1, y1, x2, y2);
	x2++;
}
x2--;
while (y2 <= 28)
{
	getchar();
	draw_line_pilot(x1, y1, x2, y2);
	y2++;
}
y2--;
while (x2 >= 1) 
{
	getchar();
	draw_line_pilot(x1, y1, x2, y2);
	x2--;
}
x2++;
while (y2 >= 1) 
{
	printf("test");
	getchar();
	draw_line_pilot(x1, y1, x2, y2);
	y2--;
}
y2++;
}
}

