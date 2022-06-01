# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbellatr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 15:57:55 by bbellatr          #+#    #+#              #
#    Updated: 2022/05/30 15:57:55 by bbellatr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalnum.c ft_isalpha.c \
				ft_isascii.c ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c \
				ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
				ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
				ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c \
				ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRCD		=	$(patsubst %.c,%.d,${SRC})

OBJ			=	${SRC:.c=.o}

BONUSSRC	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
				ft_lstmap.c

BONUSSRCD	=	$(patsubst %.c,%.d,${BONUSSRC})

BONUSOBJ	=	${BONUSSRC:.c=.o}

CFLAGS		=	-Wall -Werror -Wextra

HEADER		=	libft.h

NAME		=	libft.a

AR			=	ar rc

%.o:			%.c Makefile
				@${CC} ${CFLAGS} -c $< -o $@ -MMD -O2

$(NAME):		${OBJ}
				@${AR} ${NAME} ${OBJ}

bonus:			${NAME} ${BONUSOBJ}
				@${AR} ${NAME} ${BONUSOBJ}

all:			${NAME}

clean:
				@${RM} ${OBJ} ${SRCD} ${BONUSOBJ} ${BONUSSRCD}

fclean:			clean
				@${RM} ${NAME}

re:				fclean	all

.PHONY:			all clean fclean re
