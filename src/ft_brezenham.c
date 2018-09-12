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

double	ft_abs(double x)
{
	if (x >= 0)
		return (x);
	else
		return (0 - x);
}

void	ft_set_print(t_fdf *fdf, int i, int j)
{
	mlx_string_put(_PTR, 50, 50, fdf->map[0][0].colour, "move: <- ->");
	mlx_string_put(_PTR, 50, 100, fdf->map[0][0].colour, "zoom: + -");
	mlx_string_put(_PTR, 50, 150, fdf->map[0][0].colour, "rotate: 1 - 6");
	mlx_string_put(_PTR, 50, 200, fdf->map[0][0].colour, "colour: r g b w");
	while (++j < fdf->y_max)
	{
		i = -1;
		while (++i < fdf->x_max)
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

void	ft_horizontal(t_fdf *fdf, int j, int i)
{
	fdf->x = (double)fdf->map[j][i].x;
	fdf->y = (double)fdf->map[j][i].y;
	fdf->tmp1 = _D_XI ? (_D_YI / _D_XI) : 99999999;
	if (ft_abs(fdf->tmp1) <= 1)
	{
		while (ft_abs(fdf->x - fdf->map[j][i + 1].x) > 1)
		{
			fdf->y = fdf->tmp1 * _D_XT + fdf->map[j][i].y;
			if (fdf->x < 5120 && fdf->y < 2880)
				mlx_pixel_put(_PTR, fdf->x, fdf->y, fdf->map[j][i].colour);
			fdf->x = fdf->x > fdf->map[j][i + 1].x ? fdf->x - 1 : fdf->x;
			fdf->x = fdf->x < fdf->map[j][i + 1].x ? fdf->x + 1 : fdf->x;
		}
	}
	else
		while (ft_abs(fdf->y - fdf->map[j][i + 1].y) > 1)
		{
			fdf->x = 1 / fdf->tmp1 * _D_YT + fdf->map[j][i].x;
			if (fdf->x < 5120 && fdf->y < 2880)
				mlx_pixel_put(_PTR, fdf->x, fdf->y, fdf->map[j][i].colour);
			fdf->y = fdf->y > fdf->map[j][i + 1].y ? fdf->y - 1 : fdf->y;
			fdf->y = fdf->y < fdf->map[j][i + 1].y ? fdf->y + 1 : fdf->y;
		}
}

void	ft_vertical(t_fdf *fdf, int j, int i)
{
	fdf->x = fdf->map[j][i].x;
	fdf->y = fdf->map[j][i].y;
	fdf->tmp1 = _D_XJ ? (_D_YJ / _D_XJ) : 99999999;
	if (ft_abs(fdf->tmp1) <= 1)
	{
		while (ft_abs(fdf->x - fdf->map[j + 1][i].x) > 1)
		{
			fdf->y = fdf->tmp1 * _D_XT + fdf->map[j][i].y;
			if (fdf->x < 5120 && fdf->y < 2880)
				mlx_pixel_put(_PTR, fdf->x, fdf->y, fdf->map[j][i].colour);
			fdf->x = fdf->x > fdf->map[j + 1][i].x ? fdf->x - 1 : fdf->x;
			fdf->x = fdf->x < fdf->map[j + 1][i].x ? fdf->x + 1 : fdf->x;
		}
	}
	else
		while (ft_abs(fdf->y - fdf->map[j + 1][i].y) > 1)
		{
			fdf->x = 1 / fdf->tmp1 * _D_YT + fdf->map[j][i].x;
			if (fdf->x < 5120 && fdf->y < 2880)
				mlx_pixel_put(_PTR, fdf->x, fdf->y, fdf->map[j][i].colour);
			fdf->y = fdf->y > fdf->map[j + 1][i].y ? fdf->y - 1 : fdf->y;
			fdf->y = fdf->y < fdf->map[j + 1][i].y ? fdf->y + 1 : fdf->y;
		}
}
