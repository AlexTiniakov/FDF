/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 18:54:39 by otiniako          #+#    #+#             */
/*   Updated: 2018/09/07 18:54:41 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int close_window(int key, void *param)
{
	if (key == 53)
		exit(0);
	return (0);
}

void	test()
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "my window");
	
	int x0 = 500;
	int y0 = 500;
	int x1[] = {1, 999, 999, 1};
	int y1[] = {1, 1, 999, 999};
	int y = y0;
	int x = x0;
	int i = -1;
	while (++i < 4)
	{
	int y = y0;
	int x = x0;
	int tmp = (y1[i] - y0) / (x1[i] - x0);
	while (x != x1[i])
	 {
		y = tmp * (x - x0) + y0;
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xffffff);
		x = x > x1[i] ? x - 1 : x;
		x = x < x1[i] ? x + 1 : x;
	 }
	}
	mlx_key_hook(win_ptr, close_window, (void *)0);
	//mlx_pixel_put(mlx_ptr, win_ptr, 600, 600, 76435);
	mlx_loop(mlx_ptr);
}