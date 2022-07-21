/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opr_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 00:37:11 by cchetana          #+#    #+#             */
/*   Updated: 2022/07/20 00:39:26 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// reverse rotate a =   shift down all elements of stack a by 1
//                      the last element becomes the first one

static void	run_rev_stack(t_info *s)
{
	int	i;
	int	tmp;
	int	tmp_seq;

	i = s->cur_size - 1;
	tmp = s->tab[i][0];
	tmp_seq = s->tab[i][1];
	while (i > 0)
	{
		s->tab[i][0] = s->tab[i - 1][0];
		s->tab[i][1] = s->tab[i - 1][1];
		--i;
	}
	s->tab[i][0] = tmp;
	s->tab[i][1] = tmp_seq;
}

void	reverse_ra(t_info *a, int flag)
{
	if (flag)
		write(1, "rra\n", 4);
	if (a->cur_size < 2)
		return ;
	run_rev_stack(a);
}

void	reverse_rb(t_info *b, int flag)
{
	if (flag)
		write(1, "rrb\n", 4);
	if (b->cur_size < 2)
		return ;
	run_rev_stack(b);
}

void	reverse_rr(t_info *a, t_info *b, int flag)
{
	if (flag)
		write(1, "rrr\n", 4);
	reverse_ra(a, 0);
	reverse_rb(b, 0);
}
