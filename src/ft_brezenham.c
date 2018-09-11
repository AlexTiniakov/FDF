/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brezenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 17:03:22 by otiniako          #+#    #+#             */
/*   Updated: 2018/09/10 17:03:23 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

double ft_abs(double x)
{
    if (x >= 0)
        return (x);
    else
        return (0 - x);
}

void ft_set_print(t_fdf *fdf, int i, int j)
{

    mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 50, 50, fdf->map[0][0].colour, "move: <- ->");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 50, 100, fdf->map[0][0].colour, "zoom: + -");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 50, 150, fdf->map[0][0].colour, "rotate: 1 - 6");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 50, 200, fdf->map[0][0].colour, "colour: r g b w");
    while (++j< fdf->y_max)
	{
		i = -1;
		while (++i< fdf->x_max)
		{
			fdf->map[j][i].x += (double)fdf->x0;
			fdf->map[j][i].y += (double)fdf->y0;
		}
	}
	j = -1;
	while (++j < fdf->y_max)
	{
		i = -1;
		while (++i < fdf->x_max)
		{
			if (i + 1 < fdf->x_max)
				ft_horizontal(fdf, j, i);
			if (j + 1 < fdf->y_max)	
				ft_vertical(fdf, j, i);
		}
	}
}

void ft_horizontal(t_fdf *fdf, int j, int i)
{
    double tmp;
    int k = -1;
    double x = (double)fdf->map[j][i].x;
    double y = (double)fdf->map[j][i].y;
    if ((fdf->map[j][i + 1].x - fdf->map[j][i].x))
        tmp = (fdf->map[j][i + 1].y - fdf->map[j][i].y) / (fdf->map[j][i + 1].x - fdf->map[j][i].x);
    else
        tmp = 99999999;
    if (ft_abs(tmp) <= 1)
    {
        while (ft_abs(x - fdf->map[j][i + 1].x) > 1)
        {
            y = tmp * (x - fdf->map[j][i].x) + fdf->map[j][i].y;
            if (x < 5120 && y < 2880)
                mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, fdf->map[j][i].colour);
            x = x > fdf->map[j][i + 1].x ? x - 1 : x;
            x = x < fdf->map[j][i + 1].x ? x + 1 : x;
        }
    }
    else
        while (ft_abs(y - fdf->map[j][i + 1].y) > 1)
        {
            x = 1 / tmp * (y - fdf->map[j][i].y) + fdf->map[j][i].x;
            if (x < 5120 && y < 2880)
                mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, fdf->map[j][i].colour);
            y = y > fdf->map[j][i + 1].y ? y - 1 : y;
            y = y < fdf->map[j][i + 1].y ? y + 1 : y;
        }
}

void ft_vertical(t_fdf *fdf, int j, int i)
{
    double tmp;
    int k = -1;
    double x = fdf->map[j][i].x;
    double y = fdf->map[j][i].y;
    if ((fdf->map[j + 1][i].x - fdf->map[j][i].x))
        tmp = (fdf->map[j + 1][i].y - fdf->map[j][i].y) / (fdf->map[j + 1][i].x - fdf->map[j][i].x);
    else
        tmp = 99999999;
    if (ft_abs(tmp) <= 1)
    {
        while (ft_abs(x - fdf->map[j + 1][i].x) > 1)
        {
            y = tmp * (x - fdf->map[j][i].x) + fdf->map[j][i].y;
            if (x < 5120 && y < 2880)
                mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, fdf->map[j][i].colour);
            x = x > fdf->map[j + 1][i].x ? x - 1 : x;
            x = x < fdf->map[j + 1][i].x ? x + 1 : x;
        }
    }
    else
        while (ft_abs(y - fdf->map[j + 1][i].y) > 1)
        {
            x = 1 / tmp * (y - fdf->map[j][i].y) + fdf->map[j][i].x;
            if (x < 5120 && y < 2880)
                mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, fdf->map[j][i].colour);
            y = y > fdf->map[j + 1][i].y ? y - 1 : y;
            y = y < fdf->map[j + 1][i].y ? y + 1 : y;
        }
}