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

void	error(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
}

t_lst	put_in_lst(t_lst *lst_a, char **argv, int argc)
{
	int i;
	t_lst *tmp;

	argc--;
	tmp = lst_a;
	i = 1;
	while (argc > 0)
	{
		if (ft_isdigit(argv[i]) == 0)
			error();
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
