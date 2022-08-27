/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:30:43 by adelille          #+#    #+#             */
/*   Updated: 2022/08/27 17:06:24 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.hpp"
#include "graphic.hpp"
#include "keys.hpp"

bool	env::resize(void)
{
	int	key;

	attrset(A_BOLD | COLOR_PAIR(CP_RED));

	getmaxyx(stdscr, this->_win_row, this->_win_col);
	while (!graphic::valid_size(this->_win_row, this->_win_col))
	{
		clear();
		graphic::frame_resize(this->_win_row, this->_win_col);
		graphic::pmw(this->_win_row, this->_win_col, "too small");
		refresh();

		key = 0;
		while (key != KEY_RESIZE)
		{
			key = getch();
			if (keys::is_exit(key))
				return (false);
		}

		getmaxyx(stdscr, this->_win_row, this->_win_col);
	}

	attrset(A_NORMAL);

	return (true);
}