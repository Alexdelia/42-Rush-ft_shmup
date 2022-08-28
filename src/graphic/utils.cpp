/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:12:49 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 21:44:28 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.hpp"

void	graphic::pmw(const int row, const int col, const std::string &str)
{
	mvaddstr(row / 2, (col - str.size()) / 2, str.c_str());
}

bool	graphic::valid_size(const int row, const int col)
{
	return (row >= MIN_WIN_ROW && col >= MIN_WIN_COL);
}

void	graphic::frame_resize(const int row, const int col)
{
	mvprintw(0, 0, "⌜");
	mvprintw(0, col - 1, "⌝");
	mvprintw(row - 1, 0, "⌞");
	mvprintw(row - 1, col - 1, "⌟");
}

size_t	graphic::ft_stlen(size_t n)
{
	size_t	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}
