/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:11:23 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/26 15:54:37 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < n - 1)
	{
		j = -1;
		while (++j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int	*push_atoarr(t_push_swap *ps)
{
	int		*arr;
	int		i;
	t_dlist	*tmp;

	i = -1;
	tmp = ps->a->head;
	arr = malloc(sizeof(int) * ps->a->size);
	if (!arr)
	{
		ft_dprintf(STDERR_FILENO, "Error\n");
		ft_dlstclear(&(ps->a->head), free);
		exit(EXIT_FAILURE);
	}
	while (++i < ps->a->size)
	{
		arr[i] = *(int *)tmp->content;
		tmp = tmp->next;
	}
	return (arr);
}

void	push_swap(t_push_swap *ps)
{
	int		*arr;

	if (is_sorted(ps->a))
		return ;
	if (ps->a->size <= 5)
		return (small_sort(ps));
	if (is_rev_sorted(ps->a))
		return (reverse_sort(ps->a, ps->b));
	arr = push_atoarr(ps);
	bubble_sort(arr, ps->a->size);
	push_atob(ps, arr);
	push_btoa(ps, arr);
	free(arr);
}
