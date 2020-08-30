/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:51:45 by adavis            #+#    #+#             */
/*   Updated: 2019/09/05 14:31:00 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define FLAGS "#0-+ ."
# define MODIFIERS "hhllL"
# define CONVERSIONS "cspdiouxXf%"
# define BASE_CHARS_UPPER "0123456789ABCDEF"
# define BASE_CHARS_LOWER "0123456789abcdef"

typedef	unsigned char	t_bool;
enum {false, true};

typedef struct			s_params
{
	t_bool				alternate;
	t_bool				left;
	t_bool				sign;
	t_bool				space;
	t_bool				prec;
	t_bool				zeros;
	int					l;
	t_bool				lll;
	int					h;
	size_t				width;
	int					precision;
}						t_params;

int						ft_printf(const char *format, ...);
int						parse(char **fmt, va_list ap, t_params *params);
void					init_params(t_params *params);
int						get_width(char *str);
int						get_precision(char *str, t_params *params);
void					set_flags(char **fmt, t_params *params);
int						d_render(long long d, t_params *params);
int						c_render(char c, t_params *params);
int						s_render(char *s, t_params *params);
int						o_render(unsigned long long d, t_params *params);
int						x_render(unsigned long long d, t_params *params,
																t_bool upper);
void					ft_putnbr_base(unsigned long long nbr, int base,
																t_bool upper);
int						p_render(unsigned long long d, t_params *params);
int						u_render(unsigned long long u, t_params *params);
size_t					f_render(long double f, t_params *params);
int						handle_u(va_list ap, t_params *params);
int						handle_d(va_list ap, t_params *params);
int						handle_x(va_list ap, t_params *params, t_bool upper);
int						handle_o(va_list ap, t_params *params);
int						handle_f(va_list ap, t_params *params);
int						perc_render(t_params *params);
int						x_empty(size_t width);
int						o_empty(t_params *params);
size_t					d_nbrlen(long long nbr);
void					d_render_zeros(long long d, t_params *params);
int						d_render_short(short d);

#endif
