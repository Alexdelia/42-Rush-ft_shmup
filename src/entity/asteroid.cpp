/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asteroid.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 09:44:52 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 09:44:53 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity/asteroid.hpp"

asteroid::asteroid(const size_t col): entity(0, col, 0, 2, 0, "*", 0)
{}

asteroid::~asteroid()
{}

void	asteroid::process(env &e)
{
	if (e.get_tick() % this->_speed == 0)
		this->set_row(this->get_row() + 1);
}
