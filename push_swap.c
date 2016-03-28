/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 14:09:00 by droly             #+#    #+#             */
/*   Updated: 2016/03/24 12:02:17 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		error(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
}

void		checkdoublon(t_lst *lst_a, t_lst *tmp)
{
	int		tmp2;

	lst_a = tmp;
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

t_lst		*options(char **argv, t_lst *tmp)
{
	tmp->c = 0;
	tmp->v = 0;
	if ((ft_strcmp(argv[1], "-c") == 0 || ft_strcmp(argv[1], "-v") == 0)
			&& argv[2] != NULL)
	{
		if (ft_strcmp(argv[1], "-c") == 0 || ft_strcmp(argv[2], "-c") == 0)
			tmp->c = 1;
		if (ft_strcmp(argv[1], "-v") == 0 || ft_strcmp(argv[2], "-v") == 0)
			tmp->v = 1;
	}
	return (tmp);
}

t_lst		*put_in_lst(t_lst *lst_a, char **argv, int argc, t_lst *lst_b)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	tmp = lst_a;
	tmp = options(argv, tmp);
	i = tmp->v + tmp->c;
	while (argc > i)
	{
		if (argc != i + 1)
			lst_a->next = (t_lst*)malloc(sizeof(t_lst));
		lst_a->content = ft_atoi(argv[argc]);
		if (ft_strcmp(ft_itoa(lst_a->content), argv[argc]) != 0)
			error();
		argc--;
		if (argc != i)
			lst_a = lst_a->next;
	}
	lst_a->next = NULL;
	checkdoublon(lst_a, tmp);
	lst_a = algo(lst_a, lst_b, tmp, 2147483647);
	free(lst_b);
	return (lst_a);
}

int			main(int argc, char **argv)
{
	t_lst	*lst_a;

	lst_a = (t_lst*)malloc(sizeof(t_lst));
	lst_a->next = NULL;
	if (argc == 1)
		return (0);
	lst_a = put_in_lst(lst_a, argv, argc - 1, NULL);
	if (lst_a->c == 1)
	{
		ft_putstr("\n                 \033[1;33mRESULTAT :\033[0m\n");
		while (lst_a)
		{
			ft_putstr("                     \033[0;32m");
			ft_putnbr(lst_a->content);
			ft_putstr("\033[0m\n");
			lst_a = lst_a->next;
		}
	}
	free(lst_a);
	return (0);
}
