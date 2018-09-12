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

void	ft_print_window(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 5120, 2880, "FDF");
	ft_rotate_z(fdf, -0.5);
	ft_rotate_x(fdf, -0.5);
	ft_set_print(fdf, -1, -1);
	mlx_key_hook(fdf->win_ptr, ft_wait, (void *)fdf);
	mlx_loop(fdf->mlx_ptr);
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

void	ft_add_to_map(t_fdf *fdf, int i)
{
	fdf->map[fdf->y_max - 1] = (t_pixel *)malloc(sizeof(t_pixel) * fdf->x_max);
	while (fdf->tmp[++i])
	{
		if (_A_L1 || _A_L2)
			exit(ft_printf("map error\n"));
		fdf->map[fdf->y_max - 1][i].x = i / (double)fdf->x_max * 1000;
		fdf->map[fdf->y_max - 1][i].y = _Y;
		fdf->map[fdf->y_max - 1][i].z = ft_atoi(fdf->tmp[i]);
		fdf->map[fdf->y_max - 1][i].z = _Z ? 100000 : _Z1;
		_COL = _S1 ? _MAX(_AB1, _AB2) : 0xFFFFFF;
	}
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

int		main(int ac, char **av)
{
	t_fdf fdf;

	ft_init_fdf(&fdf);
	if (ac > 1 && (fdf.fd = open(av[1], O_RDWR)) != -1)
		ft_fdf(&fdf);
	else if (ac < 2)
	{
		ft_printf("usage: ./fdf map_file\n");
		exit(0);
	}
	else if (fdf.fd == -1)
	{
		perror(av[1]);
		exit(0);
	}
	if (fdf.x_max < 2 && fdf.y_max < 2)
		exit(ft_printf("map error\n"));
	ft_print_window(&fdf);
	return (0);
}
