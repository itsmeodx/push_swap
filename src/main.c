/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:12:07 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/30 16:50:22 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print(void *content)
{
	ft_printf(" %d", *(int *)content);
}

int	main(int ac, char *av[])
{
	t_push_swap	ps;
	t_stack		a;
	t_stack		b;

	if (ac == 1)
		return (EXIT_SUCCESS);
	ps = (t_push_swap){0};
	a = (t_stack){0};
	b = (t_stack){0};
	ps.av = av;
	ps.ac = ac;
	ps.a = &a;
	ps.b = &b;
	if (!parse_args(&ps))
	{
		ft_dprintf(STDERR_FILENO, "Error\n");
		return (EXIT_FAILURE);
	}
	push_swap(&ps);
	ft_dlstclear(&(a.head), free);
	return (EXIT_SUCCESS);
}
