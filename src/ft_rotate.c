/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 20:54:53 by otiniako          #+#    #+#             */
/*   Updated: 2018/09/10 20:54:53 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void ft_rotate_x(t_fdf *fdf, double alp)
{
    int y;
    int z;
    int i;
    int j;

	j = -1;
	while (++j < fdf->y_max)
	{
		i = -1;
		while (++i < fdf->x_max)
		{
			y = fdf->map[j][i].y * cos(alp)  + fdf->map[j][i].z * sin(alp);
			z = 0 - fdf->map[j][i].y * sin(alp)  + fdf->map[j][i].z * cos(alp);
			fdf->map[j][i].y = y;
			fdf->map[j][i].z = z;
		}
	}
}

void ft_rotate_y(t_fdf *fdf, double alp)
{
    int x;
    int z;
    int i;
    int j;

	j = -1;
	while (++j < fdf->y_max)
	{
		i = -1;
		while (++i < fdf->x_max)
		{
			x = fdf->map[j][i].x * cos(alp)  - fdf->map[j][i].z * sin(alp);
			z = fdf->map[j][i].x * sin(alp)  + fdf->map[j][i].z * cos(alp);
			fdf->map[j][i].x = x;
			fdf->map[j][i].z = z;
		}
	}
}

void ft_rotate_z(t_fdf *fdf, double alp)
{
    int x;
    int y;
    int i;
    int j;

	j = -1;
	while (++j < fdf->y_max)
	{
		i = -1;
		while (++i < fdf->x_max)
		{
			x = fdf->map[j][i].x * cos(alp)  + fdf->map[j][i].y * sin(alp);
			y = 0 - fdf->map[j][i].x * sin(alp)  + fdf->map[j][i].y * cos(alp);
			fdf->map[j][i].x = x;
			fdf->map[j][i].y = y;
		}
	}
}