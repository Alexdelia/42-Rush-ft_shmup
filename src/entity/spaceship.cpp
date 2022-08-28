/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaceship.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 09:45:02 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 10:37:06 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity/spaceship.hpp"

spaceship::spaceship(const size_t col): entity(0, col, 2, 6, 3, "$", 0)
{}

spaceship::~spaceship()
{}

void	spaceship::process(env &e)
{
	this->_action_counter++;
	if (e.get_tick() % this->_speed == 0)
		this->set_row(this->get_row() + 1);
	if (_action_counter == _action) {
		e.add_entity(new rocket(this->_row, this->_col));
		this->_action_counter = 0;
	}
}
