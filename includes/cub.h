/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:11:33 by mjhin             #+#    #+#             */
/*   Updated: 2022/05/30 21:11:35 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# define S 1
# define A 0
# define D 2
# define W 13
# define ESC 53
# define AR_LEFT 123
# define AR_RIGHT 124
# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 800
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include "libft.h"
# include "get_next_line.h"
# include "types.h"
# include "parser.h"
# include "cub_cast.h"

//Функции общего назначения (utils.c)
void	ft_error(t_game *game, char *msg, int op);
int		ft_open(char *flnm);
void	ft_gnl_read(t_game *game, int *gnl, int fd, char **ln);
void	pixel_put(t_pixel *pixel, int x, int y, int color);
int		get_pixel_color(t_textures *txt, int x, int y);

//Функции для работы с массивом
char	**ft_arr_plus_one(char ***sub_arr, char *str, int i, int ln);
void	ft_putarr_fd(char **arr, int fd);
int		ft_arrlen(char **arr);
char	**ft_arrdup(char **arr);
char	**ft_arrjoin(char **arr1, char **arr2);

//Очистка памяти (free.c)
void	ft_context_free_err(t_game *game, char ***tmp, int aln, char *msg);
void	ft_free_game(t_game *game);
char	**ft_free_arr(char **arr, int ln);

// cub
int		dolznoBitVmain(t_game *main, t_raycast *raycast);

#endif
