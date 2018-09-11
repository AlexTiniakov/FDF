/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 11:15:57 by otiniako          #+#    #+#             */
/*   Updated: 2018/09/07 11:15:58 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define _MS ((str[j] == '-' || str[j] == '+') && j == 0)
# define _L system("leaks -q fdf")
# include <mlx.h>
# include <math.h>
# include "libft.h"

typedef struct	s_pixel
{
	double				x;
	double				y;
	double				z;
	int		        colour;
}					t_pixel;

typedef struct		s_fstr
{
	char			**str;
	struct s_fstr   *next;
}					t_fstr;

typedef struct		s_fdf
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				fd;
	double			delta;
	char			*str;
	char			**tmp;
	int				x_max;
	int				y_max;
	int				x0;
	int				y0;
	int				zoom;
	t_fstr			*content;
	t_pixel			**map;
}					t_fdf;

void ft_horizontal(t_fdf *fdf, int j, int i);
void ft_vertical(t_fdf *fdf, int j, int i);
void ft_rotate_x(t_fdf *fdf, double alp);
void ft_rotate_y(t_fdf *fdf, double alp);
void ft_rotate_z(t_fdf *fdf, double alp);
void ft_set_print(t_fdf *fdf, int i, int j);
int ft_wait(int key, void *param);
void ft_rotate_all(t_fdf *fdf, int key);
void ft_move(t_fdf *fdf, int key);
void ft_zoom(t_fdf *fdf, int key);
void ft_colour(t_fdf *fdf, int key);

#endif