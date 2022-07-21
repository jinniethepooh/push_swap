/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 00:19:11 by cchetana          #+#    #+#             */
/*   Updated: 2022/07/20 14:11:43 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		++len;
	return (len);
}

static int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	if (!s1 || !s2)
		return (-1);
	i = -1;
	while (++i < n && (s1[i] || s2[i]))
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

static int	loop_join(char *src, char *dst)
{
	int	i;

	i = 0;
	while (src && src[i])
	{
		dst[i] = src[i];
		++i;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	res = (char *)malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!res)
		return (NULL);
	i = loop_join((char *)s1, res);
	i += loop_join((char *)s2, &res[i]);
	res[i] = '\0';
	if (s1)
		free((void *)s1);
	return (res);
}

void	do_ins(char *ins, t_info *a, t_info *b)
{
	if (ft_strncmp(ins, "sa\n", 3) == 0)
		swap_a(a, 0);
	else if (ft_strncmp(ins, "sb\n", 3) == 0)
		swap_b(b, 0);
	else if (ft_strncmp(ins, "ss\n", 3) == 0)
		swap_s(a, b, 0);
	else if (ft_strncmp(ins, "pa\n", 3) == 0)
		push_a(a, b, 0);
	else if (ft_strncmp(ins, "pb\n", 3) == 0)
		push_b(a, b, 0);
	else if (ft_strncmp(ins, "ra\n", 3) == 0)
		rotate_a(a, 0);
	else if (ft_strncmp(ins, "rb\n", 3) == 0)
		rotate_b(b, 0);
	else if (ft_strncmp(ins, "rr\n", 3) == 0)
		rotate_r(a, b, 0);
	else if (ft_strncmp(ins, "rra\n", 4) == 0)
		reverse_ra(a, 0);
	else if (ft_strncmp(ins, "rrb\n", 4) == 0)
		reverse_rb(b, 0);
	else if (ft_strncmp(ins, "rrr\n", 4) == 0)
		reverse_rr(a, b, 0);
	else
		error_invalid_instruction(ins, a, b);
}
