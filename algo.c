/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 14:48:18 by droly             #+#    #+#             */
/*   Updated: 2016/03/23 18:36:40 by droly            ###   ########.fr       */
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

t_lst	*swap(t_lst *lst_a, t_lst *tmp, t_lst *lst_b)
{
	if (lst_a->next != NULL)
	{
		while (lst_a->next->next != NULL)
			lst_a = lst_a->next;
		if (lst_a->content < lst_a->next->content)
		{
			lst_a = tmp;
			lst_a = swap_ab(lst_a, lst_b, tmp, "sa ");
		}
		lst_a = tmp;
		if (ft_check(lst_a, lst_b, tmp) == 1)
			return (lst_a);
		lst_a = tmp;
	}
	return (lst_a);
}

int		add(t_lst *lst_a, t_lst *tmp, int c)
{
	c = 2147483647;
	while (lst_a != NULL)
	{
		if (c >= lst_a->content)
			c = lst_a->content;
		lst_a = lst_a->next;
	}
	lst_a = tmp;
	return (c);
}

t_lst	*add2(t_lst *lst_a, t_lst *lst_b, t_lst *tmp, int c)
{
	while (lst_a->next != NULL)
		lst_a = lst_a->next;
	while (lst_a->content != c)
	{
		lst_a = tmp;
		lst_a = rotate_r(lst_a, lst_b, tmp, "rra ");
		while (lst_a->next != NULL)
			lst_a = lst_a->next;
	}
	return (lst_a);
}

t_lst	*algo(t_lst *lst_a, t_lst *lst_b, t_lst *tmp, int c)
{
	lst_a = tmp;
	while (ft_check(lst_a, lst_b, tmp) == 0)
	{
		if (ft_check(lst_a = swap(lst_a, tmp, lst_b), lst_b, tmp) == 1)
			return (lst_a);
		c = add(lst_a, tmp, c);
		lst_a = add2(lst_a, lst_b, tmp, c);
		if (lst_a->content == c && ft_check(tmp, lst_b, tmp) == 0)
		{
			lst_a = tmp;
			lst_b = push(lst_b, lst_a, tmp, "pb ");
			lst_a = push2(lst_a, lst_b, tmp);
		}
		if (lst_a == NULL)
			while (lst_b != NULL)
			{
				if (lst_b->next == NULL)
					lst_a = push(lst_a, lst_b, tmp, "pa\n");
				else
					lst_a = push(lst_a, lst_b, tmp, "pa ");
				lst_a = tmp;
				lst_b = push3(lst_b, lst_a, tmp);
			}
	}
	return (lst_a);
}
