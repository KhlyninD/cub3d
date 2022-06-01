/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:09:42 by mjhin             #+#    #+#             */
/*   Updated: 2022/05/30 21:14:43 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ft_to_width(t_game *game, int y, int ln, int tmpln)
{
	char	*tmp;
	char	*tmp2;

	if (game->map[y][ln - 1] == '\n')
		ln--;
	if (game->map[y][ln] == '\n')
		game->map[y][ln] = '\0';
	if (ln < game->width)
	{
		tmpln = game->width - ln;
		tmp2 = ft_strdup(game->map[y]);
		if (tmp2 == NULL)
			ft_error(game, "ft_to_width malloc", 0);
		tmp = ft_calloc(tmpln + 1, sizeof(char));
		if (tmp == NULL)
			ft_error(game, "ft_to_width malloc", 0);
		tmp = ft_memset(tmp, ' ', tmpln);
		free(game->map[y]);
		game->map[y] = ft_strjoin(tmp2, tmp);
		free(tmp);
		free(tmp2);
	}
}

static void	ft_check_core(t_game *game, char **m, int y, int x)
{
	while (m[y + 1] != NULL)
	{
		if (game->map[y] == NULL)
		{
			while (game->map[y + 1] != NULL)
			{
				free(game->map[y + 1]);
				y++;
			}
			ft_error(game, "malloc error ft_check_core", 0);
		}
		if ((m[y][0] != '1' && m[y][0] != ' ')
			|| (m[y][game->width - 1] != '1' && m[y][game->width - 1] != ' '))
			ft_error(game, "Frame is not full!", 0);
		while (m[y][x + 1] != '\0')
		{
			if ((m[y - 1][x] == ' ' || m[y + 1][x] == ' ' || m[y][x - 1] == ' '
				|| m[y][x + 1] == ' ') && m[y][x] != '1' && m[y][x] != ' ')
				ft_error(game, "Frame is not full!!", 0);
			x++;
		}
		x = 0;
		y++;
	}
}

static void	ft_check_rectangularity_frame(t_game *game, char **map, int i)
{
	int	j;

	j = 0;
	while (map[0][j] != '\0')
	{
		if (map[0][j] != '1' && map[0][j] != ' ')
			ft_error(game, "Frame is not full!!!", 0);
		j++;
	}
	if (game->map[1] != NULL)
	{
		ft_check_core(game, map, 1, 0);
		while (map[game->high - 1][i] != '\0')
		{
			if (map[game->high - 1][i] != '1' && map[game->high - 1][i] != ' ')
				ft_error(game, "Frame is not full!!!!!", 0);
			i++;
		}
	}
}

static int	ft_check_strangers_fullness(t_game *game, char *m, int j)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	while (m[i] != '\0')
	{
		if (m[i] != '0' && m[i] != '1' && m[i] != 'N' && m[i] != 'S'
			&& m[i] != 'E' && m[i] != 'W' && m[i] != ' ')
		{
			m[i + 1] = '\0';
			ft_error(game, ft_strjoin("Illegal character ", &(m[i])), 0);
		}
		if (m[i] == 'S' || m[i] == 'N' || m[i] == 'W' || m[i] == 'E')
		{
			p++;
			game->playdir = m[i];
			game->player_base[0] = i;
			game->player_base[1] = j;
		}
		i++;
	}
	return (p);
}

void	ft_check_map(t_game *game)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	if (game->map == NULL)
		ft_error(game, "Map didn't parsed or file is empty", 0);
	while (game->map[i] != NULL)
	{
		p += ft_check_strangers_fullness(game, game->map[i], i);
		i++;
	}
	if (p < 1)
		ft_error(game, "Where is starting character?", 0);
	if (p > 1)
		ft_error(game, "Too many starting characters", 0);
	i = 0;
	while (i < game->high)
	{
		ft_to_width(game, i, ft_strlen(game->map[i]), 0);
		i++;
	}
	ft_check_rectangularity_frame(game, game->map, 0);
	if (game->map[0][game->width] == '\n')
		game->map[0][game->width] = '\0';
}
