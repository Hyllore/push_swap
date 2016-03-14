/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 14:48:18 by droly             #+#    #+#             */
/*   Updated: 2016/03/14 17:05:47 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check(t_lst *lst_a, t_lst *lst_b, t_lst *tmp)
{
	tmp = lst_a;
	if (lst_b != NULL)
		return (0);
	while (lst_a->next != NULL)
	{
		if (lst_a->content < lst_a->next->content)
			return (0);
		lst_a = lst_a->next;
	}
	return (1);
}

t_lst	*algo(t_lst *lst_a, t_lst *lst_b)
{
	t_lst	*tmp;
	int c;

	c = 2147483647;
	tmp = lst_a;
	while (ft_check(lst_a, lst_b, tmp) == 0)
	{
		while (lst_a->next->next != NULL)
			lst_a = lst_a->next;
		if (lst_a->content < lst_a->next->content)
		{
			lst_a = tmp;
			lst_a = swap_ab(lst_a, tmp, "sa ");
		}
		while (lst_a != NULL)
		{
			if (c >= lst_a->content)
				c = lst_a->content;
			lst_a = lst_a->next;
		}
		lst_a = tmp;
		while (lst_a->next != NULL)
			lst_a = lst_a->next;
		while (lst_a->content != c)
		{
			lst_a = tmp;
			lst_a = rotate_r(lst_a, tmp, "rra ");
			while (lst_a->next != NULL)
				lst_a = lst_a->next;
		}
		lst_a = tmp;
		if (lst_a->content == c)
		{
			lst_b = push(lst_b, lst_a, tmp, "pb ");
			lst_a = push2(lst_a, tmp);
		}
		if (lst_a == NULL)
		{
			while (lst_b != NULL)
			{
				lst_a = push(lst_a, lst_b, tmp, "pb ");
				lst_b = push2(lst_b, tmp);
			}
		}
	}
	return (tmp);
}
