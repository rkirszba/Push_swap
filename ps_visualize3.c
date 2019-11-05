/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_visualize3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 12:29:25 by rkirszba          #+#    #+#             */
/*   Updated: 2019/03/09 12:32:28 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_show_state_ko(t_psnb *alst, t_pssdl *stct, t_rect *rect, int stack)
{
	int		i;
	int		j;

	j = 0;
	i = ps_give_entries(alst);
	ps_fill_rect(rect, alst);
	while (--i >= 0)
	{
		if (rect[i].nb >= 0)
			SDL_SetRenderDrawColor(stct->renderer, 255, 255, 255, 255);
		else
			SDL_SetRenderDrawColor(stct->renderer, 212, 220, 218, 255);
		rect[i].wdth = ps_give_width(rect[i].nb, stct->hvalue);
		rect[i].rect.x = (640 - rect[i].wdth) / 2 + (!stack ? 0 : 640);
		rect[i].rect.y = stct->whght - (stct->hght * (j + 1));
		rect[i].rect.w = (!rect[i].nb ? 1 : rect[i].wdth);
		rect[i].rect.h = stct->hght;
		SDL_RenderFillRect(stct->renderer, &(rect[i].rect));
		j++;
	}
}

void	ps_visualize_ko(t_pslsts *lsts, t_pssdl *stct)
{
	t_rect		*rect1;
	t_rect		*rect2;
	SDL_Rect	rect;

	rect.x = 0;
	rect1 = NULL;
	rect2 = NULL;
	SDL_SetRenderDrawColor(stct->renderer, 0, 0, 0, 255);
	SDL_RenderClear(stct->renderer);
	if (!(rect1 = (t_rect*)malloc(sizeof(*rect1)
	* ps_give_entries(lsts->alst_na))))
		exit(1);
	if (!(rect2 = (t_rect*)malloc(sizeof(*rect2)
	* ps_give_entries(lsts->alst_nb))))
		exit(1);
	ps_show_state_ko(lsts->alst_na, stct, rect1, 0);
	ps_show_state_ko(lsts->alst_nb, stct, rect2, 1);
	SDL_RenderPresent(stct->renderer);
	if (rect1)
		free(rect1);
	if (rect2)
		free(rect2);
}
