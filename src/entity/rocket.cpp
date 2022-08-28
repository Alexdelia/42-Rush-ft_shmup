/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rocket.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 09:44:57 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 15:55:16 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity/rocket.hpp"
#include "graphic.hpp"

rocket::rocket(const int row, const int col, const int dir):
	entity(row, col, 1, 2, 2, "|", CP_ROCKET, false, true, 1, 10)
{
	_dir = dir;
	if (dir == -1)
		this->_sprite = "/";
	else if (dir == 1)
		this->_sprite = "\\";
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
	if (_action_counter >= _action) {
		this->_color_pair = CP_SCORE;
		this->_action_counter = 0;
	}
	else
	{
		this->_color_pair = CP_ROCKET;
		this->_action_counter++;
	}
}
