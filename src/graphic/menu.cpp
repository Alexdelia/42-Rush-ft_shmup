/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:19:51 by adelille          #+#    #+#             */
/*   Updated: 2022/08/26 22:52:58 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"

static bool choose_play(const env &e)
{
	// if want option before playing
	//	(difficulty, map, ...)
	return (true);
}

static bool menu_key_handle(const env &e)
{
	move((e.get_row() - 1) / 2 + 3, e.get_col() / 2 - 2);
	e.key = getch();
	if (e.key == 'p' || e.key == 'P' || e.key == '\n')
	{
		if (!choose_play(e))
			return (false);
	}
	else if (e.key == 's' || e.key == 'S')
	{
		const score s;
		if (!graphic::print_score(e, s))
			return (false);
	}
	else if (e.key == KEY_RESIZE)
	{
		if (!e.resize(e))
			return (false);
	}
	else
		return (false);
	return (true);
}

bool	graphic::menu(const env &e)
{
	e.key = 's';
	while (e.key == 's' || e.key == 'S' || e.key == KEY_RESIZE)
	{
		clear();
		print_menu(e);
		if (!menu_key_handle(e))
			return (false);
	}

	clear();
	curs_set(0);

	return (true);
}
