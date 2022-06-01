/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:10:13 by mjhin             #+#    #+#             */
/*   Updated: 2022/05/30 21:10:17 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	ft_parse_texture(t_game *game, char **tmp)
{
	int		i;

	i = -1;
	if (tmp[0][0] == 'N' && tmp[0][1] == 'O')
		i = 0;
	if (tmp[0][0] == 'S' && tmp[0][1] == 'O')
		i = 1;
	if (tmp[0][0] == 'W' && tmp[0][1] == 'E')
		i = 2;
	if (tmp[0][0] == 'E' && tmp[0][1] == 'A')
		i = 3;
	if (i >= 0 && game->nswe[i] == NULL)
		game->nswe[i] = ft_strdup(tmp[1]);
	else
		return (1);
	if (game->nswe[i] == NULL)
		return (1);
	return (0);
}

static int	ft_game_write(t_game *game, char ***tmp, int strln)
{
	if (strln == 2)
		return (ft_parse_texture(game, *tmp));
	if ((*tmp)[0][0] == 'F' && game->floor == -1)
		ft_parse_rgb(game, tmp, &(game->floor), 0);
	else if ((*tmp)[0][0] == 'C' && game->ceilling == -1)
		ft_parse_rgb(game, tmp, &(game->ceilling), 0);
	else
		return (1);
	return (0);
}

static void	ft_check_write_params(t_game *game, char **line, int *check)
{
	char	***tmp;
	int		sln;
	int		aln;

	tmp = malloc(sizeof(char **));
	if (tmp == NULL)
		ft_error(game, "ft_check_write_params malloc", 0);
	*tmp = ft_split(*line, ' ');
	aln = ft_arrlen(*tmp);
	if (*tmp == NULL)
		ft_context_free_err(game, tmp, aln, "ft_split malloc");
	if (aln > 0)
		sln = ft_strlen((*tmp)[0]);
	if (aln < 2 || sln > 2 || sln < 1 || ft_game_write(game, tmp, sln))
		ft_context_free_err(game, tmp, aln, "Wrong map parameters");
	ft_free_arr(*tmp, 2);
	free(tmp);
	(*check)++;
}

void	ft_parse_params(t_game *game, int *gnl, int fd)
{
	int		i;
	int		check;

	game->gnln = ft_calloc(1, sizeof (char *));
	if (game->gnln == NULL)
		ft_error(game, "ft_parse_params malloc", 0);
	*game->gnln = ft_calloc(1, 1);
	if (*game->gnln == NULL)
		ft_error(game, "ft_parse_params malloc", 0);
	i = 0;
	check = 0;
	game->floor = -1;
	game->ceilling = -1;
	while (*gnl != 0 && check != 6)
	{
		ft_gnl_read(game, gnl, fd, game->gnln);
		if ((*game->gnln) != NULL && (*game->gnln)[0] != '\n'
			&& (*game->gnln)[0] != '\0')
			ft_check_write_params(game, game->gnln, &check);
		i++;
	}
	if (check != 6)
		ft_error(game, "Not enough argumetns", 0);
}
