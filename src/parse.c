/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:12:34 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/30 16:24:37 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_2d(char **d)
{
	size_t	i;

	i = 0;
	while (d && d[i])
		free(d[i++]);
	free(d);
}

bool	parse_args(t_push_swap *ps)
{
	char	**args;
	int		i;

	if (ps->ac < 2)
		return (false);
	i = 0;
	while (++i < ps->ac)
	{
		if (check_null(ps->av[i]))
		{
			ft_dlstclear(&(ps->a->head), free);
			return (false);
		}
		args = ft_split(ps->av[i], ' ');
		if (!args || !parse_args_again(ps, args))
		{
			free_2d(args);
			ft_dlstclear(&(ps->a->head), free);
			return (false);
		}
		free_2d(args);
	}
	return (true);
}

bool	parse_args_again(t_push_swap *ps, char **args)
{
	int		i;
	long	n;
	int		flag;

	if (!args)
		return (false);
	i = -1;
	while (args[++i])
	{
		if (!check_str(args[i]))
			return (false);
		n = ft_fatoi(args[i], &flag);
		if (flag == 1)
			return (false);
		if (!init_stack(ps->a, (int)n))
			return (false);
	}
	return (true);
}

bool	check_str(char *str)
{
	int	i;

	if (!str)
		return (false);
	i = 0;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1])
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i])
		return (false);
	return (true);
}

bool	check_null(char *str)
{
	int	i;

	if (!str)
		return (true);
	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (!str[i])
		return (true);
	return (false);
}
