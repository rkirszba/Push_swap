/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:37:18 by rkirszba          #+#    #+#             */
/*   Updated: 2019/03/09 13:33:52 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_free_nb(t_psnb **alst)
{
	t_psnb	*tmp;

	while (*alst)
	{
		tmp = *alst;
		*alst = (*alst)->next;
		free(tmp);
	}
}

void	ps_free_inst(t_psinstlst **alst)
{
	t_psinstlst	*tmp;

	while (*alst)
	{
		tmp = *alst;
		*alst = (*alst)->next;
		free(tmp);
	}
}

void	ps_free_nb_inst(t_psnb **alst_n, t_psinstlst **alst_i)
{
	ps_free_nb(alst_n);
	ps_free_inst(alst_i);
}

void	ps_free_nb_nb(t_psnb **alst_na, t_psnb **alst_nb)
{
	ps_free_nb(alst_na);
	ps_free_nb(alst_nb);
}
