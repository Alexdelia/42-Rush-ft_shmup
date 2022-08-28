/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ally_rocket.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 09:44:49 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 10:07:39 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity/ally_rocket.hpp"
#include "graphic.hpp"

ally_rocket::ally_rocket(const int row, const int col): entity(row, col, 1, 1, 0, "'", CP_PLAYER)
{}

ally_rocket::~ally_rocket()
{}

void	ally_rocket::process(env &e)
{
	if (e.get_tick() % this->_speed == 0)
		this->set_row(this->get_row() - 1);
}
