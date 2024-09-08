/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:12:50 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/30 16:27:22 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_stack
{
	t_dlist	*head;
	int		size;
}	t_stack;

typedef struct s_push_swap
{
	t_stack	*a;
	t_stack	*b;
	int		ac;
	char	**av;
	int		min;
	int		max;
}	t_push_swap;

// atob.c
bool	is_a_before_range(t_stack *a, int *arr, int min);
bool	is_a_in_range(t_stack *a, int *arr, int min, int max);
void	push_or_rotate(t_push_swap *ps, int *arr);
int		set_range(int size);
void	push_atob(t_push_swap *ps, int *arr);

// btoa.c
void	push_btoa(t_push_swap *ps, int *arr);

// checker.c
bool	which(t_push_swap *ps, char *line);
void	checker(t_push_swap *ps);

// init.c
bool	init_stack(t_stack *a, int n);
bool	is_duplicate(t_stack *a, int n);

// main.c
void	print(void *content);

// median.c
bool	is_nearest_above_median(t_stack *a, int *arr, int min, int max);
bool	is_smallest_above_median(t_stack *a, int *arr, int size);
bool	is_biggest_above_median(t_stack *b, int *arr, int size);

// parse.c
void	free_2d(char **d);
bool	parse_args(t_push_swap *ps);
bool	parse_args_again(t_push_swap *ps, char **args);
bool	check_str(char *s);
bool	check_null(char *s);

// push_swap.c
void	bubble_sort(int *arr, int n);
int		*push_atoarr(t_push_swap *ps);
void	push_swap(t_push_swap *ps);

// push.c
void	set_stack_y(t_stack *y, t_dlist *tmp);
bool	push(t_stack *x, t_stack *y);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

// rev_rotate.c
bool	reverse_rotate(t_stack *x);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

// rotate.c
bool	rotate(t_stack *x);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

// small_sort.c
void	small_sort(t_push_swap *ps);
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	sort_four(t_push_swap *ps);
void	sort_five(t_push_swap *ps);

// sort.c
bool	is_sorted(t_stack *a);
bool	is_rev_sorted(t_stack *a);
void	reverse_sort(t_stack *a, t_stack *b);

// swap.c
bool	swap(t_stack *x);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

// tabs.c
void	clean_tabs(char *s);

// which.c
void	which_swap(t_push_swap *ps, char *line);
void	which_push(t_push_swap *ps, char *line);
void	which_rotate(t_push_swap *ps, char *line);
void	which_reverse_rotate(t_push_swap *ps, char *line);

#endif // PUSH_SWAP_H
