/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instructions3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:41:21 by rkirszba          #+#    #+#             */
/*   Updated: 2019/03/04 15:30:33 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rra(t_psnb **alst_na, t_psnb **alst_nb)
{
	t_psnb	*tmp1;
	t_psnb	*tmp2;

	(void)alst_nb;
	if (!*alst_na || !(*alst_na)->next)
		return ;
	tmp1 = *alst_na;
	while (tmp1->next)
		tmp1 = tmp1->next;
	tmp2 = tmp1;
	tmp1->next = *alst_na;
	*alst_na = tmp1;
	while (tmp1->next != tmp2)
		tmp1 = tmp1->next;
	tmp1->next = NULL;
}

void	ps_rrb(t_psnb **alst_na, t_psnb **alst_nb)
{
	t_psnb	*tmp1;
	t_psnb	*tmp2;

	(void)alst_na;
	if (!*alst_nb || !(*alst_nb)->next)
		return ;
	tmp1 = *alst_nb;
	while (tmp1->next)
		tmp1 = tmp1->next;
	tmp2 = tmp1;
	tmp1->next = *alst_nb;
	*alst_nb = tmp1;
	while (tmp1->next != tmp2)
		tmp1 = tmp1->next;
	tmp1->next = NULL;
}

void	ps_rrr(t_psnb **alst_na, t_psnb **alst_nb)
{
	ps_rra(alst_na, alst_nb);
	ps_rrb(alst_na, alst_nb);
}
