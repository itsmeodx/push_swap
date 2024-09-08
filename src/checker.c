/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:42:16 by oouaadic          #+#    #+#             */
/*   Updated: 2024/06/01 17:55:55 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print(void *content)
{
	ft_printf("\t%d\n", *(int *)content);
}

bool	which(t_push_swap *ps, char *line)
{
	if (!ft_strcmp(line, "sa\n") || !ft_strcmp(line, "sb\n")
		|| !ft_strcmp(line, "ss\n"))
		which_swap(ps, line);
	else if (!ft_strcmp(line, "pa\n") || !ft_strcmp(line, "pb\n"))
		which_push(ps, line);
	else if (!ft_strcmp(line, "rra\n") || !ft_strcmp(line, "rrb\n")
		|| !ft_strcmp(line, "rrr\n"))
		which_reverse_rotate(ps, line);
	else if (!ft_strcmp(line, "ra\n") || !ft_strcmp(line, "rb\n")
		|| !ft_strcmp(line, "rr\n"))
		which_rotate(ps, line);
	else
		return (false);
	return (true);
}

void	checker(t_push_swap *ps)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (!which(ps, line))
			return (ft_dprintf(STDERR_FILENO, "Error\n"),
				get_next_line(-1), free(line));
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	if (is_sorted(ps->a) && !ps->b->size)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
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
	checker(&ps);
	ft_dlstclear(&(a.head), free);
	ft_dlstclear(&(b.head), free);
	return (EXIT_SUCCESS);
}
