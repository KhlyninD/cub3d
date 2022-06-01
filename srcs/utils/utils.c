/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:12:28 by mjhin             #+#    #+#             */
/*   Updated: 2022/05/30 21:12:31 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_error_fd(t_game *game, char *msg, int op, int fd)
{
	if (close(fd) == -1)
		ft_error(game, "е**ть", 0);
	ft_error(game, msg, op);
}

void	ft_error(t_game *game, char *msg, int op)
{
	ft_putstr_fd("Error\n", 2);
	if (op == 0)
		ft_putstr_fd(msg, 2);
	if (op == 1)
		perror(msg);
	ft_free_game(game);
	exit(EXIT_FAILURE);
}

int	ft_open(char *flnm)
{
	int	fd;

	fd = open(flnm, O_RDONLY);
	if (fd == -1)
		ft_error(NULL, flnm, 1);
	return (fd);
}

void	ft_gnl_read(t_game *game, int *gnl, int fd, char **ln)
{
	free(*ln);
	*gnl = get_next_line(fd, ln);
	if (*gnl == -1)
	{
		if (close(fd) == -1)
			ft_error(game, "GNL and close", 0);
		ft_error(game, "GNL", 0);
	}
}
