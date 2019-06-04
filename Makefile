# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/28 16:26:12 by ablizniu          #+#    #+#              #
#    Updated: 2018/05/28 16:26:17 by ablizniu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror -g3
HEADERS = libft/libft.h ft_printf.h
OBJS = ft_printf.o	\
		ft_printf_core.o \
		ft_printf_core_2.o \
		ft_printf_core_2_1.o \
		ft_printf_core_2_2.o \
		ft_printf_core_2_3.o \
		ft_printf_core_2_4.o \
		ft_printf_core_2_5.o \
		ft_printf_core_2_6.o \
		ft_printf_core_2_7.o \
		ft_smt.o \
		ft_smt_0.o \
		ft_smt_2.o \
		ft_smt_3.o \
		ft_printf_d.o \
		ft_printf_d_1.o \
		ft_printf_d_2.o \
		ft_printf_core_0_1.o \
		ft_printf_core_0_2.o \
		ft_printf_core_0_3.o \
		ft_printf_core_0_4.o \
		ft_printf_core_0_5.o \
		specificators.o \
		ft_itoa_base_printf.o \
		ft_itoa_base_printf_u.o
OBJDIR = objs/
OBJECTS = $(addprefix ${OBJDIR}, ${OBJS})
LIB = libft.a
.PHONY: re all clean fclean

all: ${NAME}

$(NAME): $(OBJECTS)
	ar -rc ${NAME} $^ libft/*.o
	ranlib ${NAME}

${OBJDIR}%.o: %.c libft/libft.a
	mkdir -p ${OBJDIR}
	gcc -c ${FLAGS} -o $@ $<

libft/libft.a:
	make -C libft/

clean:
	make clean -C libft/
	/bin/rm -rf ${OBJDIR}
	/bin/rm -rf ${OBJECTS}


fclean: clean
	make fclean -C libft/
	/bin/rm -f ${NAME}

re: fclean all

