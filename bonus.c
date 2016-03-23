/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 18:35:29 by droly             #+#    #+#             */
/*   Updated: 2016/03/23 18:37:19 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*push3(t_lst *lst_2, t_lst *lst_add, t_lst *tmp)
{
	t_lst *tmp2;

	tmp2 = lst_2;
	if (lst_2->next == NULL)
	{
		lst_2 = NULL;
		if (tmp->v == 1)
			ft_option(lst_add, lst_2, tmp);
		return (lst_2);
	}
	while (lst_2->next->next != NULL)
		lst_2 = lst_2->next;
	lst_2->next = NULL;
	lst_2 = tmp2;
	if (tmp->v == 1)
		ft_option(lst_add, lst_2, tmp);
	return (lst_2);
}

void	ft_option(t_lst *lst_a, t_lst *lst_b, t_lst *tmp)
{
	if (tmp->v == 1)
	{
		ft_putstr("\n\033[0;36mPile A :               Pile B :\033[0m\n");
		while (lst_a != NULL || lst_b != NULL)
		{
			if (lst_a == NULL)
				ft_putstr("   \033[0;31m/\033[0m");
			if (lst_a != NULL)
			{
				ft_putstr("   ");
				ft_putnbr(lst_a->content);
				lst_a = lst_a->next;
			}
			if (lst_b == NULL)
				ft_putstr("                      \033[0;31m/\033[0m\n");
			if (lst_b != NULL)
			{
				ft_putstr("                      ");
				ft_putnbr(lst_b->content);
				ft_putchar('\n');
				lst_b = lst_b->next;
			}
		}
	}
}
