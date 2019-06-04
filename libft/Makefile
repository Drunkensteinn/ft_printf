# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/01 16:55:34 by ablizniu          #+#    #+#              #
#    Updated: 2018/04/02 19:34:30 by ablizniu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
KEYS = -Wall -Wextra -Werror -std=c99 -c
SRCS =  ft_memjn.c ft_bchr.c ft_exponentiation.c ft_memcpy_end.c get_next_line.c ft_memjoin.c ft_realloc.c ft_alist_initialize.c ft_strnlen.c ft_doop.c \
ft_swap_char.c ft_swap_int.c ft_neo_its_matrix.c ft_lstnew.c ft_atoi.c ft_lstdel.c ft_lstiter.c ft_lstmap.c ft_lstadd.c ft_lstdelone.c ft_bzero.c \
ft_putchar.c ft_putendl.c ft_putendl_fd.c ft_putnbr_fd.c ft_putchar_fd.c ft_putstr_fd.c ft_putstr.c ft_putnbr.c ft_itoa.c ft_strsplit.c ft_isalnum.c\
ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memalloc.c ft_memccpy.c ft_strjoin.c ft_strtrim.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c\
ft_memmove.c ft_memset.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strlcat.c\
ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strstr.c ft_strsub.c ft_tolower.c ft_toupper.c ft_len_swap.c\
ft_bzero_int.c
HEADER_H = libft.h

.PHONY: re all clean fclean
.NOTPARALLEL: all clean fclean re

all: $(NAME)

%.o: %.c
	gcc $(KEYS) $(SRCS)

$(NAME):
	gcc -I=$(HEADER_H) $(KEYS) -c $(SRCS) && ar rc libft.a *.o
	ranlib $(NAME)
clean:
	@/bin/rm -f *.o *.ghc
fclean: clean
	@/bin/rm -f $(NAME) *.o *.a *.gch

re: fclean all