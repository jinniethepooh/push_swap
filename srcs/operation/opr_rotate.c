/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opr_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 00:39:32 by cchetana          #+#    #+#             */
/*   Updated: 2022/07/20 00:43:57 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rot a =  shift up all elements of stack a by 1
//          the first element becomes the last one

static void	run_rot_stack(t_info *s)
{
	int	i;
	int	tmp;
	int	tmp_seq;

	i = 0;
	tmp = s->tab[i][0];
	tmp_seq = s->tab[i][1];
	while (i < s->cur_size - 1)
	{
		s->tab[i][0] = s->tab[i + 1][0];
		s->tab[i][1] = s->tab[i + 1][1];
		++i;
	}
	s->tab[i][0] = tmp;
	s->tab[i][1] = tmp_seq;
}

void	rotate_a(t_info *a, int flag)
{
	if (flag)
		write(1, "ra\n", 3);
	if (a->cur_size < 2)
		return ;
	run_rot_stack(a);
}

void	rotate_b(t_info *b, int flag)
{
	if (flag)
		write(1, "rb\n", 3);
	if (b->cur_size < 2)
		return ;
	run_rot_stack(b);
}

void	rotate_r(t_info *a, t_info *b, int flag)
{
	if (flag)
		write(1, "rr\n", 3);
	rotate_a(a, 0);
	rotate_b(b, 0);
}
