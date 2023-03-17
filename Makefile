# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cormiere <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 11:42:04 by cormiere          #+#    #+#              #
#    Updated: 2022/10/10 17:29:01 by cormiere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

AR = ar rcs

CFLAGS = -Wall -Werror -Wextra

SRC = ft_atoi.c \
	ft_isprint.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_bzero.c \
	ft_memchr.c \
	ft_strdup.c \
	ft_tolower.c \
	ft_isalnum.c \
	ft_memcmp.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_isalpha.c \
	ft_memcpy.c \
	ft_strlen.c \
	ft_isascii.c \
	ft_memmove.c \
	ft_strncmp.c \
	ft_isdigit.c \
	ft_memset.c \
	ft_strnstr.c \
	ft_calloc.c \
	ft_putchar_fd.c \
	ft_strjoin.c \
	ft_putstr_fd.c \
	ft_putnbr_fd.c \
	ft_putendl_fd.c \
	ft_substr.c \
	ft_itoa.c \
	ft_strtrim.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_split.c

SRC_BONUS = ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

OBJ = ${SRC:.c=.o}

OBJ_BONUS = ${SRC_BONUS:.c=.o}

all: $(NAME)

.c.o: 
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	$(OBJ)
	 ${AR} ${NAME} $(OBJ)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

bonus : $(OBJ) $(OBJ_BONUS)
	${AR} ${NAME} $(OBJ) $(OBJ_BONUS)

.PHONY:
	re all clean fclean bonus
