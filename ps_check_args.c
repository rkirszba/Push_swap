/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:52:51 by rkirszba          #+#    #+#             */
/*   Updated: 2019/03/06 21:02:28 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_check_dupli(int nb, t_psnb **alst_n, char **tab)
{
	t_psnb *tmp;

	tmp = *alst_n;
	while (tmp)
	{
		if (nb == tmp->nb)
			ps_write_error_ck(alst_n, tab);
		tmp = tmp->next;
	}
}

static void	ps_make_stack(int nb, t_psnb **alst_n, char **tab)
{
	t_psnb	*new;
	t_psnb	*tmp;

	tmp = *alst_n;
	ps_check_dupli(nb, alst_n, tab);
	if (!(new = (t_psnb*)malloc(sizeof(*new))))
		exit(1);
	new->nb = nb;
	new->next = NULL;
	if (!(*alst_n))
	{
		*alst_n = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return ;
}

static void	ps_check_arg(char *arg, t_psnb **alst_n, char **tab)
{
	int		i;
	long	nb;

	i = 0;
	if ((arg[0] == '+' || arg[0] == '-') && arg[1])
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
		{
			free(arg);
			ps_write_error_ck(alst_n, tab);
		}
		i++;
	}
	nb = ps_give_nb(arg);
	if (nb < INT_MIN || nb > INT_MAX)
		ps_write_error_ck(alst_n, tab);
	ps_make_stack((int)nb, alst_n, tab);
}

int			ps_check_args(char *arg, t_psnb **alst_n)
{
	int			i;
	static int	j = 0;
	int			v;
	char		**tab;

	i = 0;
	v = 0;
	j++;
	if (!(tab = ft_strsplit(arg, ' ')))
		exit(1);
	if (tab[i] && !ft_strcmp(tab[i], "-v") && j == 1)
	{
		free(tab[i]);
		v = 1;
		i++;
	}
	while (tab[i])
	{
		ps_check_arg(tab[i], alst_n, tab);
		i++;
	}
	free(tab);
	return (v);
}
