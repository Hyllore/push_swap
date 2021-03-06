/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:22:51 by droly             #+#    #+#             */
/*   Updated: 2016/03/23 18:36:16 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*push2(t_lst *lst_2, t_lst *lst_add, t_lst *tmp)
{
	tmp = lst_2;
	if (lst_2->next == NULL)
	{
		lst_2 = NULL;
		if (tmp->v == 1)
			ft_option(lst_2, lst_add, tmp);
		return (lst_2);
	}
	while (lst_2->next->next != NULL)
		lst_2 = lst_2->next;
	lst_2->next = NULL;
	lst_2 = tmp;
	if (tmp->v == 1)
		ft_option(lst_2, lst_add, tmp);
	return (lst_2);
}

t_lst	*rotate_r(t_lst *lst_ab, t_lst *lst_add, t_lst *tmp, char *str)
{
	int tmp2;

	tmp2 = lst_ab->content;
	tmp = lst_ab;
	while (lst_ab->next != NULL)
	{
		lst_ab->content = lst_ab->next->content;
		lst_ab = lst_ab->next;
	}
	lst_ab->content = tmp2;
	lst_ab = tmp;
	if (ft_check(lst_ab, lst_add, tmp) == 1)
		str = "rra\n";
	ft_putstr(str);
	if (tmp->v == 1)
		ft_option(lst_ab, lst_add, tmp);
	return (lst_ab);
}

t_lst	*rotate(t_lst *lst_ab, t_lst *tmp)
{
	int tmp2;
	int tmp3;

	tmp3 = 0;
	tmp2 = 0;
	tmp = lst_ab;
	while (lst_ab->next != NULL)
		lst_ab = lst_ab->next;
	tmp2 = lst_ab->content;
	lst_ab = tmp;
	while (lst_ab != NULL)
	{
		tmp3 = lst_ab->content;
		lst_ab->content = tmp2;
		tmp2 = tmp3;
		lst_ab = lst_ab->next;
	}
	lst_ab = tmp;
	return (lst_ab);
}

t_lst	*push(t_lst *lst_1, t_lst *lst_2, t_lst *tmp, char *str)
{
	while (lst_2->next != NULL)
		lst_2 = lst_2->next;
	if (lst_1 == NULL)
	{
		lst_1 = malloc(sizeof(t_lst));
		lst_1->next = NULL;
		tmp = lst_1;
		lst_1->content = lst_2->content;
		lst_1 = tmp;
		ft_putstr(str);
		return (lst_1);
	}
	tmp = lst_1;
	while (lst_1->next != NULL)
		lst_1 = lst_1->next;
	lst_1->next = malloc(sizeof(t_lst));
	lst_1->next->next = NULL;
	lst_1->next->content = lst_2->content;
	ft_putstr(str);
	lst_1 = tmp;
	return (lst_1);
}

t_lst	*swap_ab(t_lst *lst_a, t_lst *lst_b, t_lst *tmp, char *str)
{
	int c;

	c = 0;
	tmp = lst_a;
	while (lst_a->next->next != NULL)
		lst_a = lst_a->next;
	c = lst_a->content;
	lst_a->content = lst_a->next->content;
	lst_a->next->content = c;
	lst_a = tmp;
	if (ft_check(lst_a, lst_b, tmp))
		str = "sa\n";
	ft_putstr(str);
	if (tmp->v == 1)
		ft_option(lst_a, lst_b, tmp);
	return (lst_a);
}
