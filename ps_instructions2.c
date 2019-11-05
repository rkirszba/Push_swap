/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instructions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:23:28 by rkirszba          #+#    #+#             */
/*   Updated: 2019/03/04 15:25:49 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_ra(t_psnb **alst_na, t_psnb **alst_nb)
{
	t_psnb	*tmp;

	(void)alst_nb;
	if (!*alst_na || !(*alst_na)->next)
		return ;
	tmp = *alst_na;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *alst_na;
	*alst_na = (*alst_na)->next;
	tmp->next->next = NULL;
}

void	ps_rb(t_psnb **alst_na, t_psnb **alst_nb)
{
	t_psnb	*tmp;

	(void)alst_na;
	if (!*alst_nb || !(*alst_nb)->next)
		return ;
	tmp = *alst_nb;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *alst_nb;
	*alst_nb = (*alst_nb)->next;
	tmp->next->next = NULL;
}

void	ps_rr(t_psnb **alst_na, t_psnb **alst_nb)
{
	ps_ra(alst_na, alst_nb);
	ps_rb(alst_na, alst_nb);
}
