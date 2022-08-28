/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rocket.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 09:44:57 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 11:24:19 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity/rocket.hpp"
#include "graphic.hpp"

rocket::rocket(const int row, const int col): entity(row, col, 1, 4, 2, "!", CP_ROCKET, false, true)
{}

rocket::~rocket()
{}

void	rocket::process(env &e)
{
	if (e.get_tick() % this->_speed == 0)
		this->set_row(this->get_row() + 1);
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
