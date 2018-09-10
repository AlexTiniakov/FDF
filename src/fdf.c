/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 11:15:28 by otiniako          #+#    #+#             */
/*   Updated: 2018/09/07 11:15:30 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int close_window(int key, void *param)
{
	if (key == 53)
		exit(0);
	return (0);
}

void	ft_print_window(t_fdf *fdf, int i, int j)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 5120, 2880, "FDF");
	ft_rotate_z(fdf, -0.5);
	ft_rotate_x(fdf, -0.5);
	while (++j< fdf->y_max)
	{
		i = -1;
		while (++i< fdf->x_max)
		{
			fdf->map[j][i].x += 850;
			fdf->map[j][i].y += 100;
		}
	}
	j = -1;
	while (++j < fdf->y_max)
	{
		i = -1;
		while (++i < fdf->x_max)
		{
			if (i + 1 < fdf->x_max)
				ft_horizontal(fdf, mlx_ptr, win_ptr, j, i);
			if (j + 1 < fdf->y_max)	
				ft_vertical(fdf, mlx_ptr, win_ptr, j, i);
		}
	}
	mlx_key_hook(win_ptr, close_window, (void *)0);
	mlx_loop(mlx_ptr);
}

void	ft_add_content(t_fdf *fdf)
{
	t_fstr *tmp;
	t_fstr *tab;
	
	tmp = fdf->content;
	while (fdf->content && fdf->content->next)
		fdf->content = fdf->content->next;
	tab = (t_fstr *)malloc(sizeof(t_fstr));
	tab->str = fdf->tmp;
	tab->next = NULL;
	if (fdf->content && !fdf->content->next)
	{
		fdf->content->next = tab;
		fdf->content = tmp;
	}
	else
		fdf->content = tab;
}

int		ft_check_1(char *str, int j)
{
	while (str[++j])
			if (!(_MS || ft_isdigit(str[j])))
				return (0);
	return (1);
}

int		ft_check_colour(char *str)
{
	int	j;
	char *s;

	j = 2;
	if (!ft_strstr(str, ",0x") && !ft_check_1(str, -1))
		return (0);
	if ((s = ft_strstr(str, ",0x")))
	{
		while(s[++j])
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

void	ft_add_to_map(t_fdf *fdf, int i)
{
	fdf->map[fdf->y_max - 1] = (t_pixel *)malloc(sizeof(t_pixel) * fdf->x_max);
	while (fdf->tmp[++i])
	{
		fdf->map[fdf->y_max - 1][i].x = i * 1000 / fdf->x_max;
		fdf->map[fdf->y_max - 1][i].y = (fdf->y_max - 1) * 1000 / fdf->x_max;
		fdf->map[fdf->y_max - 1][i].z = ft_atoi(fdf->tmp[i]) * 100 / fdf->x_max;
		fdf->map[fdf->y_max - 1][i].colour = ft_strstr(fdf->tmp[i], ",0x") ? _MAX(ft_atoi_base((ft_strstr(fdf->tmp[i], ",0x") + 3), _HEXL), ft_atoi_base((ft_strstr(fdf->tmp[i], ",0x") + 3), _HEXU)) : 0xFFFFFF;
	}
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
	if (fdf->x_max != k)
		return (0);
	fdf->y_max++;
	ft_add_to_map(fdf, -1);
	return (1);
}

void	ft_init_fdf(t_fdf *fdf)
{
	fdf->str = NULL;
	fdf->tmp = NULL;
	fdf->x_max = 0;
	fdf->y_max = 0;
	fdf->content = NULL;
	fdf->map = NULL;
	fdf->map = (t_pixel **)malloc(sizeof(t_pixel *) * 10000);
}

void	ft_fdf(t_fdf *fdf)
{
	while (get_next_line(fdf->fd, &(fdf->str)))
	{
		if (!ft_check_str(fdf, -1, 0))
			exit(ft_printf("map error\n"));
		ft_memdel((void **)&(fdf->str));
	}
}

int     main(int ac, char **av)
{
	t_fdf	fdf;

	ft_init_fdf(&fdf);
	if (ac > 1 && (fdf.fd = open(av[1], O_RDWR)) != -1)
		ft_fdf(&fdf);
	else if (ac < 2)
		ft_printf("usage: ./fdf map_file\n");
	else
		perror(av[1]);
	if (fdf.x_max < 2 && fdf.y_max < 2)
		exit(ft_printf("map error\n"));
	ft_print_window(&fdf, -1, -1);
	return (0);
}