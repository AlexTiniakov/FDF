/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonuses.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:59:50 by otiniako          #+#    #+#             */
/*   Updated: 2018/09/11 10:59:51 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		ft_wait(int key, void *param)
{
	t_fdf *fdf;

	fdf = (t_fdf *)param;
	if (key == 53)
		exit(0);
	if (key == 69 || key == 78)
		ft_zoom(fdf, key);
	if (key >= 123 && key <= 126)
		ft_move(fdf, key);
	if (key >= 18 && key <= 23)
		ft_rotate_all(fdf, key);
	if (key == 15 || key == 5 || key == 11 || key == 13)
		ft_colour(fdf, key);
	return (0);
}

void	ft_zoom(t_fdf *fdf, int key)
{
	int i;
	int j;

	j = -1;
	if ((fdf->zoom > -15 && key == 78) || (fdf->zoom < 15 && key == 69))
	{
		while (++j < fdf->y_max)
		{
			i = -1;
			while (++i < fdf->x_max)
			{
				fdf->map[j][i].x = _D_X * (key == 69 ? 1.2 : (1 / 1.2));
				fdf->map[j][i].y = _D_Y * (key == 69 ? 1.2 : (1 / 1.2));
				fdf->map[j][i].z *= (key == 69 ? 1.2 : (1 / 1.2));
			}
		}
		fdf->zoom += key == 69 ? 1 : -1;
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		ft_set_print(fdf, -1, -1);
	}
}

void	ft_move(t_fdf *fdf, int key)
{
	int i;
	int j;

	j = -1;
	while (++j < fdf->y_max)
	{
		i = -1;
		while (++i < fdf->x_max)
		{
			fdf->map[j][i].x = (fdf->map[j][i].x - (double)fdf->x0);
			fdf->map[j][i].y = (fdf->map[j][i].y - (double)fdf->y0);
		}
	}
	fdf->x0 += key == 123 ? 50 : 0;
	fdf->x0 -= key == 124 ? 50 : 0;
	fdf->y0 += key == 126 ? 50 : 0;
	fdf->y0 -= key == 125 ? 50 : 0;
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	ft_set_print(fdf, -1, -1);
}

void	ft_rotate_all(t_fdf *fdf, int key)
{
	int i;
	int j;

	j = -1;
	while (++j < fdf->y_max)
	{
		i = -1;
		while (++i < fdf->x_max)
		{
			fdf->map[j][i].x = (fdf->map[j][i].x - (double)fdf->x0);
			fdf->map[j][i].y = (fdf->map[j][i].y - (double)fdf->y0);
		}
	}
	if (key == 18 || key == 19)
		ft_rotate_x(fdf, key == 18 ? 0.1 : -0.1);
	else if (key == 20 || key == 21)
		ft_rotate_y(fdf, key == 20 ? 0.1 : -0.1);
	else if (key == 23 || key == 22)
		ft_rotate_z(fdf, key == 23 ? 0.1 : -0.1);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	ft_set_print(fdf, -1, -1);
}

void	ft_colour(t_fdf *fdf, int key)
{
	int i;
	int j;

	j = -1;
	while (++j < fdf->y_max)
	{
		i = -1;
		while (++i < fdf->x_max)
		{
			fdf->map[j][i].x = (fdf->map[j][i].x - (double)fdf->x0);
			fdf->map[j][i].y = (fdf->map[j][i].y - (double)fdf->y0);
			fdf->map[j][i].colour = key == 15 ? _R : fdf->map[j][i].colour;
			fdf->map[j][i].colour = key == 5 ? _G : fdf->map[j][i].colour;
			fdf->map[j][i].colour = key == 11 ? _B : fdf->map[j][i].colour;
			fdf->map[j][i].colour = key == 13 ? _W : fdf->map[j][i].colour;
		}
	}
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	ft_set_print(fdf, -1, -1);
}
