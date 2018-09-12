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
# define _D_X (fdf->map[j][i].x - (double)fdf->x0)
# define _D_Y (fdf->map[j][i].y - (double)fdf->y0)
# define _D_XI (fdf->map[j][i + 1].x - fdf->map[j][i].x)
# define _D_YI (fdf->map[j][i + 1].y - fdf->map[j][i].y)
# define _PTR fdf->mlx_ptr, fdf->win_ptr
# define _D_XJ (fdf->map[j + 1][i].x - fdf->map[j][i].x)
# define _D_YJ (fdf->map[j + 1][i].y - fdf->map[j][i].y)
# define _D_XT (fdf->x - fdf->map[j][i].x)
# define _D_YT (fdf->y - fdf->map[j][i].y)
# define _A_L1 ft_atoi_long(fdf->tmp[i]) > 2147483647
# define _A_L2 ft_atoi_long(fdf->tmp[i]) < -2147483648
# define _Y ((double)fdf->y_max - 1) / (double)fdf->x_max * 1000
# define _Z fdf->map[fdf->y_max - 1][i].z > 100000
# define _Z1 fdf->map[fdf->y_max - 1][i].z / (double)fdf->x_max * 1000
# define _S1 ft_strstr(fdf->tmp[i], ",0x")
# define _COL fdf->map[fdf->y_max - 1][i].colour
# define _AB1 ft_atoi_base((ft_strstr(fdf->tmp[i], ",0x") + 3), _HEXL)
# define _AB2 ft_atoi_base((ft_strstr(fdf->tmp[i], ",0x") + 3), _HEXU)
# define _R 0xFF0000
# define _G 0x00FF00
# define _B 0x0000FF
# define _W 0xFFFFFF
# include <mlx.h>
# include <math.h>
# include "libft.h"

typedef struct		s_pixel
{
	double			x;
	double			y;
	double			z;
	int				colour;
}					t_pixel;

typedef struct		s_fstr
{
	char			**str;
	struct s_fstr	*next;
}					t_fstr;

typedef struct		s_fdf
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				fd;
	char			*str;
	char			**tmp;
	int				x_max;
	int				y_max;
	int				x0;
	int				y0;
	int				zoom;
	double			x;
	double			y;
	double			tmp1;
	t_fstr			*content;
	t_pixel			**map;
}					t_fdf;

void				ft_horizontal(t_fdf *fdf, int j, int i);
void				ft_vertical(t_fdf *fdf, int j, int i);
void				ft_rotate_x(t_fdf *fdf, double alp);
void				ft_rotate_y(t_fdf *fdf, double alp);
void				ft_rotate_z(t_fdf *fdf, double alp);
void				ft_set_print(t_fdf *fdf, int i, int j);
int					ft_wait(int key, void *param);
void				ft_rotate_all(t_fdf *fdf, int key);
void				ft_move(t_fdf *fdf, int key);
void				ft_zoom(t_fdf *fdf, int key);
void				ft_colour(t_fdf *fdf, int key);
int					ft_check_1(char *str, int j);
int					ft_check_colour(char *str);
int					ft_check_str(t_fdf *fdf, int i, int k);
void				ft_init_fdf(t_fdf *fdf);
void				ft_add_content(t_fdf *fdf);
void				ft_add_to_map(t_fdf *fdf, int i);

#endif
