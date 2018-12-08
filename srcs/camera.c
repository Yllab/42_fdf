#include "fdf.h"
#include "matrix.h"
#include <math.h>

int					is_visible(t_vector point, t_camera *camera)
{
	if (!((double)fabs(point.x) > camera->canvas_width / 2 ||
		(double)fabs(point.y) > camera->canvas_height / 2))
		return (1);
	return (0);
}

void				pt_to_screen(t_vector *point, t_camera *camera)
{
	point->x = (point->x + camera->canvas_width / 2) / canvas_width;
	point->y = (point->y + camera->canvas_height / 2) / canvas_height;
	point->x = floor((double)(point->x * camera->win_w));
	point->y = floor((double)(point->y * camera->win_h));

}

int					pt_to_canvas(t_vector *point, t_camera *camera)
{
	vect_mat_mul(&point, camera->t.matrix);
	point->x /= -point->z;
	point->y /= -point->z;
}

void				pt_draw(t_vector point, t_hub *hub, int z, int x)
{
	t_vector		connect;

	if (x < hub->map->width - 1)
	{
		vector_copy(connect, hub->map->points[z][x + 1]);
		pt_to_canvas(&connect, &(hub->camera));
		if (is_visible(&connect, &(hub->camera)))
		{
			pt_to_screen(&connect, &(hub->camera));
			draw_line(&(hub->img), point, connect);
		}
	}
	if (z > 0)
	{
		vector_copy(connect, hub->map->points[z - 1][x]);
		pt_to_canvas(&connect, &(hub->camera));
		if (is_visible(&connect, &(hub->camera)))
		{
			pt_to_screen(&connect, &(hub->camera));
			draw_line(&(hub->img), point, connect);
		}
	}
}

void				render(t_hub *hub)
{
	int 			x;
	int				z;
	int				h_max;
	int				w_max;
	t_vector		point;

	z = 0;
	x = 0;
	h_max = hub->map->height;
	w_max = hub->map->width;
	matrix_inv(camera->t.matrix);
	while (z < h_max)
	{
		x = 0;
		while (x < w_max)
		{
			vector_copy(point, hub->map->points[z][x]);
			pt_to_canvas(&point, &(hub->camera));
			if (is_visible(point, &(hub->camera))
				pt_draw(point, hub, z, x);
			x++;
		}
		z++;
	}
}
