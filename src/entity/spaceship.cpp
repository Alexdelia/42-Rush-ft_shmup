/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaceship.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 09:45:02 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 16:40:25 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity/spaceship.hpp"
#include "graphic.hpp"

spaceship::spaceship(const size_t col):
	entity(0, col, 2, 6, 240, "🜉", CP_RED, true, true, 10, 100)
{}

spaceship::~spaceship()
{}

void	spaceship::process(env &e)
{
	if (e.get_tick() % this->_speed == 0)
		this->_row++;
	if (_action_counter >= _action) {
		e.add_entity(new rocket(this->_row + 1, this->_col, 0));
		this->_action_counter = 0;
	}
	else
		this->_action_counter++;
}
