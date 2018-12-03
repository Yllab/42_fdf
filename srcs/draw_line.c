#include <math.h>
//#include "fdf.h"

//#include "libft.h"

static void draw_line_low(char tab[][TAB_X], int x1, int y1, int x2, int y2)
{
	int dx;
	int dy;
	int yi;
	int e;

	dx = x2 - x1;
	dy = y2 - y1;
	yi = dy > 0 ? 1 : -1;
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

	dx = x2 - x1;
	dy = y2 - y1;
	xi = dx > 0 ? 1 : -1;
	dx *= dx > 0 ? 2 : -2;
	e = dx - dy;
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
	if (fabs((double)(y2 - y1)) < fabs((double)(x2 - x1)))
	{
		if (x2 > x1)
			draw_line_low(tab, x1, y1, x2, y2);
		else
			draw_line_low(tab, x2, y2, x1, y1);
	}
	else
	{
		if (y2 > y1)
			draw_line_steep(tab, x1, y1, x2, y2);	
		else
			draw_line_steep(tab, x2, y2, x1, y1);
	}
}
