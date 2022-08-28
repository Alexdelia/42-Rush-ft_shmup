/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rocket.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 09:44:57 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 10:39:46 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity/rocket.hpp"

rocket::rocket(const int row, const int col, const int dir): entity(row, col, 1, 4, 0, "!", 0)
{
	_dir = dir;
}

rocket::~rocket()
{}

void	rocket::process(env &e)
{
	if (e.get_tick() % this->_speed == 0)
	{
		this->_row++;
		this->_col += this->_dir;
	}
}
