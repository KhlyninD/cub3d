/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_cast.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:53:32 by bbellatr          #+#    #+#             */
/*   Updated: 2022/05/30 15:53:32 by bbellatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_CAST_H
# define CUB_CAST_H

// pognali_epta.c
void	init_st_rc(t_game *main, t_raycast *raycast);
void	calc(t_raycast *raycast, t_game *main);
int		render(t_game *main);

// init_struct.c
void	init_st_rc2(t_game *main, t_raycast *raycast);
void	init_st_rc(t_game *main, t_raycast *raycast);
void	init_key(t_raycast *raycast);

// open_txt.c
void	init_txt(t_game *main);
void	open_txt(t_game *main, t_textures *txt, char *path);
void	load_txt(t_game *main);

//keyhook.c
int		free_all(void);
int		keypress(int keycode, t_keys *keys);
int		keyrelease(int keycode, t_keys *keys);
void	key_event(t_raycast *raycast, t_keys *keys);

//move.c
void	move_a(t_raycast *raycast);
void	move_s(t_raycast *raycast);
void	move_d(t_raycast *raycast);
void	move_w(t_raycast *raycast);

//rotate.c
void	rotate_l(t_raycast *raycast);
void	rotate_r(t_raycast *raycast);

//draw_and_search_dz.c
void	draw_line(t_raycast *raycast, t_textures *txt, int y, int x);
void	seach_draw_and_txt(t_raycast *raycast);
void	choice_txt(t_raycast *raycast, t_game *main, int x);

//free.c
void	free_all_raycast(t_game *main);
void	free_txtr(t_game *main);

#endif
