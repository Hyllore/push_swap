/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 14:09:00 by droly             #+#    #+#             */
/*   Updated: 2016/03/15 11:38:11 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	error(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
}

void	checkdoublon(t_lst *lst_a, t_lst *tmp)
{
	int tmp2;

	tmp2 = 0;
	while (lst_a != NULL)
	{
		tmp2 = lst_a->content;
		tmp = lst_a->next;
		while (tmp != NULL)
		{
			if (tmp2 == tmp->content)
				error();
			tmp = tmp->next;
		}
		lst_a = lst_a->next;
	}
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
	i = argc;
	while (argc > 0)
	{
		if (argc != 1)
			lst_a->next = (t_lst*)malloc(sizeof(t_lst));
		lst_a->content = ft_atoi(argv[i]);
		if (ft_strcmp(ft_itoa(lst_a->content), argv[i]) != 0)
			error();
		i--;
		argc--;
		if (argc != 0)
			lst_a = lst_a->next;
	}
	lst_a->next = NULL;
	lst_a = tmp;
	checkdoublon(lst_a, tmp);
	lst_a = algo(lst_a, lst_b);
	lst_a = tmp;
	return (lst_a);
}

int		main(int argc, char **argv)
{
	t_lst *lst_a;

	lst_a = (t_lst*)malloc(sizeof(t_lst));
	lst_a->next = NULL;
	lst_a = put_in_lst(lst_a, argv, argc);
	ft_putstr("lst a :");
	while (lst_a != NULL)
	{
		printf(" %d\n", lst_a->content);
		lst_a = lst_a->next;
	}
}
