/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaceship.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 09:45:02 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 11:19:39 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity/spaceship.hpp"

spaceship::spaceship(const size_t col): entity(0, col, 2, 6, 240, "$", 0, true, true)
{}

spaceship::~spaceship()
{}

void	spaceship::process(env &e)
{
	if (e.get_tick() % this->_speed == 0)
		this->set_row(this->get_row() + 1);
	if (_action_counter >= _action) {
		e.add_entity(new rocket(this->_row + 1, this->_col));
		this->_action_counter = 0;
	}
	else
		this->_action_counter++;
}
