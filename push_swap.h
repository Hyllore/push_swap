/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:57:08 by droly             #+#    #+#             */
/*   Updated: 2016/03/15 11:38:00 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct		s_lst
{
	int				content;
	struct s_lst	*next;
}					t_lst;

t_lst	*push2(t_lst *lst_2, t_lst *tmp);
t_lst	*rotate_r(t_lst *lst_ab, t_lst *tmp, char *str);
t_lst	*rotate(t_lst *lst_ab, t_lst *tmp);
t_lst	*push(t_lst *lst_1, t_lst *lst_2, t_lst *tmp, char *str);
t_lst	*swap_ab(t_lst *lst_ab, t_lst *tmp, char *str);
void	error(void);
void	checkdoublon(t_lst *lst_a, t_lst *tmp);
t_lst	*put_in_lst(t_lst *lst_a, char **argv, int argc);
t_lst	*algo(t_lst *lst_a, t_lst *lst_b);
int		ft_check(t_lst *lst_a, t_lst *lst_b, t_lst *tmp);

#endif
