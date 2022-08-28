/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:19:51 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 21:51:39 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.hpp"
#include "keys.hpp"

static bool menu_key_handle(env &e, int *key)
{
	move((e.get_win_row() - 1) / 2 + 5, (e.get_win_col() - 1) / 2);
	*key = getch();
	if (*key == '2')
		e.add_multi();
	else if (*key == KEY_RESIZE)
	{
		if (!e.resize())
			return (false);
		clear();
		graphic::print_menu(e);
	}
	else if (keys::is_exit(*key) || *key == 'q' || *key == 'Q')
		return (false);
	return (true);
}

bool	graphic::menu(env &e)
{
	clear();
	graphic::print_menu(e);
	int	key = -1;
	while (key == -1 || key == KEY_RESIZE)
	{
		if (!menu_key_handle(e, &key))
			return (false);
	}

	clear();
	curs_set(0);

	return (true);
}
