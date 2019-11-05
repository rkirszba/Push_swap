/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_b2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:44:07 by rkirszba          #+#    #+#             */
/*   Updated: 2019/03/04 15:43:59 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_last_is_min(t_psnb *alst_nb)
{
	int		min;

	if (!alst_nb)
		return (0);
	min = alst_nb->nb;
	while (alst_nb->next)
	{
		if (alst_nb->nb < min)
			min = alst_nb->nb;
		alst_nb = alst_nb->next;
	}
	if (min > alst_nb->nb)
		return (1);
	return (0);
}
