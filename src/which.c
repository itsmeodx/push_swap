/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:06:28 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/25 16:08:34 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	which_swap(t_push_swap *ps, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		swap(ps->a);
	else if (!ft_strcmp(line, "sb\n"))
		swap(ps->b);
	else if (!ft_strcmp(line, "ss\n"))
	{
		swap(ps->a);
		swap(ps->b);
	}
}

void	which_push(t_push_swap *ps, char *line)
{
	if (!ft_strcmp(line, "pa\n"))
		push(ps->b, ps->a);
	else if (!ft_strcmp(line, "pb\n"))
		push(ps->a, ps->b);
}

void	which_rotate(t_push_swap *ps, char *line)
{
	if (!ft_strcmp(line, "ra\n"))
		rotate(ps->a);
	else if (!ft_strcmp(line, "rb\n"))
		rotate(ps->b);
	else if (!ft_strcmp(line, "rr\n"))
	{
		rotate(ps->a);
		rotate(ps->b);
	}
}

void	which_reverse_rotate(t_push_swap *ps, char *line)
{
	if (!ft_strcmp(line, "rra\n"))
		reverse_rotate(ps->a);
	else if (!ft_strcmp(line, "rrb\n"))
		reverse_rotate(ps->b);
	else if (!ft_strcmp(line, "rrr\n"))
	{
		reverse_rotate(ps->a);
		reverse_rotate(ps->b);
	}
}
