/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:13:21 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/12 16:25:34 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_char(char c, t_flags *flags)
{
	int		count;

	count = 0;
	if (flags->minus == 0)
		count += ft_print_width(flags, 1, 0);
	count += ft_putchar_fd(c, flags->fd);
	if (flags->minus == 1)
		count += ft_print_width(flags, 1, 0);
	return (count);
}
