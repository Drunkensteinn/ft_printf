/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 21:58:52 by ablizniu          #+#    #+#             */
/*   Updated: 2018/05/06 22:29:44 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <wchar.h>
# include <stdio.h>
# include <errno.h>
# include <time.h>
# include <locale.h>
# define PLS_PASS	time(NULL);
# define FIRST		0
# define SECOND		0xC080
# define THIRD		0xE08080
# define FOURTH		0xF0808080
# define BUFF_LEN	ft_strlen((*tmp)->buff)

typedef enum		e_fl
{
	hash = 0x1,
	zero = 0x2,
	plus = 0x4,
	minus = 0x8,
	space = 0x10,
	presicions = 0x20,
	n = 0x40,
	width = 0x80,
	dollar = 0x100,
	hh = 0x200,
	h = 0x400,
	l = 0x800,
	ll = 0x1000,
	j = 0x2000,
	z = 0x4000,
	C = 0x8000,
	d = 0x10000,
	i = 0x20000,
	s = 0x40000,
	o = 0x80000,
	p = 0x100000,
	x = 0x200000,
	c = 0x400000,
	u = 0x800000,
	D = 0x1000000,
	S = 0x2000000,
	O = 0x4000000,
	U = 0x8000000,
	X = 0x10000000,
	b = 0x20000000,
	B = 0x40000000,
	k = 0x80000000,
}					t_fl;

t_fl				g_a;
unsigned int		g_flags;

int					ft_printf(const char *format, ...);
int					ft_fprintf(const int fd, const char *format, ...);
int					ft_printf_core(va_list ag, t_alist *tmp);
int					ft_printf_core_1(t_alist *tmp);
int					validator_specificators_and_flags(va_list ap,
					t_alist **tmp);
uintmax_t			isflags_unsigned(va_list ap);
intmax_t			isflags_signed(va_list ap);
int					isflag(void);
int					search(void);
int					validator_flags(t_alist **tmp);
int					validator_flags_0(t_alist **tmp);
int					validator_flags_1(t_alist **tmp);
int					validator_flags_2(t_alist **tmp);
void				buffering(t_alist **tmp, int step,
					size_t size, char *symbol);
void				buffering_2(t_alist **tmp, int step);
int					fill_bits(t_alist **tmp, va_list ap);
void				fill_bits_1(t_alist **tmp, int *ret);
void				fill_bits_2(t_alist **tmp, int *ret);
void				fill_bits_3(t_alist **tmp, int *ret);
void				fill_bits_4(t_alist **tmp, int *ret);
int					fill_bits_a(t_alist **tmp);
void				fill_bits_a_1(t_alist **tmp, int *ret);
void				fill_bits_a_2(t_alist **tmp, int *ret);
int					ft_printf_processing(va_list ap, t_alist **tmp);
int					ft_printf_processing_1(va_list ap, t_alist **tmp);
int					ft_printf_processing_2(va_list ap, t_alist **tmp);
int					ft_printf_processing_3(va_list ap, t_alist **tmp);
int					ft_printf_processing_4(va_list ap, t_alist **tmp);
int					ft_printf_processing_5(va_list ap, t_alist **tmp);
int					kostil(t_alist **tmp);
int					search_specify(t_alist **tmp);
void				d_i(t_alist **tmp, va_list ap);
void				d_d_i_presisions(t_alist **tmp, size_t l,
					char *str, int *res);
int					zero_decimal_integer(t_alist **tmp, intmax_t n);
void				u_u(t_alist **tmp, va_list ap);
void				u_u_presisions(t_alist **tmp, size_t l,
					char *str, int *res);
void				o_t(t_alist **tmp, va_list ap);
void				x_hex(t_alist **tmp, va_list ap);
void				b_binary(t_alist **tmp, va_list ap);
void				p_pointer_addres(t_alist **tmp, va_list ap);
void				pointer_addres(t_alist **tmp, size_t len, char *symbol);
void				pointer_prec_zero(t_alist **tmp);
void				pointer_zero_f(t_alist **tmp);
void				pointer_zero_f_1(t_alist **tmp);
void				k_time_date(t_alist **tmp, va_list ap);
void				c_character(t_alist **tmp, va_list ap);
void				c_eof(t_alist **tmp);
void				format_len(t_alist **tmp);
int					width_c_eof(t_alist **tmp);
int					width_c_zero(t_alist **tmp);
void				p_b_f(t_alist **tmp, int step, size_t size);
void				s_string(t_alist **tmp, va_list ap);
void				unicode_c(t_alist **tmp, va_list ap);
void				unicode_s(t_alist **tmp, va_list ap);
void				unicode_s_1(size_t size, int step, wchar_t *s_t,
					t_alist **tmp);
int					*unicode_len(wchar_t *arr);
int					presicions_s(t_alist **tmp, size_t size, int step);
int					presicions_s_zero(t_alist **tmp, char *s, size_t len);
void				unicode_0(t_alist **tmp, unsigned int value,
					char *arr, int *step);
void				unicode_1(t_alist **tmp, unsigned int value,
					char *arr, int *step);
void				unicode_2(t_alist **tmp, unsigned int value,
					char *arr, int *step);
void				unicode_3(t_alist **tmp, unsigned int value,
					char *arr, int *step);
void				make_us_whole_reference_to_dead_space(t_alist **tmp,
					int size, char *arr, char *arr_uni);
int					hash_(t_alist **tmp, size_t l, char *str);
void				p_h_1(t_alist **tmp, char *str, size_t l, int *ret);
void				p_h_2(t_alist **tmp, char *str, size_t l, int *ret);
void				p_h_3(t_alist **tmp, char *str, size_t l, int *ret);
void				p_h_4(char *s);
void				p_h_5(char *s);
int					width_(t_alist **tmp);
int					presic_(t_alist **tmp);
void				space_(t_alist **tmp, size_t len, char *str, char *symbol);
int					hash_and_presic_x_x(t_alist **tmp, size_t l, char *str);
int					hash_and_presic_o_o(t_alist **tmp, size_t l, char *str);
int					x_x_zero_width(t_alist **tmp, size_t l, char *str);
int					x_x_precision(t_alist **tmp, size_t l, char *str, int *res);
int					o_o_precision(t_alist **tmp, size_t l, char *str, int *res);
int					s_s_precision(t_alist **tmp, size_t l, char *str);
int					kostili(t_alist **tmp, size_t l2, char *str, char *symbol);
int					kostil_1(t_alist **tmp, size_t l2, char *str, char *symbol);
int					kostil_2(t_alist **tmp, size_t l2, char *str, char *symbol);
int					kostil_3(t_alist **tmp, size_t l2, char *str, char *symbol);
int					kostil_4(t_alist **tmp, size_t l2, char *str, char *symbol);
int					kostil_5(t_alist **tmp, size_t l2, char *str, char *symbol);
int					kostil_6(t_alist **tmp, size_t l2, char *str, char *symbol);
int					kostil_7(t_alist **tmp, size_t l2, char *str, char *symbol);
int					kostil_8(t_alist **tmp, size_t l2, char *str, char *symbol);
void				p_m(t_alist **tmp, char **symbol, size_t *size, char *str);
void				w_m(t_alist **tmp, size_t *size, char **symbol, char *str);
void				min_(t_alist **tmp, char **symbol, size_t *size, char *str);
int					space_1(t_alist **tmp, size_t len, char *str, char *symbol);
void				plus_(t_alist **tmp, char **symbol, char *str);
void				output(int fd, char *buff, size_t length);
int					pre_output1(t_alist **tmp, size_t *size);
int					pre_output1_1(t_alist **tmp);
int					preoutput_1_2(t_alist **tmp);
int					pre_output_2_1(t_alist **tmp, size_t l2, char *symbol);
void				pre_output_2_2(t_alist **tmp, char *symbol);
void				pre_output_2_3(t_alist **tmp, size_t l2,
					char *symbol, char *str);
void				pre_output2(t_alist **tmp, size_t l2,
					char *str, char *symbol);
int					pre_output3(t_alist **tmp, size_t *size);
void				ft_itoa_base_printfu(uintmax_t num, int base,
					int up, t_alist **tmp);
void				ft_itoa_base_printf_s(intmax_t n, int base,
					int up, t_alist **tmp);
void				ft_bzero_list(t_alist **tmp);

#endif
