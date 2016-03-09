/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 14:09:00 by droly             #+#    #+#             */
/*   Updated: 2016/03/07 17:48:41 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	error(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
}

t_lst	push(t_lst *lst_1, t_lst *lst_2, t_lst *tmp)
{
	if (lst_1 == NULL)
	{
		lst_1 = malloc(sizeof(t_lst));
		lst_1->next = NULL;
	}
	tmp = lst_1;
	while (lst_2->next->next != NULL)
		lst_2 = lst_2->next;
	while (lst_1->next != NULL)
		lst_1 = lst_1->next;
	lst_1->content = lst_2->content;
	lst_1 = tmp;
	ft_putnbr(lst_1->next->content);
	return (*lst_1);
}

t_lst	swap_ab(t_lst *lst_ab, t_lst *tmp)
{
	int c;

	c = 0;
	while (lst_ab->next->next->next != NULL)
		lst_ab = lst_ab->next;
	c = lst_ab->content;
	lst_ab->content = lst_ab->next->content;
	lst_ab->next->content = c;
	lst_ab = tmp;
	return (*lst_ab);
}

t_lst	put_in_lst(t_lst *lst_a, char **argv, int argc)
{
	int i;
	t_lst *tmp;
	t_lst *lst_b;

	argc--;
	tmp = lst_a;
	i = 1;
	while (argc > 0)
	{
		lst_a->next = malloc(sizeof(t_lst));
		lst_a->content = ft_atoi(argv[i]);
		if (ft_strcmp(ft_itoa(lst_a->content), argv[i]) != 0)
			error();
		i++;
		argc--;
		lst_a = lst_a->next;
	}
	lst_a->next = NULL;
	lst_a = tmp;
	*lst_b = push(lst_b, lst_a, tmp);
	ft_putchar('c');
	while (lst_b->next != NULL)
	{
		ft_putchar('c');
		printf("lst b : %d", lst_b->content);
		lst_b = lst_b->next;
	}
	return (*lst_a);
}

int		main(int argc, char **argv)
{
	t_lst *lst_a;

	lst_a = (t_lst*)malloc(sizeof(t_lst));
	*lst_a = put_in_lst(lst_a, argv, argc);
	while (lst_a->next != NULL)
	{
		ft_putnbr(lst_a->content);
		lst_a = lst_a->next;
	}
	lst_a = lst_a->next;
}
