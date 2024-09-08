/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:07:52 by oouaadic          #+#    #+#             */
/*   Updated: 2024/04/27 17:44:59 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	count;

	if (fd < 0)
		return (0);
	count = 0;
	count += ft_putstr_fd(s, fd);
	count += ft_putchar_fd('\n', fd);
	return (count);
}

int	ft_putendl(char *s)
{
	int	count;

	count = 0;
	count += ft_putstr(s);
	count += ft_putchar('\n');
	return (count);
}
