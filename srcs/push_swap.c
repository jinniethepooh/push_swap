/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 00:09:01 by cchetana          #+#    #+#             */
/*   Updated: 2022/07/21 01:48:57 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_init(t_info *s)
{
	s->tab = NULL;
	s->cur_size = 0;
	s->ori_size = 0;
	s->max = 0;
	s->max_seq = 0;
	s->max_pos = 0;
	s->min = 0;
	s->min_pos = 0;
	s->block_size = 0;
}

static void	push_swap(t_info *a, t_info *b)
{
	if (a->ori_size > 60)
	{
		a->block_size = 20 + (a->ori_size / 10);
		push_to_block(a, b);
		sort_large(a, b);
	}
	else if (a->ori_size == 3)
		sort_three(a);
	else if (a->ori_size == 5)
		sort_five(a, b);
	else
	{
		push_to_b(a, b);
		sort_small(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_info	a;
	t_info	b;

	ps_init(&a);
	ps_init(&b);
	if (argc - 1 > 0)
	{
		a.ori_size = argc - 1;
		create_stack(&a, &b, argv);
		get_sequence(&a);
		if (!is_sort(a.tab, a.ori_size, 'a'))
			push_swap(&a, &b);
	}
	free_stack(&a, &b);
	return (0);
}
