/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 01:11:46 by cchetana          #+#    #+#             */
/*   Updated: 2022/07/21 03:28:22 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_info {
	int	**tab;
	int	cur_size;
	int	ori_size;
	int	max;
	int	max_seq;
	int	max_pos;
	int	min;
	int	min_pos;
	int	block_size;
}	t_info;

// ----- VALIDATOR ----- //
int		ft_isdigit(char c);
int		ft_isspace(char c);
int		ft_issign(char c);
int		is_valid_input(char c);
int		is_valid_nbr(char c, long nbr, int digit);
int		is_sort(int **tab, int size, int flag);
void	is_dup_input(t_info *a, t_info *b);

// ----- ERROR HANDLING ----- //
void	error_msg(void);
void	error_usage(int argc);
void	error_malloc(t_info *a, t_info *b);
void	error_invalid_input(t_info *a, t_info *b);
void	error_invalid_instruction(char *ins, t_info *a, t_info *b);

// ----- FREE ----- //
void	free_stack(t_info *a, t_info *b);

// ----- INPUT MANAGEMENT ----- //
void	create_stack(t_info *a, t_info *b, char **s);
void	get_sequence(t_info *a);
int		ncount(char **s, int sz);
int		ps_atoi(const char *str, t_info *a, t_info *b);
int		sublooper(char *s, int flag);

// ----- OPERATION ----- //
// ----- 1) swap ----- //
void	swap_a(t_info *a, int flag);
void	swap_b(t_info *b, int flag);
void	swap_s(t_info *a, t_info *b, int flag);

// ----- 2) push ----- //
void	push_a(t_info *a, t_info *b, int flag);
void	push_b(t_info *a, t_info *b, int flag);

// ----- 3) rotate ----- //
void	rotate_a(t_info *a, int flag);
void	rotate_b(t_info *b, int flag);
void	rotate_r(t_info *a, t_info *b, int flag);

// ----- 4) reverse rotate ----- //
void	reverse_ra(t_info *a, int flag);
void	reverse_rb(t_info *b, int flag);
void	reverse_rr(t_info *a, t_info *b, int flag);

// ----- SORTING ----- //
void	sort_large(t_info *a, t_info *b);
void	push_to_block(t_info *a, t_info *b);
void	sort_three(t_info *a);
void	sort_five(t_info *a, t_info *b);
void	sort_small(t_info *a, t_info *b);
void	push_to_b(t_info *a, t_info *b);

// ----- UTILITIES ----- //
void	sort_asc(t_info *a, t_info *b);
void	sort_dsc(t_info *a, t_info *b);
void	find_max(t_info *s);
void	find_min(t_info *s);
int		find_pos(int nbr, t_info *s);

#endif
