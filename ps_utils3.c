/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 13:58:40 by rkirszba          #+#    #+#             */
/*   Updated: 2019/03/04 15:41:57 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_give_width(int nb, int hvalue)
{
	int		wdth;

	wdth = (nb < 0 ? -nb : nb) * 640 / hvalue;
	return (wdth);
}

int		ps_give_whght(int entries)
{
	int		i;

	if (!entries)
		return (1024);
	i = 0;
	while (i * entries <= 1024)
		i++;
	i--;
	if (i * entries >= 1300)
		return (1024);
	return (i * entries);
}

int		ps_give_delay(t_psinstlst *alst_i)
{
	int		i;

	i = 0;
	while (alst_i)
	{
		i++;
		alst_i = alst_i->next;
	}
	if (i <= 15)
		return (1000);
	if (i >= 7500)
		return (0);
	return (7500 / i);
}

void	ps_fill_background(t_pssdl *stct, SDL_Rect rect)
{
	SDL_SetRenderDrawColor(stct->renderer, 38, 81, 240, 255);
	SDL_RenderClear(stct->renderer);
	SDL_SetRenderDrawColor(stct->renderer, 245, 24, 10, 255);
	rect.x = 640;
	rect.y = 0;
	rect.w = 640;
	rect.h = stct->whght;
	SDL_RenderFillRect(stct->renderer, &rect);
}

void	ps_choose_color(t_pssdl *stct, int nb, int stack)
{
	if (!stack)
	{
		if (nb >= 0)
			SDL_SetRenderDrawColor(stct->renderer, 213, 16, 69, 255);
		else
			SDL_SetRenderDrawColor(stct->renderer, 253, 24, 142, 255);
	}
	else
	{
		if (nb >= 0)
			SDL_SetRenderDrawColor(stct->renderer, 255, 244, 4, 255);
		else
			SDL_SetRenderDrawColor(stct->renderer, 253, 247, 115, 255);
	}
}
