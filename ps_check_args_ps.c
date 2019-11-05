/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_args_ps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:33:07 by rkirszba          #+#    #+#             */
/*   Updated: 2019/03/06 21:02:22 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_write_error_ps(t_pslsts *lsts, char **tab)
{
	write(1, "Error\n", 6);
	ps_free_nb(&(lsts->alst_na));
	free(tab);
	free(lsts);
	exit(1);
}

static void	ps_check_dupli_ps(int nb, t_pslsts *lsts, char **tab)
{
	t_psnb *tmp;

	tmp = lsts->alst_na;
	while (tmp)
	{
		if (nb == tmp->nb)
			ps_write_error_ps(lsts, tab);
		tmp = tmp->next;
	}
}

static void	ps_make_stack_ps(int nb, t_pslsts *lsts, char **tab)
{
	t_psnb	*new;
	t_psnb	*tmp;

	tmp = lsts->alst_na;
	ps_check_dupli_ps(nb, lsts, tab);
	if (!(new = (t_psnb*)malloc(sizeof(*new))))
		exit(1);
	new->nb = nb;
	new->next = NULL;
	if (!(lsts->alst_na))
	{
		lsts->alst_na = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return ;
}

static void	ps_check_arg_ps(char *arg, t_pslsts *lsts, char **tab)
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
			ps_write_error_ps(lsts, tab);
		}
		i++;
	}
	nb = ps_give_nb(arg);
	if (nb < INT_MIN || nb > INT_MAX)
		ps_write_error_ps(lsts, tab);
	ps_make_stack_ps((int)nb, lsts, tab);
}

void		ps_check_args_ps(char *arg, t_pslsts *lsts)
{
	int		i;
	char	**tab;

	i = 0;
	if (!(tab = ft_strsplit(arg, ' ')))
		exit(1);
	while (tab[i])
	{
		ps_check_arg_ps(tab[i], lsts, tab);
		i++;
	}
	free(tab);
}
