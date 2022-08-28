/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asteroid.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 09:44:52 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 15:40:17 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity/asteroid.hpp"

asteroid::asteroid(const size_t col):
	entity(0, col, 0, 2, 0, "✦", 0, false, true, 1, 90)
{}

asteroid::~asteroid()
{}

void	asteroid::process(env &e)
{
	if (e.get_tick() % this->_speed == 0)
		this->_row++;
	if (e.get_tick() % 4 == 0)
	{
		if ((int)(e.get_tick() / 100) % 4 == 1)
			this->_col--;
		else if ((int)(e.get_tick() / 100) % 4 == 3)
			this->_col++;
	}
}
