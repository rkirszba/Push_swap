/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 17:42:04 by rkirszba          #+#    #+#             */
/*   Updated: 2019/03/04 17:24:23 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sa(t_psnb **alst_na, t_psnb **alst_nb)
{
	t_psnb	*tmp;

	(void)alst_nb;
	if (!*alst_na || !(*alst_na)->next)
		return ;
	tmp = *alst_na;
	*alst_na = (*alst_na)->next;
	tmp->next = tmp->next->next;
	(*alst_na)->next = tmp;
}

void	ps_sb(t_psnb **alst_na, t_psnb **alst_nb)
{
	t_psnb	*tmp;

	(void)alst_na;
	if (!*alst_nb || !(*alst_nb)->next)
		return ;
	tmp = *alst_nb;
	*alst_nb = (*alst_nb)->next;
	tmp->next = tmp->next->next;
	(*alst_nb)->next = tmp;
}

void	ps_ss(t_psnb **alst_na, t_psnb **alst_nb)
{
	ps_sa(alst_na, alst_nb);
	ps_sb(alst_na, alst_nb);
}

void	ps_pa(t_psnb **alst_na, t_psnb **alst_nb)
{
	t_psnb	*tmp;

	if (!*alst_nb)
		return ;
	tmp = (*alst_nb)->next;
	(*alst_nb)->next = *alst_na;
	*alst_na = *alst_nb;
	*alst_nb = tmp;
}

void	ps_pb(t_psnb **alst_na, t_psnb **alst_nb)
{
	t_psnb	*tmp;

	if (!*alst_na)
		return ;
	tmp = (*alst_na)->next;
	(*alst_na)->next = *alst_nb;
	*alst_nb = *alst_na;
	*alst_na = tmp;
}
