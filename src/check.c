/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 18:30:22 by otiniako          #+#    #+#             */
/*   Updated: 2018/09/11 18:30:23 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		ft_check_1(char *str, int j)
{
	while (str[++j])
		if (!(_MS || ft_isdigit(str[j])))
			return (0);
	return (1);
}

int		ft_check_colour(char *str)
{
	int		j;
	char	*s;

	j = 2;
	if (!ft_strstr(str, ",0x") && !ft_check_1(str, -1))
		return (0);
	if ((s = ft_strstr(str, ",0x")))
	{
		while (s[++j])
			if ((!ft_strchr(_HEXU, s[j]) && !ft_strchr(_HEXL, s[j])) || j > 8)
				return (0);
		if (!(j = s - str))
			return (0);
		while (--j >= 0)
			if (!(_MS || ft_isdigit(str[j])))
				return (0);
	}
	return (1);
}

int		ft_check_str(t_fdf *fdf, int i, int k)
{
	if (!fdf->str || !(fdf->tmp = ft_strsplit(fdf->str, ' ')))
		return (0);
	ft_add_content(fdf);
	while (fdf->tmp && fdf->tmp[++i])
	{
		if (!ft_check_colour(fdf->tmp[i]))
			return (0);
		k++;
	}
	fdf->x_max = fdf->x_max ? fdf->x_max : k;
	if (fdf->x_max != k || fdf->x_max >= 99999)
		return (0);
	fdf->y_max++;
	ft_add_to_map(fdf, -1);
	return (1);
}

void	ft_init_fdf(t_fdf *fdf)
{
	fdf->mlx_ptr = NULL;
	fdf->win_ptr = NULL;
	fdf->str = NULL;
	fdf->tmp = NULL;
	fdf->x_max = 0;
	fdf->y_max = 0;
	fdf->x0 = 850;
	fdf->y0 = 100;
	fdf->content = NULL;
	fdf->map = NULL;
	fdf->map = (t_pixel **)malloc(sizeof(t_pixel *) * 100000);
	fdf->zoom = 0;
}
