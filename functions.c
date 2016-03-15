/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:22:51 by droly             #+#    #+#             */
/*   Updated: 2016/03/15 17:05:41 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*push2(t_lst *lst_2, t_lst *tmp)
{
	tmp = lst_2;
	while (lst_2->next->next != NULL)
		lst_2 = lst_2->next;
	lst_2->next = NULL;
	lst_2 = tmp;
	return (lst_2);
}

t_lst	*rotate_r(t_lst *lst_ab, t_lst *tmp, char *str)
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
	ft_putstr(str);
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

t_lst	*swap_ab(t_lst *lst_ab, t_lst *tmp, char *str)
{
	int c;

	c = 0;
	tmp = lst_ab;
	while (lst_ab->next->next != NULL)
		lst_ab = lst_ab->next;
	c = lst_ab->content;
	lst_ab->content = lst_ab->next->content;
	lst_ab->next->content = c;
	lst_ab = tmp;
	ft_putstr(str);
	return (lst_ab);
}
