/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 14:09:00 by droly             #+#    #+#             */
/*   Updated: 2016/03/10 16:58:34 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	error(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
}

t_lst	*push2(t_lst *lst_2, t_lst *tmp)
{
	tmp = lst_2;
	while (lst_2->next != NULL)
		lst_2 = lst_2->next;
	free(lst_2);
	lst_2 = NULL;
	lst_2 = tmp;
	return (lst_2);
}

t_lst	*push(t_lst *lst_1, t_lst *lst_2, t_lst *tmp)
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
		return (lst_1);
	}
	tmp = lst_1;
	while (lst_1 != NULL)
		lst_1 = lst_1->next;
	lst_1 = malloc(sizeof(t_lst));
	lst_1->content = lst_2->content;
	lst_1->next = NULL;
	lst_1 = tmp;
	return (lst_1);
}

t_lst	swap_ab(t_lst *lst_ab, t_lst *tmp)
{
	int c;

	c = 0;
	while (lst_ab->next != NULL)
		lst_ab = lst_ab->next;
	c = lst_ab->content;
	lst_ab->content = lst_ab->next->content;
	lst_ab->next->content = c;
	lst_ab = tmp;
	return (*lst_ab);
}

t_lst	*put_in_lst(t_lst *lst_a, char **argv, int argc)
{
	int i;
	t_lst *tmp;
	t_lst *lst_b;
	int i2;

	lst_b = NULL;
	argc--;
	i2 = argc;
	tmp = lst_a;
	i = 1;
	while (argc > 0)
	{
		ft_putchar('i');
		if (i2 != argc)
			lst_a = malloc(sizeof(t_lst));
		lst_a->content = ft_atoi(argv[i]);
		if (ft_strcmp(ft_itoa(lst_a->content), argv[i]) != 0)
			error();
		i++;
		argc--;
		lst_a = lst_a->next;
	}
	lst_a = NULL;
	lst_a = tmp;
	while (lst_a->next != NULL)
	{
		ft_putchar('c');
		printf("\nlst a-1 : %d\n", lst_a->content);
		lst_a = lst_a->next;
	}
	lst_b = push(lst_b, lst_a, tmp);
	lst_a = push2(lst_a, tmp);
	while (lst_a != NULL)
	{
		tmp = lst_a;
		printf("\nlst a : %d\n", lst_a->content);
		lst_a = lst_a->next;
	}
	lst_a = tmp;
	lst_b = push(lst_b, lst_a, tmp);
	lst_a = push2(lst_a, tmp);
	while (lst_a != NULL)
	{
		tmp = lst_a;
		printf("\nlst a2 : %d\n", lst_a->content);
		lst_a = lst_a->next;
	}
	lst_a = tmp;
	return (lst_a);
}

int		main(int argc, char **argv)
{
	t_lst *lst_a;

	lst_a = malloc(sizeof(t_lst));
	lst_a = put_in_lst(lst_a, argv, argc);
//	while (lst_a->next != NULL)
//	{
//		printf("\nlst a : %d\n", lst_a->content);
//		lst_a = lst_a->next;
//	}
//	lst_a = lst_a->next;
}
