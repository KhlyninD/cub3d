/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:11:23 by mjhin             #+#    #+#             */
/*   Updated: 2022/05/30 21:11:26 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

//Парсинг карты
void	ft_parse_params(t_game *game, int *gnl, int fd);
void	ft_parse_rgb(t_game *game, char ***tmp, int *op, int i);
void	ft_check_map(t_game *game);

#endif
