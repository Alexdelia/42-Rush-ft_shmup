/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:19:51 by adelille          #+#    #+#             */
/*   Updated: 2022/08/27 18:11:45 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.hpp"
#include "keys.hpp"

static bool choose_play(const env &e)
{
	(void)e;
	// if want option before playing
	//	(difficulty, map, ...)
	return (true);
}

static bool menu_key_handle(env &e, int *key)
{
	move((e.get_win_row() - 1) / 2 + 3, e.get_win_col() / 2 - 2);
	*key = getch();
	if (*key == 'p' || *key == 'P' || *key == '\n')
	{
		if (!choose_play(e))
			return (false);
		return (true);
	}
	else if (*key == 's' || *key == 'S')
	{
		score s(e);
		graphic::print_score(e, s);
		clear();
		graphic::print_menu(e);
		return (true);
	}
	else if (*key == KEY_RESIZE)
	{
		if (!e.resize())
			return (false);
	}
	else if (keys::is_exit(*key))
		return (false);
	*key = 'z';
	return (true);
}

bool	graphic::menu(env &e)
{
	clear();
	graphic::print_menu(e);
	int	key = 'z';
	while (key == 'z' || key == 's' || key == 'S' || key == KEY_RESIZE)
	{
		if (!menu_key_handle(e, &key))
			return (false);
	}

	clear();
	curs_set(0);

	return (true);
}
