/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opr_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 00:34:00 by cchetana          #+#    #+#             */
/*   Updated: 2022/07/20 00:37:01 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push_a = take the first element at the top of b and put it at the top of a.
// (push to a)

static void	run_core_stack(t_info *s)
{
	int	i;

	i = 0;
	while (i < s->cur_size - 1)
	{
		s->tab[i][0] = s->tab[i + 1][0];
		s->tab[i][1] = s->tab[i + 1][1];
		++i;
	}
	s->tab[i][0] = 0;
	s->tab[i][1] = 0;
	s->cur_size -= 1;
}

static void	run_push_stack(t_info *s, int tmp, int tmp_seq)
{
	int	i;

	i = s->cur_size;
	while (i > 0)
	{
		s->tab[i][0] = s->tab[i - 1][0];
		s->tab[i][1] = s->tab[i - 1][1];
		--i;
	}
	s->tab[0][0] = tmp;
	s->tab[0][1] = tmp_seq;
	s->cur_size += 1;
}

void	push_a(t_info *a, t_info *b, int flag)
{
	int	tmp;
	int	tmp_seq;

	if (flag)
		write(1, "pa\n", 3);
	if (b->cur_size == 0)
		return ;
	tmp = b->tab[0][0];
	tmp_seq = b->tab[0][1];
	run_core_stack(b);
	run_push_stack(a, tmp, tmp_seq);
}

void	push_b(t_info *a, t_info *b, int flag)
{
	int	tmp;
	int	tmp_seq;

	if (flag)
		write(1, "pb\n", 3);
	if (a->cur_size == 0)
		return ;
	tmp = a->tab[0][0];
	tmp_seq = a->tab[0][1];
	run_core_stack(a);
	run_push_stack(b, tmp, tmp_seq);
}
