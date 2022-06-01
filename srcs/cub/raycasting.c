/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:55:38 by bbellatr          #+#    #+#             */
/*   Updated: 2022/05/30 15:55:38 by bbellatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	calc_step_and_sidedist(t_raycast *raycast)
{
	if (raycast->raydir_x < 0)
	{
		raycast->step_x = -1;
		raycast->side_dist_x = (raycast->pos_x - raycast->map_x)
			* raycast->delta_dist_x;
	}
	else
	{
		raycast->step_x = 1;
		raycast->side_dist_x = (raycast->map_x + 1.0f - raycast->pos_x)
			* raycast->delta_dist_x;
	}
	if (raycast->raydir_y < 0)
	{
		raycast->step_y = -1;
		raycast->side_dist_y = (raycast->pos_y - raycast->map_y)
			* raycast->delta_dist_y;
	}
	else
	{
		raycast->step_y = 1;
		raycast->side_dist_y = (raycast->map_y + 1.0f - raycast->pos_y)
			* raycast->delta_dist_y;
	}
}

void	dir_and_dist(t_raycast *raycast, int x)
{
	raycast->camera_x = 2 * x / (float)SCREEN_WIDTH - 1;
	raycast->raydir_x = raycast->dir_x + raycast->plane_x * raycast->camera_x;
	raycast->raydir_y = raycast->dir_y + raycast->plane_y * raycast->camera_x;
	raycast->delta_dist_x = fabs(1 / raycast->raydir_x);
	raycast->delta_dist_y = fabs(1 / raycast->raydir_y);
	raycast->map_x = (int)raycast->pos_x;
	raycast->map_y = (int)raycast->pos_y;
}

void	search_hit(t_raycast *raycast, t_game *game)
{
	raycast->hit = 0;
	while (!raycast->hit)
	{
		if (raycast->side_dist_x < raycast->side_dist_y)
		{
			raycast->side_dist_x += raycast->delta_dist_x;
			raycast->map_x += raycast->step_x;
			raycast->side = 0;
		}
		else
		{
			raycast->side_dist_y += raycast->delta_dist_y;
			raycast->map_y += raycast->step_y;
			raycast->side = 1;
		}
		if (game->map[raycast->map_y][raycast->map_x] == '1')
			raycast->hit = 1;
	}
}

void	calc_raycast(t_raycast *raycast, t_game *game)
{
	int	x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		dir_and_dist(raycast, x);
		calc_step_and_sidedist(raycast);
		search_hit(raycast, game);
		seach_draw_and_txt(raycast);
		choice_txt(raycast, game, x);
		x++;
	}
}

int	render(t_game *game)
{
	key_event(game->raycast, game->raycast->keys);
	calc_raycast(game->raycast, game);
	mlx_put_image_to_window(game->raycast->mlx, game->raycast->win,
		game->raycast->pixel->img, 0, 0);
	return (0);
}
