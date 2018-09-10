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

void ft_horizontal(t_fdf *fdf, int j, int i)
{
    double x = (double)fdf->map[j][i].x;
    double y = (double)fdf->map[j][i].y;
    double tmp = ((double)fdf->map[j][i + 1].y - (double)fdf->map[j][i].y) / ((double)fdf->map[j][i + 1].x - (double)fdf->map[j][i].x);
    while ((int)x != fdf->map[j][i + 1].x && x < 5120 && y < 2880)
    {
        y = tmp * (x - (double)fdf->map[j][i].x) + (double)fdf->map[j][i].y;
        mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, fdf->map[j][i].colour);
        x = x > fdf->map[j][i + 1].x ? x - 0.1 : x;
		x = x < fdf->map[j][i + 1].x ? x + 0.1 : x;
    }
    if ((int)x == fdf->map[j][i + 1].x && (int)y != fdf->map[j][i + 1].y)
        while ((int)y != fdf->map[j][i + 1].y && x < 5120 && y < 2880)
        {
            mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, fdf->map[j][i].colour);
            y = y > fdf->map[j][i + 1].y ? y - 0.1 : y;
		    y = y < fdf->map[j][i + 1].y ? y + 0.1 : y;
        }
}

void ft_vertical(t_fdf *fdf, int j, int i)
{
    double x = (double)fdf->map[j][i].x;
    double y = (double)fdf->map[j][i].y;
    double tmp = ((double)fdf->map[j + 1][i].y - (double)fdf->map[j][i].y) / ((double)fdf->map[j + 1][i].x - (double)fdf->map[j][i].x);
    while ((int)x != fdf->map[j + 1][i].x && x < 5120 && y < 2880)
    {
        y = tmp * (x - (double)fdf->map[j][i].x) + (double)fdf->map[j][i].y;
        mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, fdf->map[j][i].colour);
        x = x > fdf->map[j + 1][i].x ? x - 0.1 : x;
		x = x < fdf->map[j + 1][i].x ? x + 0.1 : x;
    }
    if ((int)x == fdf->map[j + 1][i].x && (int)y != fdf->map[j + 1][i].y)
        while ((int)y != fdf->map[j + 1][i].y && x < 5120 && y < 2880)
        {
            mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, fdf->map[j][i].colour);
            y = y > fdf->map[j + 1][i].y ? y - 0.1 : y;
		    y = y < fdf->map[j + 1][i].y ? y + 0.1 : y;
        }
}