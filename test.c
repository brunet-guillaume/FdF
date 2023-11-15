#include "./minilibx-linux/mlx.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_data;

typedef struct	s_mlx_data {
	void	*mlx;
	void	*win;
	t_data	img;
	int		xm;
	int		ym;

}	t_mlx_data;

typedef struct	s_line {
	int	x0;
	int	y0;
	int	x1;
	int	y1;
}	t_line;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}


void	draw_line(int x0, int y0, int x1, int y1, t_mlx_data *e)
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int err2;

	dx = abs(x1 - x0);
	sx = 1;
	if (x0 > x1)
		sx = -1;
	dy = -abs(y1 - y0);
	sy = 1;
	if (y0 > y1)
		sy = -1;
	err = dx + dy;
	while (!(x1 == x0 && y1 == y0))
	{
		my_mlx_pixel_put(&e->img, x0, y0, 0x00FFFFFF);
		err2 = 2 * err;
		if (err2 >= dy)
		{
			err += dy;
			x0 += sx;
		}
		if (err2 <= dx)
		{
			err += dx;
			y0 += sy;
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);	
}

int mouse(int x, int y, t_mlx_data *p)
{
	/*int i = 0;
	int j = 0;

	while (i < 1920)
	{
		j = 0;
		while(j < 1080)
		{
			my_mlx_pixel_put(&p->img, i, j, 0x00000000);
			j++;
		}
		i++;
	}
	//my_mlx_pixel_put(&p->img, x, y, 0x0000FF00);
	mlx_clear_window(p->mlx, p->win);
	draw_line(10, 300, x, y, p);
	//mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);*/
	p->xm = x;
	p->ym = y;
	return (0);
}

int update(t_mlx_data *e)
{
	static int i = 0;
	static int j = 0;

	int x = 0;
	int y = 0;

	i++;
	j = j + i;

	if (i > 1920)
		i = 0;
	if (j > 1080)
		j = 0;
	
	while (y < 1080)
	{
		x = 0;
		while(x < 1920)
		{
			my_mlx_pixel_put(&e->img, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
	draw_line(0, 0, e->xm, e->ym, e);
	return (1);
}

int	main(void)
{
	t_mlx_data	mlx_data;
	t_line		line;

	mlx_data.mlx = mlx_init();
	mlx_data.win = mlx_new_window(mlx_data.mlx, 1920, 1080, "Hello Wordl!");
	mlx_data.img.img = mlx_new_image(mlx_data.mlx, 1920, 1080);
	mlx_data.img.addr = mlx_get_data_addr(mlx_data.img.img, &mlx_data.img.bpp, &mlx_data.img.line_len, &mlx_data.img.endian);
	mlx_data.xm = 0;
	mlx_data.ym = 0;
	

	my_mlx_pixel_put(&mlx_data.img, 5, 10, 0x0000FF00);

	mlx_put_image_to_window(mlx_data.mlx, mlx_data.win, mlx_data.img.img, 0, 0);

	//mlx_hook(mlx_data.win, 6, (1L << 6), mouse, &mlx_data);

	write(1, "aSDASD", 6);
	
	//mlx_loop_hook(mlx_data.mlx, update, &mlx_data);
	mlx_loop(mlx_data.mlx);
}
