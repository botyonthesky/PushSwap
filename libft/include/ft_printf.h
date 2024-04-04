/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 07:38:47 by tmaillar          #+#    #+#             */
/*   Updated: 2024/03/11 07:39:29 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

int		ft_printf(const char *format, ...);
int		ft_put_memory_adress(void *ptr);
int		ft_putchar_p(char c);
int		ft_putnbr_p(int n);
int		ft_putstr_p(char *str);
int		ft_check_char(char c, va_list format);
int		ft_short_p(va_list format);
int		ft_short_u(va_list format);
int		ft_short_x(va_list format);
int		ft_short_gx(va_list format);
char	*ft_convert(unsigned int x, char *set);

#endif
