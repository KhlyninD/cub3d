/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:56:30 by bbellatr          #+#    #+#             */
/*   Updated: 2022/05/30 15:56:30 by bbellatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ft_parse_map(t_game *game, int fd)
{
	int		gnl;
	int		l;

	gnl = 1;
	ft_parse_params(game, &gnl, fd);
	ft_gnl_read(game, &gnl, fd, game->gnln);
	while (gnl != 0 && (*game->gnln)[0] == '\0')
		ft_gnl_read(game, &gnl, fd, game->gnln);
	while (gnl != 0)
	{
		l = ft_strlen(*game->gnln);
		if (l > game->width)
			game->width = l;
		if ((*game->gnln)[0] == '\0'
			|| ft_arr_plus_one(&(game->map), *game->gnln, 0, l) == NULL)
			ft_error(game, "map divided", 0);
		ft_gnl_read(game, &gnl, fd, game->gnln);
	}
	l = ft_strlen(*game->gnln);
	if (ft_arr_plus_one(&(game->map), *game->gnln, 0, l) == NULL)
		ft_error(game, "last string of map did't parsed", 0);
}

static void	ft_check_format(char *name)
{
	int	i;
	int	len_ben;

	len_ben = ft_strlen(name);
	if (len_ben > 254)
		ft_error(NULL, "Invalid filename: too many characters", 0);
	i = 0;
	while (name[i] != '\0')
	{
		if (name[i] == '?' || name[i] == '<' || name[i] == '>'
			|| name[i] == '*' || name[i] == '"' || name[i] == '|')
			ft_error(NULL, "Invalid filename: illegal characters", 0);
		i++;
	}
	if (name[len_ben - 4] != '.' || name[len_ben - 3] != 'c' \
		|| name[len_ben - 2] != 'u'
		|| name[len_ben - 1] != 'b')
		ft_error(NULL, "Invalid format: file must have format \".cub\" ", 0);
}

void	ft_cub(t_game *game)
{
	t_pixel		*pixel;
	t_raycast	*raycast;

	raycast = malloc(sizeof(t_raycast));
	if (!raycast)
		exit(EXIT_FAILURE);
	game->raycast = raycast;
	raycast->mlx = mlx_init();
	init_st_rc(game, raycast);
	pixel = malloc(sizeof(t_pixel));
	if (!pixel)
		exit(EXIT_FAILURE);
	raycast->pixel = pixel;
	raycast->win = mlx_new_window(raycast->mlx, SCREEN_WIDTH,
			SCREEN_HEIGHT, "privetyli");
	pixel->img = mlx_new_image(raycast->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	pixel->addr = mlx_get_data_addr(pixel->img, &pixel->bpp,
			&pixel->line_len, &pixel->endian);
	mlx_hook(raycast->win, 2, 0, keypress, raycast->keys);
	mlx_hook(raycast->win, 3, 0, keyrelease, raycast->keys);
	mlx_hook(raycast->win, 17, 0, free_all, raycast);
	mlx_loop_hook(raycast->mlx, render, game);
	mlx_loop(raycast->mlx);
}

int	main(int argc, char *argv[])
{
	t_game		*game;
	int			fd;

	if (argc < 2)
		ft_error(NULL, "Too few arguments", 0);
	if (argc > 2)
		ft_error(NULL, "Too many arguments", 0);
	ft_check_format(argv[1]);
	fd = ft_open(argv[1]);
	game = (t_game *)malloc(sizeof(t_game));
	if (game == NULL)
		ft_error(game, "game initialization", 0);
	ft_bzero(game, sizeof(t_game));
	game->map = ft_calloc(1, sizeof(char *));
	if (game->map == NULL)
		ft_error(game, "ft_calloc for map", 0);
	ft_parse_map(game, fd);
	if (close(fd) == -1)
		ft_error(game, ft_itoa(fd), 1);
	game->high = ft_arrlen(game->map);
	ft_check_map(game);
	ft_cub(game);
	sleep(100);
	ft_free_game(game);
	exit(EXIT_SUCCESS);
}
