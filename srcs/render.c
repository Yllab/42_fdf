#include "fdf.h"
#include "matrix.h"
#include "mlx.h"
#include <math.h>

int					is_visible(t_vector *point, t_camera *cam)
{
	if (!((double)fabs(point->x) > cam->canvas_w / 2 ||
		(double)fabs(point->y) > cam->canvas_h / 2))
		return (1);
	return (0);
}

void				pt_to_screen(t_vector *point, t_camera *cam)
{
	point->x = (point->x + cam->canvas_w / 2) / cam->canvas_w;
	point->y = (point->y + cam->canvas_h / 2) / cam->canvas_h;
	point->x = floor((double)(point->x * cam->win_w));
	point->y = floor((double)(point->y * cam->win_h));

}

void				pt_to_canvas(t_vector *point, t_camera *cam)
{
	vect_mat_mul(point, cam->t.matrix);
	point->x /= -point->z;
	point->y /= -point->z;
}

void				pt_draw(t_vector point, t_hub *hub, int z, int x)
{
	t_vector		connect;

	if (x < hub->map->width - 1)
	{
		vector_copy(&connect, &(hub->map->points[z][x + 1]));
		pt_to_canvas(&connect, &(hub->camera));
		if (is_visible(&connect, &(hub->camera)))
		{
			pt_to_screen(&connect, &(hub->camera));
			draw_line(&(hub->img), point, connect);
		}
	}
	if (z > 0)
	{
		vector_copy(&connect, &(hub->map->points[z - 1][x]));
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
	t_vector		point;

	z = 0;
	x = 0;
	hub->camera.canvas_w = 2;
	hub->camera.canvas_h = 2;
	matrix_inv(hub->camera.t.matrix);
	while (z < hub->map->height)
	{
		x = 0;
		while (x < hub->map->width)
		{
			vector_copy(&point, &(hub->map->points[z][x]));
			pt_to_canvas(&point, &(hub->camera));
			if (is_visible(&point, &(hub->camera)))
				pt_draw(point, hub, z, x);
			x++;
		}
		z++;
	}
	mlx_put_image_to_window(hub->win.mlx_id, hub->win.self_id,
							hub->img.self_id, 0, 0);
}
