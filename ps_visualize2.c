/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_visualize2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 12:02:36 by rkirszba          #+#    #+#             */
/*   Updated: 2019/03/09 12:32:01 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_show_state_ok_neg(t_psnb *alst, t_pssdl *stct, t_rect *rect)
{
	int		i;
	int		j;

	j = 0;
	i = ps_give_entries(alst);
	ps_fill_rect(rect, alst);
	while (--i >= 0)
	{
		if (rect[i].nb >= 0)
			SDL_SetRenderDrawColor(stct->renderer, 213, 16, 69, 255);
		else
			SDL_SetRenderDrawColor(stct->renderer, 253, 24, 142, 255);
		rect[i].wdth = ps_give_width(rect[i].nb, stct->hvalue);
		rect[i].rect.x = (1280 - rect[i].wdth) / 2;
		rect[i].rect.y = stct->whght - (stct->hght * (j + 1));
		rect[i].rect.w = (!rect[i].nb ? 1 : rect[i].wdth);
		rect[i].rect.h = stct->hght;
		SDL_RenderFillRect(stct->renderer, &(rect[i].rect));
		j++;
	}
}

void	ps_show_state_ok(t_psnb *alst, t_pssdl *stct, t_rect *rect)
{
	int		i;
	int		j;

	j = 0;
	i = ps_give_entries(alst);
	ps_fill_rect(rect, alst);
	while (--i >= 0)
	{
		if (rect[i].nb >= 0)
			SDL_SetRenderDrawColor(stct->renderer, 38, 81, 240, 255);
		else
			SDL_SetRenderDrawColor(stct->renderer, 123, 151, 247, 255);
		rect[i].wdth = ps_give_width(rect[i].nb, stct->hvalue);
		rect[i].rect.x = (1280 - rect[i].wdth) / 2;
		rect[i].rect.y = stct->whght - (stct->hght * (j + 1));
		rect[i].rect.w = (!rect[i].nb ? 1 : rect[i].wdth);
		rect[i].rect.h = stct->hght;
		SDL_RenderFillRect(stct->renderer, &(rect[i].rect));
		j++;
	}
}

void	ps_sparkle(t_pslsts *lsts, t_pssdl *stct, t_rect *rect1)
{
	SDL_SetRenderDrawColor(stct->renderer, 213, 16, 69, 255);
	SDL_RenderClear(stct->renderer);
	ps_show_state_ok(lsts->alst_na, stct, rect1);
	SDL_RenderPresent(stct->renderer);
	SDL_Delay(400);
	SDL_SetRenderDrawColor(stct->renderer, 38, 81, 240, 25);
	SDL_RenderClear(stct->renderer);
	ps_show_state_ok_neg(lsts->alst_na, stct, rect1);
	SDL_RenderPresent(stct->renderer);
	SDL_Delay(400);
}

void	ps_visualize_ok(t_pslsts *lsts, t_pssdl *stct)
{
	t_rect		*rect1;
	SDL_Rect	rect;
	int			i;

	i = 0;
	rect.x = 0;
	rect1 = NULL;
	if (!(rect1 = (t_rect*)malloc(sizeof(*rect1)
	* ps_give_entries(lsts->alst_na))))
		exit(1);
	while (i < 5)
	{
		ps_sparkle(lsts, stct, rect1);
		i++;
	}
	SDL_SetRenderDrawColor(stct->renderer, 213, 16, 69, 255);
	SDL_RenderClear(stct->renderer);
	ps_show_state_ok(lsts->alst_na, stct, rect1);
	SDL_RenderPresent(stct->renderer);
	if (rect1)
		free(rect1);
}

void	ps_check_visualizer(t_pslsts *lsts, t_pssdl *stct)
{
	t_psnb	*tmp;

	if (!lsts->alst_na)
	{
		ps_visualize_ko(lsts, stct);
		return ;
	}
	tmp = lsts->alst_na;
	while (tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
		{
			ps_visualize_ko(lsts, stct);
			return ;
		}
		tmp = tmp->next;
	}
	if (lsts->alst_nb)
		ps_visualize_ko(lsts, stct);
	else
		ps_visualize_ok(lsts, stct);
}
