/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boss.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 09:44:52 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 19:39:42 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity/boss.hpp"
#include "graphic.hpp"

boss::boss(const int col):
	entity(0, col, 0, 30, 0, "x", CP_RED, true, true, 1, 100)
{}

boss::~boss()
{}

void	boss::process(env &e)
{
	if (e.get_tick() % this->_speed == 0 && this->_row < 10)
		this->_row++;
	if (e.get_tick() % 30 == 0)
	{
		if ((int)(e.get_tick() / 600) % 4 == 1)
			this->_col--;
		else if ((int)(e.get_tick() / 600) % 4 == 3)
			this->_col++;
	}
}
