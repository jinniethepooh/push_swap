/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opr_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 00:44:02 by cchetana          #+#    #+#             */
/*   Updated: 2022/07/20 00:47:04 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ----- swap = swap first-two-element of the stack

void	swap_a(t_info *a, int flag)
{
	int	tmp;
	int	tmp_seq;

	if (flag)
		write(1, "sa\n", 3);
	if (a->cur_size < 2)
		return ;
	tmp = a->tab[0][0];
	tmp_seq = a->tab[0][1];
	a->tab[0][0] = a->tab[1][0];
	a->tab[0][1] = a->tab[1][1];
	a->tab[1][0] = tmp;
	a->tab[1][1] = tmp_seq;
}

void	swap_b(t_info *b, int flag)
{
	int	tmp;
	int	tmp_seq;

	if (flag)
		write(1, "sb\n", 3);
	if (b->cur_size < 2)
		return ;
	tmp = b->tab[0][0];
	tmp_seq = b->tab[0][1];
	b->tab[0][0] = b->tab[1][0];
	b->tab[0][1] = b->tab[1][1];
	b->tab[1][0] = tmp;
	b->tab[1][1] = tmp_seq;
}

void	swap_s(t_info *a, t_info *b, int flag)
{
	if (flag)
		write(1, "ss\n", 3);
	swap_a(a, 0);
	swap_a(b, 0);
}
