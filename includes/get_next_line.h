/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:11:16 by mjhin             #+#    #+#             */
/*   Updated: 2022/05/30 21:11:18 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define BUFFER_SIZE 42

int		get_next_line(int fd, char **line);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strtrunc(char *str, char c);
char	*ft_strchr(const char *s, int c);

#endif
